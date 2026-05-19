#pragma once

#include <concurrentqueue.h>

#include "detail/Defs.h"
#include "detail/Meta.h"

namespace sdk {

struct SyncPolicy;

struct AsyncPolicy;

template <typename P>
concept SyncRouterPolicy = std::is_same_v<P, SyncPolicy>;

template <typename P>
concept AsyncRouterPolicy = std::is_same_v<P, AsyncPolicy>;

template <typename P>
concept RouterPolicy = detail::IsAnyOf<P, SyncPolicy, AsyncPolicy>;

template <RouterPolicy Policy>
class Router final {
   public:
    API auto route() {}

   private:
    using Placeholder = uint32_t;
    moodycamel::ConcurrentQueue<Placeholder> events;
};

}  // namespace sdk