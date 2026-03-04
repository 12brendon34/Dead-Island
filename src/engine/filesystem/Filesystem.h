#pragma once
#include <Windows.h>

#ifdef FILESYSTEM_EXPORTS
#define FILESYSTEM_API __declspec(dllexport)
#else
#define FILESYSTEM_API __declspec(dllimport)
#endif

namespace fs {
	bool FILESYSTEM_API __cdecl fs::is_read_membuffer_enabled(void);
	bool FILESYSTEM_API __cdecl init(char *param_1,int param_2,char *param_3,bool param_4,bool param_5);
};