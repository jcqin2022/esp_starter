#include <Arduino.h>
#include "BlinkTest.h"
#include "trace.h"
#include "GroveLCD.h"
#include "device.h"

/// <summary>
/// Global variables here
/// </summary>
Trace EspTrace;
BlinkTest test;
GroveLCD myLCD;
Device device;

/// <summary>
/// Global methods here
/// </summary>
void setup() {
  EspTrace.begin(9600);
  EspTrace.printf("== Execute global setup()\n");
  test.setup();
  myLCD.setup();
  device.setup();
}

void loop() {
  test.loop();
  myLCD.loop();
  device.loop();
}