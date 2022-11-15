#ifndef CORE_H
#define CORE_H

#include <memory>

// #include "PandemoniumMath.h"
#include "PandemoniumLog.h"

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