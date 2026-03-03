#pragma once
#include <Windows.h>
#include "Game\Factory.h"
#include "Game\CGame.h"
#include "Game\IGame.h"
#include "resource.h"

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

HINSTANCE g_hDllModule;

//splash screen
HBITMAP l_Bitmap;
HWND l_Splash;

//Export, returns engine version
int ENGINE_API GetEngineDllVersion();

void ENGINE_API __cdecl ShowSplashscreen(HINSTANCE hInstance, LPCSTR bitmap_res, UINT app_title_res, HICON icon);