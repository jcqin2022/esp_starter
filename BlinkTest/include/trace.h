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
    inline size_t printf(const char* format, ...) {
        va_list arg;
        va_start(arg, format);
        memset(msg, 0, sizeof(msg));
        size_t len = now(msg, sizeof(msg));
        msg[len++] = ' ';
        vsnprintf(msg + len, sizeof(msg) - len + 1, format, arg);
        size_t ret = Serial.print(msg);
        va_end(arg);
        return ret;
    }
    inline size_t println(const char c[])
    {
        return Serial.println(c);
    }
    size_t println(int num, int base) 
    {
            return Serial.println(num, base);
    }
    inline size_t print(const char c[])
    {
        return Serial.print(c);
    }
    inline size_t print(int n, int base)
    {
        return Serial.print(n, base);
    }
private:
    char msg[128];
};

extern Trace EspTrace;
#endif // !__TRACE__
