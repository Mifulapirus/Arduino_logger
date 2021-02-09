#ifndef LOGGER_H
    #define LOGGER_H

    #include <Arduino.h>
    #include <FS.h>
    #include <SPIFFS.h>

    extern bool LOG_TO_SERIAL;
    extern bool LOG_TO_FILE;

    bool initFS();
    bool logger(String stuff);
    String clearCurrentLogFile();
    void printLogPaths();
    bool initLogger(bool debug);

#endif