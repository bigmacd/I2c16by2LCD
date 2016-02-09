#ifndef __a16by2_h__
#define __a16by2_h__

class LiquidCrystal_I2C;

#define LCD_LINE_1 1
#define LCD_LINE_2 2

class I2c16by2 {

  private:

    String    mMessage1;
    String    mMessage2;
    int       mBacklightState;

    void      updateMessage(String, lineNumber);

    LiquidCrystal_I2C* mLcd;

  protected:


  public:

    # create the lcd object and pass it in
    I2c16by2(LiquidCrystal_I2C* lcd);
    ~I2c16by2();

    # the backlight starts on
    void backlightToggle();

    # in case you forget, you can always ask
    int  backlightState();

    # clears the display (even if the backlight is off)
    void clearDisplay();

    # displays a message, unless the backlight is off in which case it stores until it is on.
    void displayMessageOnLine1(String);
    void displayMessageOnLine2(String);

    # takes your String and tries to fit it best it can on the two lines
    void displayMessage(String);

};

#endif
