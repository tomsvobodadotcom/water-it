/**
 * @brief: Water-it: Software for automated flower watering
 * @file: FileLogger.h
 * @author: Tom Svoboda
 * @date: 22. 4. 2018
 */

#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Logger.h"
#include <fstream>

namespace Log {

/**
 * Filelogger for logging to file
 */
class FileLogger : public Logger {
public:
    FileLogger(std::string filename);
    virtual ~FileLogger();

    /**
     * Returns boolean value if logging file is opened
     * @return bool
     */
    bool is_open();
    
    /**
     * Log string message
     * @param message String message
     * @param severity Severity
     */
    void log(std::string message, Severity severity) override;
    /**
     * Log exception
     * @param exception Exception
     * @param severity Severity
     */
    void log(std::exception exception, Severity severity) override;
    
protected:
    std::ofstream logFile;
    
    /**
     * Create row for appending to file
     * @param message Message
     * @param severity Severity
     * @return Log row
     */
    std::string createLogRow(std::string message, Severity severity);
};

}

#endif /* FILELOGGER_H */

