#pragma once

#include <iostream>
#include <fstream>

class Logger {
 public:
  virtual void Log(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
 public:
  void Log(const std::string& message) override {
    std::cout << message << std::endl;
  }
};

class FileLogger : public Logger {
 public:
  FileLogger(const std::string& filename) {
    _file.open(filename);
  }

  void Log(const std::string& message) override {
    _file << message << std::endl;
  }

 private:
  std::ofstream _file;
};
