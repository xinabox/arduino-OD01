/*
	This is a library for the OD01
	XinaBox Modules
	
	Functions include:
	-	I2C Communication
*/

#ifndef XiX_OD01_h
#define XiX_OD01_h

// System Includes
#include <Wire.h>
#include <XiX_Core.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// Device I2C Address
#define OD01_I2C_ADDRESS   		0x3C  

SSD1306AsciiWire OD01;

void OD01.begin(){
	OD01.start(&Adafruit128x64, OD01_I2C_ADDRESS);
	OD01.setFont(Adafruit5x7);
	OD01.clear();
	OD01.setScroll(true);
	OD01.set1X();
}
	
#endif