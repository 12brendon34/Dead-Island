#include "ChromeEngine.h"

//line 42
// FUNCTION: ENGINE_X86_RWDI 0x10008860
int WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  g_hDllModule = hinstDLL;
  return 1;
}

// FUNCTION: ENGINE_X86_RWDI 0x10008880
void __cdecl InitializeGameScriptFn(GSInitFn initFn, GSShutdownFunc shutdownFn)
{
    //CGame::InitializeGameScript(initFn, shutdownFn);
}




// FUNCTION: ENGINE_X86_RWDI 0x100088A0
void InitializeGameScript(HINSTANCE hInstance, const char* gameScriptDll, bool fastDIAInit)
{
    //CGame::InitializeGameScript(hInstance, gameScriptDll, fastDIAInit);
}




//IGame* __cdecl CreateGame(CGSObject* pszClassName, HINSTANCE  hInstance, bool bPlaceHolder, CGame* gameDirName){}


void __cdecl WaitForRenderingThreads(void)
{
}

//CFactory *DestroyGame(){}


//IEngine* Initalize, zamn


//~176
// FUNCTION: ENGINE_X86_RWDI 0x10008b00
int ENGINE_API GetEngineDllVersion()
{
  return 0x10001;
}

void __cdecl SetPlatform(const char *platform_name)
{
  //CGameEditor::SetUiManagerMode(platform_name);
}

// FUNCTION: ENGINE_X86_RWDI 0x10008b20
BOOL CALLBACK GoToProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return uMsg == WM_INITDIALOG;
}

//line ~200
// FUNCTION: ENGINE_X86_RWDI 0x10008b30
void __cdecl ShowSplashscreen(HINSTANCE hInstance, LPCSTR bitmap_res, UINT app_title_res, HICON icon)
{
    char app_title[128];
    app_title[0] = 0;

    LoadStringA(hInstance, app_title_res, app_title, 128);

    l_Bitmap = (HBITMAP)LoadImageA(hInstance, bitmap_res, IMAGE_BITMAP, 0, 0, 0);
    if (!l_Bitmap)
        return;

    HWND hDlg = CreateDialogParamA((HINSTANCE)g_hDllModule, MAKEINTRESOURCEA(IDD_DIALOG1), NULL, GoToProc, 0);
    l_Splash = hDlg;
    if (!hDlg)
        return;

    SendDlgItemMessageA(hDlg, 1002, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)l_Bitmap);

    if (app_title[0])
        SetWindowTextA(l_Splash, app_title);

    SetClassLongA(l_Splash, GCL_HICON, (LONG)icon);

    tagBITMAP bmp;
    GetObjectA(l_Bitmap, sizeof(tagBITMAP), &bmp);

    HWND hBitmapCtrl = GetDlgItem(l_Splash, 1002);
    if (hBitmapCtrl)
        SetWindowPos(hBitmapCtrl, NULL, 0, 0, bmp.bmWidth, bmp.bmHeight, SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOMOVE);

    int x = (GetSystemMetrics(SM_CXSCREEN) - bmp.bmWidth) / 2;
    int y = (GetSystemMetrics(SM_CYSCREEN) - bmp.bmHeight) / 2;

    SetWindowPos(l_Splash, NULL, x, y, bmp.bmWidth, bmp.bmHeight, SWP_NOZORDER | SWP_NOACTIVATE);

    UpdateWindow(l_Splash);
}