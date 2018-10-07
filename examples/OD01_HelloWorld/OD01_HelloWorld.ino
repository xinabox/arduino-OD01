/*************************************************************
	This is an examples for the OD01 0.96 inch OLED Display
	
	You can buy one on our store!
	-----> https://xinabox.cc/modules/displays/OD01/
	
	This example display a basic Hello World text on the 
	OLED display.
	
	The display communicates over the I2C Bus.

*************************************************************/

#include "xCore.h"
#include "Arduino_OD01.h"

xOD01 OD01;

const int DELAY_TIME = 2000;

void setup() {
  // Starts the I2C communication
#ifdef ESP8266
	Wire.pins(2, 14);
#endif
  Wire.begin();
  
  // Start the OLED Display OD01
  OD01.begin();

  // set display tex to double size
  OD01.set2X();
  
  // Sends a command to the OD01 to print a text string
  OD01.print("OD01 TEST");

  // Small delay
  delay(DELAY_TIME);
  
  // Sends a command to the OD01 to clear the display
  OD01.clear();

}

void loop() {
  // set display tex to double size
  OD01.set2X();
    
  // Sends a command to the OD01 to print a text string on a singe line
  OD01.println("Hello");

  // set display tex to normal size
  OD01.set1X();
  
  // Sends a command to the OD01 to print a text string  
  OD01.print("World");

  // Small delay
  delay(DELAY_TIME);
  
  // Sends a command to the OD01 to clear the display  
  OD01.clear();
}
