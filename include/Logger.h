#ifndef LOGGER_H
    #define LOGGER_H

    #include <Arduino.h>
    #include <FS.h>
    #include <SPIFFS.h>

    bool LOG_TO_SERIAL = true;
    bool LOG_TO_FILE = false;

    bool initFS();
    bool logger(String stuff);
    String clearCurrentLogFile();
    void printLogPaths();
    bool initLogger(bool debug);

#endif