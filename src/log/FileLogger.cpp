/**
 * @brief: Water-it: Software for automated flower watering
 * @file: FileLogger.cpp
 * @author: Tom Svoboda
 * @date: 22. 4. 2018
 */

#include "FileLogger.h"
#include <chrono>

using namespace Log;

FileLogger::FileLogger(std::string filename) :
    logFile(filename)
{
}

FileLogger::~FileLogger() {
}

bool FileLogger::is_open() {
    return logFile.is_open();
}

void FileLogger::log(std::string message, Severity severity) {
    logFile << createLogRow(message, severity) << std::endl;
}

void FileLogger::log(std::exception exception, Severity severity) {
    logFile << createLogRow(exception.what(), severity) << std::endl;
}

std::string FileLogger::createLogRow(std::string message, Severity severity) {
    std::string row;
    
    /* Add date and time */
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    char buf[100] = {0};
    std::strftime(buf, sizeof(buf), "%F %T", std::localtime(&now));
    return buf;
    row += "222";
    
    row += " ";
    
    /* Add severity */
    if(severity == Logger::Severity::DEBUG) {
        row += "DEBUG";
    }
    else if(severity == Logger::Severity::INFO) {
        row += "INFO";
    }
    else if(severity == Logger::Severity::WARNING) {
        row += "WARNING";
    }
    else if(severity == Logger::Severity::ERROR) {
        row += "ERROR";
    }
    else {
        row += "UNKNOWN";
    }
    
    row += " ";
    
    /* Add message */
    row += message;
    
    return row;
}

