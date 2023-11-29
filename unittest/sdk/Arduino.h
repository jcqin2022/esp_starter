// ARDUINO API methods.
#ifndef __ARDUINO__
#define __ARDUINO__
#include <cstdio>
#include <stdarg.h>
#include "esp_api.h"
#include "esp_def.h"

class HWSerial {
public:
	inline HWSerial() {}
	inline void begin(unsigned long baud) {
		std::printf("Serial.begin(): %d\n", baud);
	};
	inline void print(const char* str) {
		std::printf("Serial.print(): %s\n", str);
	};
	inline void printf(const char* format, ...) {
		va_list arg;
		va_start(arg, format);
		std::vprintf(format, arg);
		va_end(arg);
	};
};

extern HWSerial Serial;

#endif // __ARDUINO__

