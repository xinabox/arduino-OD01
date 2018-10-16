// System Includes
#include "arduino-OC01.h"

xOD01::xOD01(void):SSD1306AsciiWire()
{
    OD01_I2C_ADDRESS = 0x3C;
}

xOD01::xOD01(uint8_t addr):SSD1306AsciiWire()
{   
    OD01_I2C_ADDRESS = addr;
}

void xOD01::begin(void)
{
	start(&Adafruit128x64, OD01_I2C_ADDRESS);
	setFont(Adafruit5x7);
	clear();
	setScroll(true);
	set1X();
}