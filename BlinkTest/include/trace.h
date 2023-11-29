// Trace info here.
#ifndef __TRACE__
#define __TRACE__

#include "Arduino.h"
#include "util.h"
#include <memory>

class Trace {

public:
    inline Trace() {
    };
    inline void begin(unsigned long baud)
    {
        Serial.begin(baud);
    }
    inline void printf(const char* format, ...) {
        va_list arg;
        va_start(arg, format);
        memset(msg, 0, sizeof(msg));
        size_t len = now(msg, sizeof(msg));
        msg[len++] = ' ';
        vsnprintf(msg + len, sizeof(msg) - len + 1, format, arg);
        Serial.print(msg);
        va_end(arg);
    }
private:
    char msg[128];
};

extern Trace EspTrace;
#endif // !__TRACE__
