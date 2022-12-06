#ifndef CORE_H
#define CORE_H

#include "Platform.h"

#include <PandemoniumLog.h>

#include <memory>

namespace Pandemonium {

	template <typename T> using Scope = std::unique_ptr<T>;

	template <typename T> using Ref	  = std::shared_ptr<T>;

} // namespace Pandemonium

#endif /* CORE_H */