// ARDUINO API methods.
#ifndef __ESP_API__
#define __ESP_API__
#include <cstdio>
#include <thread>
#include <chrono>
typedef unsigned char      uint8_t;

inline void pinMode(uint8_t pin, uint8_t mode)
{
	std::printf("pinMode: %d, %d\n", pin, mode);
}
inline void digitalWrite(uint8_t pin, uint8_t val)
{
	std::printf("pinMode: %d, %d\n", pin, val);
}
inline void delay(unsigned long millisec)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
}

#endif // __ESP_API__

