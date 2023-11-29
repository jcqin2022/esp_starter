#include <Arduino.h>
#include "BlinkTest.h"
#include "trace.h"
/// <summary>
/// Global variables here
/// </summary>
Trace EspTrace;
BlinkTest test;

/// <summary>
/// Global methods here
/// </summary>
void setup() {
  EspTrace.begin(9600);
  EspTrace.printf("== Execute global setup()\n");
  test.setup();
  
  
}

void loop() {
  test.loop();
}