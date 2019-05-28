#ifndef COMMONS_INCLUDE_CMMS_CYCLER_HPP_
#define COMMONS_INCLUDE_CMMS_CYCLER_HPP_

#include <iterator>
#include <utility>

namespace cmms {

template <class BidirIt>
class Cycler {
    static constexpr auto npos = size_t(-1);

public:
    Cycler(BidirIt first, BidirIt last) noexcept
        : first_(std::move(first))
        , last_(std::move(std::prev(last)))
    {
    }

    bool is_first(const BidirIt& it) const
    {
        return it == first_;
    }

    bool is_last(const BidirIt& it) const
    {
        return it == last_;
    }

    BidirIt next(BidirIt it, size_t n = 1) const
    {
        while (n-- != npos) {
            it = !is_last(it) ? std::next(it) : first_;
        }
        return it;
    }

    BidirIt prev(BidirIt it, size_t n = 1) const
    {
        while (n-- != npos) {
            it = !is_first(it) ? std::prev(it) : last_;
        }
        return it;
    }

private:
    BidirIt first_;
    BidirIt last_;
};

template <class T>
auto make_cycler(T& container)
{
    return Cycler(std::begin(container), std::end(container));
}

} // namespace cmms

#endif // COMMONS_INCLUDE_CMMS_CYCLER_HPP_