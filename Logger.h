#pragma once

#include <string>
#include <fstream>
#include <memory>

class Logger 
{
private:

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::ofstream logFile;

public:

    Logger();
    ~Logger();

    static Logger& getInstance();
    void logError(const std::string& errorMessage);


};
