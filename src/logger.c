#include <stdio.h>
#include "logger.h"


/**
 * log_message - Write a log message to stderr with a level prefix.
 * @level: LogLevel enum indicating severity (LOG_INFO, LOG_WARN, LOG_ERROR, LOG_DEBUG)
 * @msg: The log message to print
 *
 * The function prints a level-specific prefix (e.g. "[INFO] ") followed by the
 * formatted message and a trailing newline to stderr. It uses vfprintf to
 * handle the variadic arguments safely.
 */
void log_message(LogLevel level, const char *msg) {
    const char *prefix;
    
    switch (level) {
        case LOG_INFO:  prefix = "[INFO] "; break;
        case LOG_WARN:  prefix = "[WARN] "; break;
        case LOG_ERROR: prefix = "[ERROR]"; break;
        case LOG_DEBUG: prefix = "[DEBUG]"; break;
        default:        prefix = "[LOG]  "; break;
    }

    fprintf(stderr, "%s%s\n", prefix, msg);
}
