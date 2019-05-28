#include <cmms/logging.hpp>
#include <spdlog/spdlog.h>

namespace cmms {

std::shared_ptr<spdlog::logger> setup_logger(const std::string& name)
{
    auto result = get(name);
    if (!result) {
        result = cmms::default_logger_raw()->clone(name);
        try {
            cmms::register_logger(result);
        } catch (const spdlog::spdlog_ex&) {
        }
    }

    return result;
}

std::shared_ptr<spdlog::logger> get(const std::string& name)
{
    return spdlog::get(name);
}

void set_formatter(std::unique_ptr<spdlog::formatter> formatter)
{
    return spdlog::set_formatter(std::move(formatter));
}

void set_pattern(std::string pattern, spdlog::pattern_time_type time_type)
{
    return spdlog::set_pattern(std::move(pattern), time_type);
}

void set_level(spdlog::level::level_enum log_level)
{
    return spdlog::set_level(log_level);
}

void flush_on(spdlog::level::level_enum log_level)
{
    return spdlog::flush_on(log_level);
}

void flush_every(std::chrono::seconds interval)
{
    return spdlog::flush_every(std::move(interval));
}

void set_error_handler(spdlog::log_err_handler handler)
{
    return spdlog::set_error_handler(std::move(handler));
}

void register_logger(std::shared_ptr<spdlog::logger> logger)
{
    return spdlog::register_logger(std::move(logger));
}

void apply_all(const std::function<void(std::shared_ptr<spdlog::logger>)>& fun)
{
    return spdlog::apply_all(fun);
}

void drop(const std::string& name)
{
    return spdlog::drop(name);
}

void drop_all()
{
    return spdlog::drop_all();
}

void shutdown()
{
    return spdlog::shutdown();
}

void set_automatic_registration(bool automatic_registation)
{
    return spdlog::set_automatic_registration(automatic_registation);
}

std::shared_ptr<spdlog::logger> default_logger()
{
    return spdlog::default_logger();
}

spdlog::logger* default_logger_raw()
{
    return spdlog::default_logger_raw();
}

void set_default_logger(std::shared_ptr<spdlog::logger> default_logger)
{
    return spdlog::set_default_logger(std::move(default_logger));
}

} // namespace cmms