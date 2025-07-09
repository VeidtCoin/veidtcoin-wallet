#include "logger.h"
#include <iostream>

namespace Logger {

void info(const std::string& msg) {
    std::cout << "[INFO] " << msg << std::endl;
}

void warn(const std::string& msg) {
    std::cout << "[WARN] " << msg << std::endl;
}

void error(const std::string& msg) {
    std::cerr << "[ERROR] " << msg << std::endl;
}

void divider() {
    std::cout << "----------------------------------------" << std::endl;
}

}
