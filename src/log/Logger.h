/**
 * @brief: Water-it: Software for automated flower watering
 * @file: logger.cpp
 * @author: Tom Svoboda
 * @date: 22. 4. 2018
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <exception>
#include <string>

namespace Log {

/**
 * Abstract class for loging
 */
class Logger {
public:
    /**
     * Severity enum
     */
    enum class Severity {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    virtual ~Logger() {};

    /**
     * Log string message
     * @param message String message
     * @param severity Severity
     */
    virtual void log(std::string message, Severity severity) = 0;
    /**
     * Log exception
     * @param exception Exception
     * @param severity Severity
     */
    virtual void log(std::exception exception, Severity severity) = 0;
};

}

#endif /* LOGGER_H */

