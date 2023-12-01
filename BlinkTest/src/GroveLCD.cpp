#include "GroveLCD.h"
#include "trace.h"

//LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define BACKLIGHT_PIN     13

//LiquidCrystal_I2C lcd(0x38);  // Set the LCD I2C address

//LiquidCrystal_I2C lcd(0x38, BACKLIGHT_PIN, POSITIVE);  // Set the LCD I2C address


// Creat a set of new characters
const uint8_t charBitmap[][8] = {
   { 0xc, 0x12, 0x12, 0xc, 0, 0, 0, 0 },
   { 0x6, 0x9, 0x9, 0x6, 0, 0, 0, 0 },
   { 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0, 0x0 },
   { 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0, 0x0 },
   { 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0x0 },
   { 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0x0 },
   { 0x0, 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0 },
   { 0x0, 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0x0 }
   
};

GroveLCD::GroveLCD()//:lcd(0x27) //lcd(0x27,16,2)
{

}

void GroveLCD::setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    size_t ret = lcd.print("hello, world!");
    EspTrace.printf("GroveLCD::setup() - lcd print result: %d\n", ret);

    delay(1000);
    // initialize the LCD
	//lcd.begin();

	// Turn on the blacklight and print a message.
    //lcd.display();
    /* lcd.home();
	lcd.backlight();
	lcd.print("Hello, world!"); */

    /* int charBitmapSize = (sizeof(charBitmap ) / sizeof (charBitmap[0]));

    // Switch on the backlight
    pinMode ( BACKLIGHT_PIN, OUTPUT );
    digitalWrite ( BACKLIGHT_PIN, HIGH );
    
    lcd.begin(16,2);               // initialize the lcd 

    for ( int i = 0; i < charBitmapSize; i++ )
    {
        lcd.createChar ( i, (uint8_t *)charBitmap[i] );
    }

    lcd.home ();                   // go home
    lcd.print("Hello, ARDUINO ");  
    lcd.setCursor ( 0, 1 );        // go to the next line
    lcd.print (" FORUM - fm   ");
    delay ( 1000 ); */

}
void GroveLCD::loop()
{
    //blink();
    showmilli();
   // Do a little animation by writing to the same location
   /* for ( int i = 0; i < 2; i++ )
   {
      for ( int j = 0; j < 16; j++ )
      {
         lcd.print (char(random(7)));
      }
      lcd.setCursor ( 0, 1 );
   }
   delay (200); */
}

void GroveLCD::showmilli()
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    size_t ret = lcd.print(millis()/1000);
    //EspTrace.printf("GroveLCD::loop() - lcd print result: %d\n", ret);

    delay(100);
}

void GroveLCD::blink()
{
    // Turn off the blinking cursor:
    lcd.noBlink();
    delay(3000);
    // Turn on the blinking cursor:
    lcd.blink();
    delay(3000);
}