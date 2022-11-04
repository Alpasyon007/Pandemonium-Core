// #include "PandemoniumMath.h"
// #include "PandemoniumLog.h"

#ifdef PANDEMONIUM_PLATFORM_WINDOWS
	#ifdef PANDEMONIUM_BUILD_DLL
		#define PANDEMONIUM_API __declspec(dllexport)
	#else
		#define PANDEMONIUM_API __declspec(dllimport)
	#endif
#else
	#error NO PLATFORMS DEFINED
#endif