#pragma once

#include <iostream>
#include <string>
namespace celogin
{
enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};
template <typename OutputStream>
class Logger
{
  public:
    Logger(LogLevel level, OutputStream& outputStream) :
        currentLogLevel(level), output(outputStream)
    {}
    template <typename T, typename... Rest>
    void print(const T& message, const Rest&... rest) const
    {
        output << message << " ";
        print(rest...);
    }
    void print() const
    {
        output << std::endl;
    }
    template <typename... Args>
    void log(const char* filename, int lineNumber, LogLevel level,
             const Args&... message) const
    {
        if (isLogLevelEnabled(level))
        {
            output << filename << ":" << lineNumber << " ";
            print(message...);
        }
    }

    void setLogLevel(LogLevel level)
    {
        currentLogLevel = level;
    }

  private:
    LogLevel currentLogLevel;
    OutputStream& output;

    bool isLogLevelEnabled(LogLevel level) const
    {
        return level >= currentLogLevel;
    }
};

inline Logger<std::ostream>& getLogger()
{
    static Logger<std::ostream> logger(LogLevel::DEBUG, std::cout);
    return logger;
}
} // namespace celogin

// Macros for clients to use logger
#define CE_LOG_DEBUG(message, ...)                                             \
    celogin::getLogger().log(__FILE__, __LINE__, celogin::LogLevel::DEBUG,     \
                             "Debug :", message, ##__VA_ARGS__)
#define CE_LOG_INFO(message, ...)                                              \
    celogin::getLogger().log(__FILE__, __LINE__, celogin::LogLevel::INFO,      \
                             "Info :", message, ##__VA_ARGS__)
#define CE_LOG_WARNING(message, ...)                                           \
    celogin::getLogger().log(__FILE__, __LINE__, celogin::LogLevel::WARNING,   \
                             "Warning :", message, ##__VA_ARGS__)
#define CE_LOG_ERROR(message, ...)                                             \
    celogin::getLogger().log(__FILE__, __LINE__, celogin::LogLevel::ERROR,     \
                             "Error :", message, ##__VA_ARGS__)
