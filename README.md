# I2c16by2LCD
A tiny little wrapper around the library for i2c 16x2 LCD

Instantiate a LiquidCrystal_I2C and I2c16by2, then had the lcd object to I2c16by2.

The default state of the backlight is on.  Call backlightToggle to turn it off.

To put a message on the first line, call displayMessageOnLine1()
To put a message on the second line, call displayMessageOnLine2()

You can call clearDisplay() to "erase" the display.  When backlightToggle is called to turn the backlight
off, it will call clearDisplay().  However, I2c16by2 remembers your last output, so calling backlightToggle
to turn it back on will display your last messages.
