#ifndef __a16by2_h__
#include "a16by2.h"
#endif

A16by2::A16by2()
{
  mBacklightState = HIGH;
  mMessage1 = "";
  mMessage2 = "";
}

A16by2::~A16by2()  {
}

void
A16by2::begin(LiquidCrystal_I2C* lcd) {
  lcd->begin(16, 2);
  lcd->setBacklight(mBacklightState);
  lcd->home();
}

void
A16by2::displayMessageOnLine1(LiquidCrystal_I2C* lcd, String messagein)  {
    updateMessage(lcd, messagein, LCD_LINE_1);
}

void
A16by2::displayMessageOnLine2(LiquidCrystal_I2C* lcd, String messagein)  {
    updateMessage(lcd, messagein, LCD_LINE_2);
}

void
A16by2::displayMessage(LiquidCrystal_I2C* lcd, String messagein) {
  // not implemented, yet.
}


void
A16by2::updateMessage(LiquidCrystal_I2C* lcd, String messagein, int lineNumber) {

  if (LCD_LINE_1 == lineNumber)
    mMessage1 = messagein;
  else
    mMessage2 = messagein;

  if (mBacklightState == LOW) return;
  
  int padChars = 16 - messagein.length();
  String message = "";
  for (int x = 0; x < padChars; x++)
    if (LCD_LINE_1 == lineNumber) {
      mMessage1 += ' ';
	  message = mMessage1;
	}
    else   {
      mMessage2 += ' ';
	  message = mMessage2;
    }

  if (LCD_LINE_1 == lineNumber)
    lcd->home();
  else
    lcd->setCursor(0, 1);

  delay(50);
  lcd->print(message);
}

void
A16by2::clearDisplay(LiquidCrystal_I2C* lcd) {
  char* message = "                ";
  lcd->home();
  delay(50);
  lcd->print(message);
  lcd->setCursor(0, 1);
  delay(50);
  lcd->print(message);
  delay(50);
}

int
A16by2::backlightState() {
    return mBacklightState;
}

void 
A16by2::backlightToggle(LiquidCrystal_I2C* lcd) {

  mBacklightState = (mBacklightState == HIGH?LOW:HIGH);
  lcd->setBacklight(mBacklightState);
  if (mBacklightState == LOW)
    clearDisplay(lcd);
  else {
    displayMessageOnLine1(lcd, mMessage1);
    displayMessageOnLine2(lcd, mMessage2);
  }
}
