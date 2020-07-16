#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include <FS.h>

bool initFS();
bool logger(String stuff);
String clearCurrentLogFile();
void printLogPaths();

#endif