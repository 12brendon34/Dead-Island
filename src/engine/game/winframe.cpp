#include <windows.h>
#include <cstring>
#include <cstdio>
#include "..\engine\ChromeEngine.h"
#include "..\kernel\ttl\string.h"

typedef HRESULT (WINAPI *SHGETFOLDERPATH)(HWND, int, HANDLE, DWORD, LPSTR);

// FUNCTION: DEADISLANDGAME 0x00401000
SHGETFOLDERPATH LocateAndLoadGetFolderPath()
{
    OSVERSIONINFOEXA os;
    memset(&os, 0, sizeof(os));
    os.dwOSVersionInfoSize = sizeof(os);

    if (!GetVersionExA((LPOSVERSIONINFOA)&os))
        return NULL;

    HMODULE hModule;
    if (os.dwMajorVersion >= 5)
        hModule = GetModuleHandleA("shell32.dll");
    else
        hModule = LoadLibraryA("SHFolder.dll");// Fallback for Win9x/early 2000

    if (!hModule)
        return NULL;

    return (SHGETFOLDERPATH)GetProcAddress(hModule, "SHGetFolderPathA");
}

char aCommandLine[1024];
int nArgCount;
char *aArg[64];

// FUNCTION: DEADISLANDGAME 0x00401070
void ReadCmdLine(char *lpCL, HMODULE hInstance)
{
    GetModuleFileNameA(hInstance, aCommandLine, 256);
    nArgCount = 1;
    aArg[0] = aCommandLine;

    char *dst = aCommandLine + lstrlenA(aCommandLine) + 1;
    char *src = lpCL;

    while (*src)
    {
        while (*src == ' ' || *src == '\t')
            src++;
        if (!*src)
			break;

        aArg[nArgCount++] = dst;

        while (*src && *src != ' ' && *src != '\t')
            *dst++ = *src++;

        *dst++ = '\0';
    }
}

