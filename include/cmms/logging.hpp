#ifndef COMMONS_INCLUDE_CMMS_LOGGING_HPP_
#define COMMONS_INCLUDE_CMMS_LOGGING_HPP_

#include "exports.hpp"

#include <spdlog/logger.h>

#include <chrono>
#include <memory>
#include <vector>

namespace cmms {

using Logger = std::shared_ptr<spdlog::logger>;
using LoggerRef = spdlog::logger*;

CMMS_EXPORT std::shared_ptr<spdlog::logger>
setup_logger(const std::string& name);

CMMS_EXPORT std::shared_ptr<spdlog::logger> get(const std::string& name);
CMMS_EXPORT void set_formatter(std::unique_ptr<spdlog::formatter> formatter);
CMMS_EXPORT void set_pattern(std::string pattern,
                             spdlog::pattern_time_type time_type
                             = spdlog::pattern_time_type::local);
CMMS_EXPORT void set_level(spdlog::level::level_enum log_level);
CMMS_EXPORT void flush_on(spdlog::level::level_enum log_level);
CMMS_EXPORT void flush_every(std::chrono::seconds interval);
CMMS_EXPORT void set_error_handler(spdlog::log_err_handler handler);
CMMS_EXPORT void register_logger(std::shared_ptr<spdlog::logger> logger);
CMMS_EXPORT void
apply_all(const std::function<void(std::shared_ptr<spdlog::logger>)>& fun);
CMMS_EXPORT void drop(const std::string& name);
CMMS_EXPORT void drop_all();
CMMS_EXPORT void shutdown();
CMMS_EXPORT void set_automatic_registration(bool automatic_registation);

CMMS_EXPORT std::shared_ptr<spdlog::logger> default_logger();
CMMS_EXPORT spdlog::logger* default_logger_raw();
CMMS_EXPORT void
set_default_logger(std::shared_ptr<spdlog::logger> default_logger);

template <typename... Args>
inline void log(spdlog::source_loc source, spdlog::level::level_enum lvl,
                const char* fmt, const Args&... args)
{
    default_logger_raw()->log(source, lvl, fmt, args...);
}

template <typename... Args>
inline void log(spdlog::level::level_enum lvl, const char* fmt,
                const Args&... args)
{
    default_logger_raw()->log(source_loc {}, lvl, fmt, args...);
}

template <typename... Args>
inline void trace(const char* fmt, const Args&... args)
{
    default_logger_raw()->trace(fmt, args...);
}

template <typename... Args>
inline void debug(const char* fmt, const Args&... args)
{
    default_logger_raw()->debug(fmt, args...);
}

template <typename... Args>
inline void info(const char* fmt, const Args&... args)
{
    default_logger_raw()->info(fmt, args...);
}

template <typename... Args>
inline void warn(const char* fmt, const Args&... args)
{
    default_logger_raw()->warn(fmt, args...);
}

template <typename... Args>
inline void error(const char* fmt, const Args&... args)
{
    default_logger_raw()->error(fmt, args...);
}

template <typename... Args>
inline void critical(const char* fmt, const Args&... args)
{
    default_logger_raw()->critical(fmt, args...);
}

template <typename T>
inline void log(spdlog::level::level_enum lvl, const T& msg)
{
    default_logger_raw()->log(lvl, msg);
}

template <typename T>
inline void trace(const T& msg)
{
    default_logger_raw()->trace(msg);
}

template <typename T>
inline void debug(const T& msg)
{
    default_logger_raw()->debug(msg);
}

template <typename T>
inline void info(const T& msg)
{
    default_logger_raw()->info(msg);
}

template <typename T>
inline void warn(const T& msg)
{
    default_logger_raw()->warn(msg);
}

template <typename T>
inline void error(const T& msg)
{
    default_logger_raw()->error(msg);
}

template <typename T>
inline void critical(const T& msg)
{
    default_logger_raw()->critical(msg);
}

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
template <typename... Args>
inline void log(level::level_enum lvl, const wchar_t* fmt, const Args&... args)
{
    default_logger_raw()->log(lvl, fmt, args...);
}

template <typename... Args>
inline void trace(const wchar_t* fmt, const Args&... args)
{
    default_logger_raw()->trace(fmt, args...);
}

template <typename... Args>
inline void debug(const wchar_t* fmt, const Args&... args)
{
    default_logger_raw()->debug(fmt, args...);
}

template <typename... Args>
inline void info(const wchar_t* fmt, const Args&... args)
{
    default_logger_raw()->info(fmt, args...);
}

template <typename... Args>
inline void warn(const wchar_t* fmt, const Args&... args)
{
    default_logger_raw()->warn(fmt, args...);
}

template <typename... Args>
inline void error(const wchar_t* fmt, const Args&... args)
{
    default_logger_raw()->error(fmt, args...);
}

template <typename... Args>
inline void critical(const wchar_t* fmt, const Args&... args)
{
    default_logger_raw()->critical(fmt, args...);
}

#endif // SPDLOG_WCHAR_TO_UTF8_SUPPORT

} // namespace cmms

#endif // COMMONS_INCLUDE_CMMS_LOGGING_HPP_