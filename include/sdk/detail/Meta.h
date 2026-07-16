#pragma once

#include <type_traits>

namespace sdk::detail {

template <typename... T>
struct Pack {};

template <typename A, typename B>
constexpr auto equality = std::is_same_v<A, B>;

template <typename T, typename... Ts>
concept IsAnyOf = (equality<T, Ts> || ...);

}  // namespace sdk::detail
