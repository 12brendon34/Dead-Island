//I made these up, there's probably some other stuff, but this makes sence at least
#include "resource.h"
#define SPLASH_ICON IDI_ICON1
#define SPLASH_DIALOG IDB_SPLASH
#define SPLASH_TITLE IDS_TITLE

#define DEFAULT_ERROR_CAPTION       "Dead Island Error"
#define ALREADY_RUNNING_MESSAGE     "Dead Island is already running"
#define REGISTRY_KEY                "SOFTWARE\\Techland\\DeadIsland"
#define ENGINE_MUTEX_NAME           "Global\\ChromeEngine4DIMutex"

#include "..\..\engine\game\winframe.cpp"