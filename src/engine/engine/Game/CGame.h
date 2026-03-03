#pragma once
#include "..\GameScript\GSObject.h"

namespace Net
{
    namespace Repl
    {
        class IGame
        {
        };
    }

    namespace Msg
    {
        class IMsgClient
        {
        };
    }
}

class ILobbyCallback{
};
class IScriptManager{
};

typedef IScriptManager* (__cdecl* GSInitFn)();
typedef void (__cdecl* GSShutdownFunc)();

class __declspec(align(4)) CGame : CGSObject, Net::Repl::IGame, Net::Msg::IMsgClient, ILobbyCallback
{
  //void CGame::InitializeGameScript(GSInitFn pszGameScriptDLL,GSShutdownFunc *param_2)


  IGame *m_IGame;
  /*
  CThreadContextData<CGame::SRenderData,2,1,1,0> m_RenderData;
  CThreadContextData<CGame::SStandaloneData,0,0,1,0> m_StandaloneData;
  CThreadContextData<CGame::SFrameData,1,0,1,0> m_FrameData;
  bool m_ResetCWD;
  CGameEditor *m_pGameEditor;
  bool m_EditorCompilingMap;
  HINSTANCE__ *m_hGameInstance;
  HWND__ *m_hWnd;
  bool m_bWindowReopening;
  CAudioSettings *m_pAudioSettings;
  ttl::string_base<char> m_OverrideProfileName;
  bool m_ResetSteamProfile;
  ttl::string_base<char> m_VideoSettingsFileName;
  ttl::string_base<char> m_AudioSettingsFileName;
  CResourceDataPack *m_pEngineDataPack;
  CResourceDataPack *m_pEngineTestDataPack;
  CCountersSystem *m_CountersSystem;
  HICON__ *m_Icon;
  float m_fBaseFOV;
  float m_CameraAspect;
  bool m_FixedWideAspect;
  int m_nArgCount;
  const char *m_aArg[128];
  char m_szLocaleID[16];
  char m_szRegionID[16];
  bool m_bExclusiveLocale;
  bool m_bSafeMode;
  bool m_bLowMoviesQuality;
  bool m_bDedicatedServer;
  ttl::string_base<wchar_t> m_szWindowName;
  ttl::string_base<char> m_GameExeCoreName;
  bool m_bNetworkCablePlugged;
  char szGamePath[260];
  CLevel *m_pASELevel;
  CLevel *m_pGameSpyLevel;
  Net::CLocalClient *m_LocalClient;
  Net::Repl::CReplicatorsManager *m_ReplicatorsManager;
  Net::Msg::CMessenger *m_Messenger;
  Performance::CSystemProfiler *m_SystemProfiler;
  ttl::vectorm<22,CLevel *> m_PendingLevelsForShow;
  CLevel *m_pActiveLevel;
  EInputRecording::TYPE m_InputRecordingType;
  bool m_bForceEndRecordingInputs;
  bool m_bForceEndPlayingInputs;
  ttl::string_base<char> m_szFileRecordFile;
  int m_nConstantGrain;
  __int64 m_nTimeCounterStart;
  unsigned int m_FramesCounter;
  unsigned int m_dwOnPainThread;
  bool m_bEnableRendering;
  HWND__ *m_RenderTaskHWND;
  const tagRECT *m_RenderTaskSrcRect;
  const tagRECT *m_RenderTaskDestRect;
  unsigned int m_RenderTaskFlags;
  bool m_bLevelTimersFrozen;
  bool m_bActualizeTimers;
  CTimersState *m_pTimersState;
  unsigned int m_dwRunMode;
  unsigned int m_dwTimeout;
  CSimpleSystemTimer m_TimoutTimer;
  bool m_bNonInteractiveSequence;
  bool m_bTimeoutPassed;
  bool m_bDontCheckTimeout;
  int m_bProcessGame;
  float m_fDefaulModuleStartTime;
  CLevel *m_pLoadedLevel;
  CGSObject2IntMap m_OwnerIDMap;
  char szCurrentlyLoadingLevel[255];
  CLevel *m_pCurrentlyLoadingLevel;
  bool m_bLevelLoading;
  bool m_bSelectionLoading;
  bool m_bGIELoading;
  char m_szGameIni[255];
  char *m_GameDirectoryName;
  volatile ENetErrorTypes::TYPE m_NetErrorType;
  ttl::string_base<char> m_NetErrorMessage;
  volatile bool m_CallSignInChange;
  volatile bool m_NetworkCableUnpluggedEncounter;
  bool m_bAllowMultipleInstances;
  bool m_bBenchmarkMode;
  bool m_AutoEnableFramePipelineing;
  bool m_ChangeFramePipeliningTo;
  ttl::list<CRTTIVoidFunctor<IGSObject>,ttl::allocator> m_EndFrameHandlers;
  CExpressionVariableManager m_ExpressionVariableManager;
  CSaveManager m_SaveManager;
  CTagSystem m_TagSystem;
  unsigned int m_MemPreallocSize;
  CResourceLoadingRuntime m_ResourceLoadingRuntime;
  ttl::string_base<char> AlertText;
  ChromeSpy::IDataCollector *m_ChromeSpy;
  bool m_SynchronizingFrameRender;
  */
};
