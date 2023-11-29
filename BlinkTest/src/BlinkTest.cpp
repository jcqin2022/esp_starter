#include "BlinkTest.h"
#include "Arduino.h"
#include "esp8266_def.h"
#include "trace.h"

BlinkTest::BlinkTest():count(0) {

}

void BlinkTest::setup() {
    EspTrace.printf("ESP8266 BlinkTest Setup now.\n");
    // put your setup code here, to run once:
    pinMode(LED_PIN_1, OUTPUT);
}

void BlinkTest::loop() {
    // put your main code here, to run repeatedly:
    printLoopTimes();

    blink_success();
    delay(1000);
    blink_inprogress();
    delay(1000);
    blink_warning();
    delay(1000);
    blink_error();
    delay(1000);
}

void BlinkTest::printLoopTimes() {
    int display = count % 10;
    if (display == 0)
    {
        EspTrace.printf("BlinkTest loop: %d steps\n", count);
    }
    count++;
}

void BlinkTest::blink_error()
{
    EspTrace.printf("blink - error: %d\n", LED_PIN_1);
    for(int i = 0; i< 5; i++)
    {
        digitalWrite(LED_PIN_1, LOW);
        delay(20);
        digitalWrite(LED_PIN_1, HIGH);
        delay(380);
    }
}
void BlinkTest::blink_warning()
{
    EspTrace.printf("blink - warning: %d\n", LED_PIN_1);
    for(int i = 0; i< 5; i++)
    {
        digitalWrite(LED_PIN_1, LOW);
        delay(100);
        digitalWrite(LED_PIN_1, HIGH);
        delay(300);
    }
}
void BlinkTest::blink_success()
{
    EspTrace.printf("blink - success: %d\n", LED_PIN_1);
    for(int i = 0; i< 5; i++)
    {
        digitalWrite(LED_PIN_1, LOW);
        delay(390);
        digitalWrite(LED_PIN_1, HIGH);
        delay(10);
    }
}
void BlinkTest::blink_inprogress()
{
    EspTrace.printf("blink - in progress: %d\n", LED_PIN_1);
    for(int i = 0; i< 5; i++)
    {
        digitalWrite(LED_PIN_1, LOW);
        delay(200);
        digitalWrite(LED_PIN_1, HIGH);
        delay(200);
    }
}