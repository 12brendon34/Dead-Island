#include "Filesystem.h"



// FUNCTION: FILESYSTEM_X86_RWDI 0x10002e30
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  if (fdwReason == DLL_PROCESS_ATTACH)
    DisableThreadLibraryCalls(hinstDLL);
  return 1;
}

namespace fs
{
	bool use_read_membuffer;
	// FUNCTION: FILESYSTEM_X86_RWDI 0x10002E50
	bool __cdecl is_read_membuffer_enabled()
	{
	  return use_read_membuffer;
	}

	// FUNCTION: FILESYSTEM_X86_RWDI 0x10002E60
	void __cdecl enable_read_membuffer(bool enable)
	{
	  use_read_membuffer = enable;
	}

	// FUNCTION: FILESYSTEM_X86_RWDI 0x10002E70
	void RemoveTrailingSlashes(char buffer, const char *path){
	}

	// FUNCTION: FILESYSTEM_X86_RWDI 0x10002EE0
	void __cdecl BuildCombinedDirectory(){
	}

    char m_CacheDir[MAX_PATH];

	// FUNCTION: FILESYSTEM_X86_RWDI 0x10002F50
    char* __cdecl get_cache_dir()
    {
        return m_CacheDir;
    }
	// FUNCTION: FILESYSTEM_X86_RWDI 0x10002F60
	bool __cdecl init(const char *write_path, int write_path_flags, const char *cache_dir, bool fallback, bool use_fs_cache){
		return true;
	}
}

