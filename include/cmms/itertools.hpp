#ifndef COMMONS_INCLUDE_CMMS_ITERTOOLS_HPP_
#define COMMONS_INCLUDE_CMMS_ITERTOOLS_HPP_

#include <iterator>
#include <utility>

namespace cmms {

template <class T, class Iterator = decltype(std::begin(std::declval<T>()))>
std::pair<Iterator, Iterator> iterpair(T& container) noexcept
{
    return std::make_pair(std::begin(container), std::end(container));
}

template <class T>
void cycle_forward(T& containter)
{
    auto first = std::begin(containter);
    auto last = std::end(containter);

    auto save = *first;
    for (auto i = std::next(first); i != std::end(containter); ++i) {
        auto tmp = *i;
        *i = save;
        save = tmp;
    }
    *first = save;
}
}

#endif // COMMONS_INCLUDE_CMMS_ITERTOOLS_HPP_x