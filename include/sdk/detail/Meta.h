#include <concepts>

namespace sdk::detail {

template <typename T, typename... Ts>
concept IsAnyOf = (std::is_same_v<T, Ts> || ...);

}  // namespace sdk::detail