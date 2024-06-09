#include "Logger.h"

Logger::Logger() 
{
    logFile.open("error_log.txt", std::ios::app);
    if (!logFile.is_open()) 
        throw std::runtime_error("Unable to open log file");
}

Logger::~Logger() 
{
    if (logFile.is_open())
        logFile.close();
}

Logger& Logger::getInstance() 
{
    static Logger instance;
    return instance;
}

void Logger::logError(const std::string& errorMessage) 
{
    if (logFile.is_open())
        logFile << errorMessage << std::endl;
}