// FUNCTION: DEADISLANDGAME 0x00401100
bool CheckFreeDiskSpaceAndDisplayWarning(LPCSTR drive_path){
	CreateDirectoryA(drive_path, 0);

	ULARGE_INTEGER bytes_available;
	if (!GetDiskFreeSpaceExA(drive_path, &bytes_available, NULL, NULL))
        return false;

    if ((bytes_available.QuadPart / (1024 * 1024)) < 200)
    {
        return false;
    }

	DWORD dwCaption = 1024;
	DWORD dwText = 1024;
	char caption[1024] = {0};
	char text[1024] = {0};

	HKEY hKey;
	if ( !RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Techland\\DeadIsland", 0, 1u, &hKey) )
	{
		RegQueryValueExA(hKey, "FreeDiskSpaceWarningCaption", 0, 0, (LPBYTE)caption, &dwCaption);
		RegQueryValueExA(hKey, "FreeDiskSpaceWarningText", 0, 0, (LPBYTE)text, &dwText);
		RegCloseKey(hKey);
	}

	if (!caption[0])
		strcpy_s(caption, 1024, "Free disk space warning");

	if (!text[0])
		strcpy_s(text, 1024, "You have insufficient disk space on drive %s\nPlease free up %d MB of disk space and run this game again.");

	char text2[1024];
	sprintf_s(text2, text);

	return MessageBoxA(NULL, text2, caption, MB_ICONWARNING || MB_OKCANCEL) != 1;
}

#ifndef DEFAULT_ERROR_CAPTION
#define DEFAULT_ERROR_CAPTION	"Error"
#endif
#ifndef ALREADY_RUNNING_MESSAGE
#define ALREADY_RUNNING_MESSAGE	"Application is already running"
#endif
#ifndef REGISTRY_KEY
#define REGISTRY_KEY	"SOFTWARE\\Techland\\Game"
#endif
#ifndef ENGINE_MUTEX_NAME
#define ENGINE_MUTEX_NAME	"Global\\ChromeEngineMutex"
#endif

// FUNCTION: DEADISLANDGAME 0x00401290
bool CheckMultipleInstances(PSTR command_line){
	HANDLE MutexA = CreateMutexA(0, 1, "Global\\ChromeEngine4DIMutex");
	HKEY__ *hKey;

	// allow multi instance
	if (strstr(command_line, "-ami"))
		return 1;

	DWORD LastError = GetLastError();
	if ( MutexA ){
		if (LastError != ERROR_ALREADY_EXISTS)
			return 1;
	}
	else if ( LastError != ERROR_ACCESS_DENIED )
	{
		return 1;
	}

	DWORD dwCaption = MAX_PATH;
	DWORD dwText = MAX_PATH;
	char caption[MAX_PATH] = {0};
	char text[MAX_PATH] = {0};

	if (!RegOpenKeyExA(HKEY_LOCAL_MACHINE, REGISTRY_KEY, 0, KEY_QUERY_VALUE, &hKey)){
		RegQueryValueExA(hKey, "AlreadyRunningCaption", 0, 0, (LPBYTE)caption, &dwCaption);
		RegQueryValueExA(hKey, "AlreadyRunningText", 0, 0, (LPBYTE)text, &dwText);
		RegCloseKey(hKey);
	}
	if ( !caption[0] )
		strcpy_s(caption, MAX_PATH, DEFAULT_ERROR_CAPTION);
	
	if ( !text[0] )
		strcpy_s(text, MAX_PATH, ALREADY_RUNNING_MESSAGE);
	
	MessageBoxA(0, text, caption, MAX_PATH);
	return 0;
}

// FUNCTION: DEADISLANDGAME 0x004013D0
int WINAPI WinMain(HINSTANCE hWinInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow){
	tagMSG stMsg;
	memset(&stMsg, 0, sizeof(stMsg));
	
	//Check engine version
	if (GetEngineDllVersion() != 0x10001){
		//exit failure
		MessageBoxA(0, "Invalid engine dll version!","Error...", MB_ICONSTOP);
		return 0;
	}
	                                      
	if (!CheckMultipleInstances(lpCmdLine)) {
		return 0;
	}
	
	char drive;
	char dir[MAX_PATH]; 
	char szExeDir[MAX_PATH];

	GetModuleFileNameA(0, szExeDir, MAX_PATH);
	_splitpath(szExeDir, (char *)&drive, dir, 0, 0);
	strcpy_s(szExeDir, MAX_PATH, (const char *)&drive);
	strcat_s(szExeDir, MAX_PATH, dir);

	char szCurrDir[MAX_PATH];
	if (strstr(lpCmdLine, "--wd"))
	{
		GetCurrentDirectoryA(MAX_PATH, szCurrDir);
		strcat_s(szCurrDir, MAX_PATH, "\\");
	}
	else
	{
		strcpy_s(szCurrDir, MAX_PATH, szExeDir);
	}

	ttl::string_base<char> str(lpCmdLine);
	unsigned int pos = str.find("-game_dir=");
	if (pos != -1)
	{
		const char *buf;
		if (str.m_Buffer)
			buf = str.m_Buffer;
		else
			buf = "";

		ttl::string_base<char> str2(buf + pos + 10);
		unsigned int space = str2.find(" ");
		if (space != -1)
			str2.resize(space);

		const char *out;
		if (str2.m_Buffer)
			out = str2.m_Buffer;
		else
			out = "";

		strcpy_s(szCurrDir, MAX_PATH, out);
		free(str2.m_Buffer);
	}

	HANDLE game_icon = LoadImageA(hWinInstance, (LPCSTR)0xA1, 1u, 0, 0, 0);


	MessageBoxA(NULL, DEFAULT_ERROR_CAPTION, DEFAULT_ERROR_CAPTION, MB_ICONWARNING || MB_OKCANCEL);



	ReadCmdLine(lpCmdLine, hWinInstance);
	LocateAndLoadGetFolderPath();

	//fs::init(acStack_6fc,local_954,"out/cache",false,true);
	if (!CheckFreeDiskSpaceAndDisplayWarning(lpCmdLine)) {
		//free(pvStack_91c);
		return 0;
	}

	return 0;
}