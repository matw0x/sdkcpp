#pragma once

#include <concurrentqueue.h>

#include "detail/Defs.h"
#include "detail/Meta.h"

namespace sdk::router {

enum class Policy {
    sync,
    async,
};

struct BaseConfig {
    static constexpr auto policy = Policy::sync;
    static constexpr auto size   = 256u;
};

template <typename C>
concept RouterConfig = std::is_base_of_v<BaseConfig, C> and requires(const C &config) { typename C::Routes; };

template <typename Event, typename WhatDo>
struct Route final {
    using Trigger   = Event;
    using Processor = WhatDo;
};

template <typename... Rs>
struct Routes final {
    using AsTuple              = std::tuple<Rs...>;
    static constexpr auto size = sizeof...(Rs);
};

template <RouterConfig Config>
class Router final {
   public:
    template <typename Event>
    API auto send(const Event &event) {}

   private:
    using Placeholder = uint32_t;
    moodycamel::ConcurrentQueue<Placeholder> events;  // maybe make QueueType like template?
};

}  // namespace sdk::router
