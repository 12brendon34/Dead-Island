#include <windows.h>
#include <cstring>
#include "..\engine\ChromeEngine.h"
#include "..\kernel\ttl\string.h"

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

	if (!RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Techland\\DeadIsland", 0, KEY_QUERY_VALUE, &hKey)){
		RegQueryValueExA(hKey, "AlreadyRunningCaption", 0, 0, (LPBYTE)caption, &dwCaption);
		RegQueryValueExA(hKey, "AlreadyRunningText", 0, 0, (LPBYTE)text, &dwText);
		RegCloseKey(hKey);
	}
	if ( !caption[0] )
		strcpy_s(caption, MAX_PATH, "Dead Island Error");
	
	if ( !text[0] )
		strcpy_s(text, MAX_PATH, "Dead Island is already running");
	
	MessageBoxA(0, text, caption, MAX_PATH);
	return 0;
}

// FUNCTION: DEADISLANDGAME 0x004013D0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow){
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

	/*
	if (str.find("-game_dir=") != -1) {
	
	}
	*/
	return 0;
}