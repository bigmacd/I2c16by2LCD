# I2c16by2LCD
A tiny little wrapper around the library for Liquid_Crystal_I2C for a 16x2 LCD

Instantiate a LiquidCrystal_I2C to be passed in to the methods of the A16by2 object.

The default state of the backlight is on.  Call backlightToggle to turn it off.

To put a message on the first line, call displayMessageOnLine1(LiquidCrystal_I2C*, String)
To put a message on the second line, call displayMessageOnLine2(LiquidCrystal_I2C*, String)

See the example sketch.

You can call clearDisplay() to "erase" the display.  When backlightToggle is called to turn the backlight
off, it will call clearDisplay().  However, A16by2 remembers your last output, so calling backlightToggle
to turn it back on will display your last messages.
