#ifndef LOGGER_H
    #define LOGGER_H

    #include <Arduino.h>
    #include <FS.h>
    //#include <SPIFFS.h>

    #define LOG_ALL             4
    #define LOG_WARNING         3
    #define LOG_ERROR           2
    #define LOG_CRITICAL_ERROR  1
    #define LOG_NOTHING         0

    extern bool LOG_TO_SERIAL;
    extern bool LOG_TO_FILE;


    bool initFS();
    bool logger(String stuff);
    bool logger(String stuff, int logLevel);
    String clearCurrentLogFile();
    void printLogPaths();
    bool initLogger(bool debug);
    bool initLogger(bool debug, int setLogLevel);

#endif