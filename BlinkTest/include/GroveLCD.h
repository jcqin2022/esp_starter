#ifndef __GROVELCD__
#define __GROVELCD__

#include <Wire.h>
#include "rgb_lcd.h"
//#include <LiquidCrystal_I2C.h>
//#include <Arduino_LiquidCrystal_I2C.h>
//#include <LiquidCrystal_I2C.h>

class GroveLCD
{
public:
	void setup();
	void loop();
    void blink();
    void showmilli();

	GroveLCD();
private:
	rgb_lcd lcd;
    //LiquidCrystal_I2C lcd;
    //LiquidCrystal_I2C lcd;

    const int colorR = 213;
    const int colorG = 157;
    const int colorB = 28;
};

#endif //__GROVELCD__