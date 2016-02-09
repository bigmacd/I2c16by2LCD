#ifndef __a16by2_h__
#include __a16by2_h__
#endif

#include <LCD.h>
#include <LiquidCrystal_I2C.h>

I2c16by2::I2c16by2(LiquidCrystal_I2C* lcd)
         :mLcd(lcd)
{

    mLastBLState = LOW;
    mBacklightState = HIGH;

    mMessage1 = "";
    mMessage2 = "";

	lcd.begin(16, 2);
	lcd.home();

	// Switch on the backlight
	lcd.setBacklightPin(mBacklightButtonPin, POSITIVE);
	lcd.setBacklight(HIGH);

	clearDisplay();
}

I2c16by2::~I2c16by2()  {
}


void
I2c16by2::displayMessageOnLine1(String messagein)  {
    updateMessage(messagein, LCD_LINE_2);
}


void
I2c16by2::displayMessageOnLine2(String messagein)  {
    updateMessage(messagein, LCD_LINE_2);
}

void
I2c16by2::displayMessage(String messagein) {

}


void
I2c16by2::updateMessage(String messagein, int lineNumber) {

  if (LCD_LINE_1 == lineNumber)
     mMessage1 = messagein;
  else
     mMessage2 = messagein;

  if (mBacklightState == LOW) return;
  
  int padChars = 16 - messagein.length();
  for (int x = 0; x < padChars; x++)
    if (LCD_LINE_1 == lineNumber)
      mMessage1 += ' ';
    else
      mMessage2 += ' ';
   
  if (LCD_LINE_1 == lineNumber)
    lcd.home();
  else
    lcd.setCursor(0, 1);

  delay(50);
  lcd.print(mMessage1);
}

void
I2c16by2::clearDisplay() {
  char* message = "                ";
  lcd.home();
  delay(50);
  lcd.print(message);
  lcd.setCursor(0, 1);
  delay(50);
  lcd.print(message);
  delay(50);
}

int
I2c16by2::backlightState() {
    return mBacklightState;
}

void 
I2c16by2::backlightToggle() {

  mBacklightState = (mBacklightState == HIGH?LOW:HIGH);
  lcd.setBacklight(mBacklightState);
  if (mBacklightState == LOW)
    clearDisplay();
  else {
    displayMessage1(mMessage1);
    displayMessage2(mMessage2);
   }
}
