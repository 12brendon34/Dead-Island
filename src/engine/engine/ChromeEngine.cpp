#include <Windows.h>
#include "ChromeEngine.h"

int WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  g_hDllModule = hinstDLL;
  return 1;
}

int ENGINE_API GetEngineDllVersion()
{
  return 0x10001;
}
