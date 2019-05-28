#ifndef COMMONS_INCLUDE_CMMS_CARTESIAN_HPP_
#define COMMONS_INCLUDE_CMMS_CARTESIAN_HPP_

#include <vector>

namespace cmms {

namespace details {
    template <class T>
    struct FreezeIt {
        using Iter = typename std::vector<T>::const_iterator;

        Iter first;
        Iter last;
        Iter pos;
    };
}

template <class T>
[[nodiscard]] std::vector<std::vector<T>>
cartesian(const std::vector<std::vector<T>>& in) {
    std::vector<std::vector<T>> result;
    std::vector<details::FreezeIt<T>> vd;

    auto s = in.size();
    vd.reserve(s);
    result.reserve(s);

    for (auto& x : in) {
        auto f = std::begin(x);
        auto l = std::end(x);
        vd.push_back({f, l, f});
    }

    while (true) {
        std::vector<T> cur;
        for (auto& x : vd) {
            cur.emplace_back(*x.pos);
        }
        result.emplace_back(std::move(cur));

        auto dlast = std::end(vd);
        for (auto it = std::begin(vd);;) {
            ++(it->pos);
            if (it->pos == it->last) {
                if (std::next(it) == dlast) {
                    goto end;
                } else {
                    it->pos = it->first;
                    ++it;
                }
            } else {
                break;
            }
        }
    }

end:
    return std::move(result);
}
}

#endif // COMMONS_INCLUDE_CMMS_CARTESIAN_HPP_