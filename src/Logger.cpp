#include <logger.h>
#include <LittleFS.h>


#define DBG_OUTPUT_PORT Serial
#define VERSION 0.1
#define LOG_FILE "/log.txt"
#define CURRENT_LOG_FILE "/current_log.txt"

bool LOG_TO_SERIAL = true;
bool LOG_TO_FILE = false;
int logLevel = LOG_ALL;

bool initFS() {
  if (LittleFS.begin()) return true;
  else return false;
}

bool initLogger(bool debug) {
  return initLogger(debug, LOG_ALL);
} 

bool initLogger(bool debug, int setLogLevel) {
  LOG_TO_SERIAL = debug;
  logLevel = setLogLevel;
  return initFS();
} 

void printLogPaths(){
  if (LOG_TO_FILE) {
    DBG_OUTPUT_PORT.println("Log file: " + String(LOG_FILE));
    DBG_OUTPUT_PORT.println("Current Log file: " + String(CURRENT_LOG_FILE));
  }
  else DBG_OUTPUT_PORT.println("Logging to file is Disabled");
}

/***************************
 * Serial logging helper with appropriate dating. It could also log to files and perform some other logging tasks
 * @param data String to be logged. Current date will be added automatically
 * @return void
 ***************************/
bool logger(String data){
 if(LOG_TO_SERIAL){
    //Print data via Serial port
    DBG_OUTPUT_PORT.println(String(millis()) + "  " + data);
    
    if (LOG_TO_FILE) {
      //Open log files
      File logFile = LittleFS.open(LOG_FILE, "a");
      File currentLogFile = LittleFS.open(CURRENT_LOG_FILE, "a");
      if (!logFile || !currentLogFile) {
        DBG_OUTPUT_PORT.println("Error opening log files");
        return false;
      }

      int bytesWritten = logFile.println(String(millis()) + "  " + data);
      if (bytesWritten <= 0) {
        DBG_OUTPUT_PORT.println("Log File write failed");
        return false;
      }
      logFile.close();

      bytesWritten = currentLogFile.println(String(millis()) + "  " + data);
      if (bytesWritten <= 0) {
        DBG_OUTPUT_PORT.println("CurrentLog File write failed");
        return false;
      }
      currentLogFile.close();
      return true;
    }
    return true;
  }
  else return true;
}

/***************************
 * Serial logging helper with appropriate dating. It could also log to files and perform some other logging tasks
 * @param data String to be logged. Current date will be added automatically
 * @param logLevel 0=Debug - 4=Force Log 
 * @return void
 ***************************/
bool logger(String data, int _logLevel){
  if(logLevel >= _logLevel) return logger(data);
  else return false;
}

String clearCurrentLogFile() {
  File currentLogFile = LittleFS.open(CURRENT_LOG_FILE, "w+");
  
  if (!currentLogFile) {
    DBG_OUTPUT_PORT.println("Error opening Current Log File to clear");
    return "NULL";
  }

  int bytesWritten = currentLogFile.println("");
  if (bytesWritten <= 0) {
    DBG_OUTPUT_PORT.println("File write failed");
    return "NULL";
  }

  DBG_OUTPUT_PORT.println("Current Log File cleared");
  currentLogFile.close();
  return CURRENT_LOG_FILE;
}
