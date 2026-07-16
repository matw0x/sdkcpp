#pragma once

#include <expected>
#include <type_traits>

namespace sdk::result {

template <typename E>
concept ScopedEnum = std::is_scoped_enum_v<E>;

template <typename Ok, ScopedEnum Err>
using Result = std::expected<Ok, Err>;

[[nodiscard]] constexpr auto fail(ScopedEnum auto err) noexcept { return std::unexpected{err}; }

}  // namespace sdk::result
