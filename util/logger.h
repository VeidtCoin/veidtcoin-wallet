#ifndef VEIDTCOIN_LOGGER_H
#define VEIDTCOIN_LOGGER_H

#include <string>

namespace Logger {
    void info(const std::string& msg);
    void warn(const std::string& msg);
    void error(const std::string& msg);
    void divider();
}

#endif
