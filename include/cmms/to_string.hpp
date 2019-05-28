#ifndef COMMONS_INCLUDE_CMMS_TO_STRING_HPP_
#define COMMONS_INCLUDE_CMMS_TO_STRING_HPP_

#include <sstream>
#include <string>

namespace cmms {

template <class T>
std::string to_string(const T& obj)
{
    std::ostringstream is;
    is << obj;
    return is.str();
}

} // namespace cmms

#endif // COMMONS_INCLUDE_CMMS_TO_STRING_HPP_