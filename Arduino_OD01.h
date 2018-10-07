/*
	This is a library for the OD01
	XinaBox Modules
	
	Functions include:
	-	I2C Communication
*/

#ifndef Arduino_OD01_h
#define Arduino_OD01_h

// System Includes
#include <Wire.h>
#include <xCore.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

class xOD01: public SSD1306AsciiWire
{
	public:
		
		xOD01(void);
		xOD01(uint8_t addr);

		void begin();
	private:
		uint8_t OD01_I2C_ADDRESS;
};
#endif
