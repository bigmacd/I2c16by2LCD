#ifndef __a16by2_h__
#define __a16by2_h__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define LCD_LINE_1 1
#define LCD_LINE_2 2

class A16by2 {

  private:

    String    mMessage1;
    String    mMessage2;
    int       mBacklightState;
    void      updateMessage(LiquidCrystal_I2C* lcd, String message, int lineNumber);
	
	LiquidCrystal_I2C* mLcd;

  protected:


  public:

    A16by2();
    ~A16by2();
	
	void begin(LiquidCrystal_I2C* lcd);

    // the backlight starts ON
    void backlightToggle(LiquidCrystal_I2C* lcd);

    // in case you forget, you can always ask
    int  backlightState();

    // clears the display (even if the backlight is off)
	// still holds onto the previous messages, however.
    void clearDisplay(LiquidCrystal_I2C*);

    // displays a message, unless the backlight is off in which case it stores until it is on.
    void displayMessageOnLine1(LiquidCrystal_I2C*, String);
    void displayMessageOnLine2(LiquidCrystal_I2C*, String);

    // takes your String and tries to fit it best it can on the two lines
    void displayMessage(LiquidCrystal_I2C*, String);
	

};

#endif
