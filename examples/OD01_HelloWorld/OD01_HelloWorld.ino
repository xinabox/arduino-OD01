/*************************************************************
	This is an examples for the OD01 0.96 inch OLED Display
	
	You can buy one on our store!
	-----> https://xinabox.cc/modules/displays/OD01/
	
	This example display a basic Hello World text on the 
	OLED display.
	
	The display communicates over the I2C Bus.

  Currently Supported on the following ☒CHIP:
  - CW01
  - CC01
  - CR01
  
  The sensor communicates over the I2C Bus.

  ------------------------TIPS--------------------------
  Change this line ----->Wire.begin(2,14);
  to this ----->Wire.begin();
  to allow this sensor to communicate with CC01 and CR01
	
*************************************************************/

#include "xCore.h"
#include "xOD01.h"

const int DELAY_TIME = 2000;

void setup() {
  // Starts the I2C communication
  Wire.begin(2,14);
  
  // Start the OLED Display OD01
  OLED.begin();

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
