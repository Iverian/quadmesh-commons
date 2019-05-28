#ifndef COMMONS_INCLUDE_CMMS_DEBUG_HPP_
#define COMMONS_INCLUDE_CMMS_DEBUG_HPP_

#include <fmt/ostream.h>

#include <iostream>
#include <stdexcept>

#ifdef NDEBUG
#define COMMONS_NDEBUG_FLAG true
#else // NDEBUG
#define COMMONS_NDEBUG_FLAG false
#endif // NDEBUG

#define cerrd                                                                 \
    if (COMMONS_NDEBUG_FLAG) {                                                \
    } else                                                                    \
        std::cerr

#define coutd                                                                 \
    if (COMMONS_NDEBUG_FLAG) {                                                \
    } else                                                                    \
        std::cout

#define throw_fmt(fmt_string, ...)                                            \
    do {                                                                      \
        auto what = fmt::format("({}:{}) " fmt_string, __FILE__, __LINE__,    \
                                ##__VA_ARGS__);                               \
        throw std::runtime_error(what);                                       \
    } while (0)

#define check_if(condition, fmt_string, ...)                                  \
    do {                                                                      \
        if (!bool(condition)) {                                               \
            throw_fmt(fmt_string, ##__VA_ARGS__);                             \
        }                                                                     \
    } while (0)

#ifdef NDEBUG

#define debug_fmt(stream, fmt_string, ...)
#define check_ifd(condition, fmt_string, ...)

#else // NDEBUG

#define debug_fmt(stream, fmt_string, ...)                                    \
    do {                                                                      \
        fmt::print((stream), fmt_string "\n", ##__VA_ARGS__);                 \
    } while (0)

#define check_ifd(condition, fmt_string, ...)                                 \
    check_if(condition, fmt_string, ##__VA_ARGS__)

#endif // NDEBUG

#endif // COMMONS_INCLUDE_CMMS_DEBUG_HPP_
