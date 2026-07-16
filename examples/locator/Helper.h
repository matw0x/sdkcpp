#pragma once

#include <type_traits>

namespace myProject {

template <typename A, typename B>
constexpr auto equality = std::is_same_v<A, B>;

}
