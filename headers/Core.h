#ifndef CORE_H
#define CORE_H

#include <memory>

// #include "PandemoniumMath.h"
#include "PandemoniumLog.h"

// Compiler Platform Checking
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#ifdef _WIN64
		#define PANDEMONIUM_PLATFORM_WINDOWS
	#elif _WIN32
		#error 32-bit Windows not supported!
	#endif
#elif __APPLE__
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR
		// iOS, tvOS, or watchOS Simulator
		#define PANDEMONIUM_PLATFORM_IPHONE_SIMULATOR
		#error iOS, tvOS, or watchOS Simulator not supported!
	#elif TARGET_OS_MACCATALYST
		// Mac's Catalyst (ports iOS API into Mac, like UIKit).
		#define PANDEMONIUM_PLATFORM_OS_MACCATALYST
		#error Mac's Catalyst not supported!
	#elif TARGET_OS_IPHONE
		// iOS, tvOS, or watchOS device
		#define PANDEMONIUM_PLATFORM_OS_IPHONE
		#error iOS, tvOS, or watchOS not supported!
	#elif TARGET_OS_MAC
		// Other kinds of Apple platforms
		#define PANDEMONIUM_PLATFORM_OS_MAC
		#error Apple platforms not supported!
	#else
		#error "Unknown Apple platform"
	#endif
#elif __ANDROID__
	// Android
	#define PANDEMONIUM_PLATFORM_ANDROID
	#error "Android not supported"
#elif __linux__
	// Linux
	#define PANDEMONIUM_PLATFORM_LINUX
	#error "Linux not supported"
#elif __unix__ // all unices not caught above
	// Unix
	#define PANDEMONIUM_PLATFORM_UNIX
	#error "Unix not supported"
#elif defined(_POSIX_VERSION)
	// POSIX
	#define PANDEMONIUM_PLATFORM_POSIX
	#error "POSIX not supported"
#else
	#error "Unknown compiler"
#endif

#ifdef PANDEMONIUM_PLATFORM_WINDOWS
	#ifdef PANDEMONIUM_BUILD_DLL
		#define PANDEMONIUM_API __declspec(dllexport)
	#else
		#define PANDEMONIUM_API __declspec(dllimport)
	#endif
#else
	#error NO PLATFORMS DEFINED
#endif

namespace Pandemonium {

	template <typename T> using Scope = std::unique_ptr<T>;

	template <typename T> using Ref	  = std::shared_ptr<T>;

} // namespace Pandemonium

#endif /* CORE_H */