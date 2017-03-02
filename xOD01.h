/*
	This is a library for the OD01
	XinaBox Modules
	
	Functions include:
	-	I2C Communication
*/

#ifndef xOD01_h
#define xOD01_h

// System Includes
#include <Wire.h>
#include <xCore.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// Device I2C Address
#define OD01_I2C_ADDRESS   		0x3C  

SSD1306AsciiWire OD01;

class xOD01: public SSD1306AsciiWire
{
	public:
		xOD01(){}
		void begin(void){
			OD01.start(&Adafruit128x64, OD01_I2C_ADDRESS);
			OD01.setFont(Adafruit5x7);
			OD01.clear();
			OD01.setScroll(true);
			OD01.set1X();
		}
};

extern xOD01 OLED;
	
#endif
