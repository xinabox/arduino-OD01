/*************************************************************
	This is an examples for the OD01 0.96 inch OLED Display
	
	You can buy one on our store!
	-----> https://xinabox.cc/modules/displays/OD01/
	
	This example display a basic Hello World text on the 
	OLED display.
	
	The display communicates over the I2C Bus.
	
	
*************************************************************/

#include "XiX_OD01.h"

void setup() {
  OD01.begin();
  OD01.println("Hello World");
}

void loop() {
}