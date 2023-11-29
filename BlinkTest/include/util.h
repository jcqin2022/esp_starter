// utilities.
#ifndef __UTIL__
#define __UTIL__

#include <stdio.h>
#include <time.h>

inline size_t now(char* str, size_t len)
{
    time_t currentTime = time(NULL);
    if (currentTime == -1) return -1;
    // 将时间戳转换为本地时间
    struct tm* localTime = localtime(&currentTime);
    // 20 characters are enough for "YYYY-MM-DD HH:MM:SS"
    return strftime(str, len, "%Y-%m-%d %H:%M:%S", localTime);
}

#endif // !__UTIL__
