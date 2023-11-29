// unittest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <conio.h>
#include "BlinkTest.h"

#include "util.h"
#include "trace.h"

/// <summary>
/// Global variables here
/// </summary>
HWSerial Serial;
Trace EspTrace;

/// <summary>
/// Global methods here
/// </summary>
void setup();
void loop();
void unblock_loop();

int main()
{
    std::cout << "====press q to quit!\n";
	setup();
	//loop();
    unblock_loop();
}

BlinkTest blinkTest;

void setup() {
	blinkTest.setup();
}

void loop() {
	int ch;
	while (true)
	{
		printf("loop\r\n");
		if ((ch=getchar()) != '\n')
			break;
	}
}

void unblock_loop() {
    char input;
    int count = 0;
    while (true) {
        // 检查是否有按键按下
        if (_kbhit()) {
            // 读取按下的键
            input = _getch();
            std::cout << "You pressed: " << input << std::endl;
            if (input == 'q') break;
        }

        // 其他非阻塞任务可以放在这里
        blinkTest.loop();
        // print time and looping info
        const size_t size = 20;
        char timestr[size];
        now(timestr, size);
        std::cout << "====" << timestr << "-looping: " << count++ << std::endl;
        // 引入延迟以避免高 CPU 使用率
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}