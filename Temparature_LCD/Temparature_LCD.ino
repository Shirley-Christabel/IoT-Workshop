#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	
}

void loop()
{
	// Do nothing here...
   int temp = analogRead(A0);
  float volt = temp*(0.0048828125);
  float milivolt = volt*1000;
  float degree = milivolt/10;
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Temp : ");
  lcd.setCursor(2,1);
  lcd.print(degree);
  delay(100);
}
