#pragma once

#include <utility>

#include "detail/Defs.h"
#include "detail/Meta.h"

namespace sdk::locator {

template <typename... Ts>
using Pack = detail::Pack<Ts...>;

template <typename ServicePack, typename Context = struct NoContext>
struct Locator;

template <typename... Services, typename Context>
struct Locator<Pack<Services...>, Context> {
    struct Hub : Context, Services... {
        template <typename... Args>
        explicit Hub(Args&&... args) : Context{std::forward<Args>(args)...} {}
    };

   protected:
    template <typename Service>
    SDK_API auto& get(this auto& self) noexcept {
        auto& hub     = static_cast<Hub&>(self);
        auto& service = static_cast<Service&>(hub);

        return service;
    }

    template <typename Service>
    SDK_API const auto& get(this const auto& self) noexcept {
        const auto& hub     = static_cast<const Hub&>(self);
        const auto& service = static_cast<const Service&>(hub);

        return service;
    }
};

}  // namespace sdk::locator
