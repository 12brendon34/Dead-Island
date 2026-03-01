#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

HINSTANCE g_hDllModule;

//Export, returns engine version
int ENGINE_API GetEngineDllVersion();