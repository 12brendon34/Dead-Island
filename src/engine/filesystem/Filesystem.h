#pragma once
#include <Windows.h>

#ifdef FILESYSTEM_EXPORTS
#define FILESYSTEM_API __declspec(dllexport)
#else
#define FILESYSTEM_API __declspec(dllimport)
#endif

namespace fs {

    // Put the FILESYSTEM_API macro before the return type.
    FILESYSTEM_API bool __cdecl is_read_membuffer_enabled();
    FILESYSTEM_API void __cdecl enable_read_membuffer(bool enable);

    FILESYSTEM_API void __cdecl RemoveTrailingSlashes(char* buffer, const char* path);
    FILESYSTEM_API void __cdecl BuildCombinedDirectory();
    FILESYSTEM_API char* __cdecl get_cache_dir();

	// use_fs_cache is unused, probably stripped
    FILESYSTEM_API bool __cdecl init(const char* write_path, int write_path_flags, const char* cache_dir, bool fallback, bool use_fs_cache);

} // namespace fs