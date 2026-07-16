#pragma once

namespace sdk::pinned {

struct Pinned {
    Pinned()  = default;
    ~Pinned() = default;

    Pinned(const Pinned&)            = delete;
    Pinned& operator=(const Pinned&) = delete;
    Pinned(Pinned&&)                 = delete;
    Pinned& operator=(Pinned&&)      = delete;
};

}  // namespace sdk::pinned
