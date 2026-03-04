#include "Filesystem.h"

// FUNCTION: FILESYSTEM_X86_RWDI 0x10002e30
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  if (fdwReason == DLL_PROCESS_ATTACH)
    DisableThreadLibraryCalls(hinstDLL);
  return 1;
}

bool use_read_membuffer = false;
bool __cdecl fs::is_read_membuffer_enabled()
{
  return use_read_membuffer;
}

//go back and grab the argument name from ida
/*void __cdecl fs::enable_read_membuffer(bool param_1)
{
  use_read_membuffer = param_1;
  return;
}
*/