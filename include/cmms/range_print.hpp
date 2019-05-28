#ifndef COMMONS_INCLUDE_CMMS_RANGE_PRINT_HPP_
#define COMMONS_INCLUDE_CMMS_RANGE_PRINT_HPP_

#include <iostream>
#include <iterator>
#include <ostream>
#include <type_traits>

namespace cmms {

namespace detail {
    template <class T>
    struct sfinae_true : std::true_type {
    };

    template <class T>
    static auto test_iterable(int) -> std::conjunction<
        sfinae_true<decltype(std::begin(std::declval<T>()))>,
        sfinae_true<decltype(std::end(std::declval<T>()))>>;
    template <class T>
    static auto test_iterable(long) -> std::false_type;
}

template <class T>
struct is_iterable : decltype(detail::test_iterable<T>(0)) {
};
template <class T>
inline constexpr bool is_iterable_v = is_iterable<T>::value;

template <class InputIt>
struct RangePrint {
    RangePrint(InputIt first, InputIt last)
        : first_(first)
        , last_(last)
    {
    }

    InputIt first() const
    {
        return first_;
    }

    InputIt last() const
    {
        return last_;
    }

private:
    InputIt first_;
    InputIt last_;
};

template <class T>
auto range_print(const T& container)
{
    return RangePrint(std::begin(container), std::end(container));
}

template <class InputIt>
std::ostream& operator<<(std::ostream& os, const RangePrint<InputIt>& obj)
{
    bool flag = false;

    os << "[";
    for (auto i = obj.first(); i != obj.last(); ++i) {
        if (flag) {
            os << ", ";
        } else {
            flag = true;
        }

        os << *i;
    }
    os << "]";

    return os;
}

template <class T, class = std::enable_if_t<is_iterable_v<T>>>
std::ostream& operator<<(std::ostream& os, const T& obj)
{
    bool flag = false;
    auto i = obj.begin();
    auto last = obj.end();

    os << "[";
    for (; i != last; ++i) {
        if (flag) {
            os << ", ";
        } else {
            flag = true;
        }

        os << *i;
    }
    os << "]";

    return os;
}
}

#endif // COMMONS_INCLUDE_CMMS_RANGE_PRINT_HPP_