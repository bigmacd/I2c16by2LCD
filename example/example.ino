//
// This is code I found myself inserting into sketches over and over.  This makes it a little
// easier as it is now a library.  Emphasis on a little.
//
// I tend to run my sketches for days, and I don't want the LCD on the whole time, so I have a button
// on (in this example) pin 12;  So when I am done for the evening, I just press the button
// and turn the LCD off.  The messages, including any updates, continues, however.
//
// This examples simply updates the message on the first line of the display with a count.
//

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <a16by2.h>

#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

long msgCount = 0;
int backlightButtonState = HIGH;

long messageWriteMillis;
long buttonPressMillis;
long messageWriteLoop = 5000;
long buttonPressLoop = 250;

LiquidCrystal_I2C	tlcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
A16by2 lcd;

void setup()
{
  pinMode(12, INPUT);
  tlcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.begin(&tlcd);
  messageWriteMillis = buttonPressMillis = millis();
}

void loop()
{
  long startMillis = millis();
  if ((startMillis - messageWriteMillis) > messageWriteLoop) {
    messageWrite();
    messageWriteMillis = startMillis;
  }
  
  if ((startMillis - buttonPressMillis) > buttonPressLoop) {
    backlightPress();
    buttonPressMillis = startMillis;
  }
}

void backlightPress() {
  int currentState = digitalRead(12);
  if (currentState == HIGH && currentState != backlightButtonState)
    lcd.backlightToggle(&tlcd);  
  backlightButtonState = currentState;  
}

void messageWrite() {
  String message = "Loop Count: ";
  message += x++;
  lcd.displayMessageOnLine1(&tlcd, message);
}
