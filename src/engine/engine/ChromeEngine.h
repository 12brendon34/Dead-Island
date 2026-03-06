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
extern "C" ENGINE_API int GetEngineDllVersion();
extern "C" ENGINE_API void __cdecl ShowSplashscreen(HINSTANCE hInstance, LPCSTR bitmap_res, UINT app_title_res, HICON icon);

/*
0000F78C	0000F78C	0855	?Initialize@IGame@@QAEHPADHPAUHICON__@@KK@Z
0000F714	0000F714	1023	GetEngineDllVersion
0000F72A	0000F72A	102D	ShowSplashscreen
0000F73E	0000F73E	1028	InitializeGameScript
0000F756	0000F756	0BE5	?RunTest@Repl@Net@@YAXXZ
0000F7BA	0000F7BA	102F	UninitializeGameScript
0000F7D4	0000F7D4	1026	HideSplashscreen
0000F7E8	0000F7E8	1020	CreateGame
0000F772	0000F772	0A4C	?OnPaint@IGame@@QAEXXZ
0000F7F6	0000F7F6	1022	DestroyGame
*/