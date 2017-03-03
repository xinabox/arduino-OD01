/*************************************************************
	This is an examples for the OD01 0.96 inch OLED Display
	
	You can buy one on our store!
	-----> https://xinabox.cc/OD01/
	
	This example display a list of I2C devices addresses 
	available on the I2C Bus on the OD01 OLED Display
	
	The display communicates over the I2C Bus.

	------------------------TIPS--------------------------
	Change this line ----->Wire.begin(2,14);
	to this			 ----->Wire.begin();
	to allow this sensor to communicate with CC01 and CR01	
	
*************************************************************/

#include <xCore.h>
#include <xOD01.h>

const int DELAY_TIME = 2000;


String I2Cfound1 = "";
String I2Cfound2 = "";

void setup() {
	Wire.begin(2,14);
	OLED.begin();
	OD01.println("\nI2C Scanner");
	OD01.println("===========");
}

void loop() {
  I2C_scan();
  delay(DELAY_TIME);
}

void I2C_scan()
{
  byte error, address;
  int nDevices = 0;
  int wrap = 0;

  OD01.print("xCHIP scan...");
  I2Cfound1 = "";
  I2Cfound2 = "";
  for (address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      String v = String(address, HEX);
      if (v.length() == 1) v = "0" + v;
      v.toUpperCase();
      OD01.println("0x");
      OD01.print(v);
      OD01.print(" ");
      nDevices = 1;
	  wrap++;
	  if(wrap == 4){
		OD01.println();
		wrap = 0;
	  }
    }
  }
  if (nDevices == 0) {
    OD01.println("No xCHIPs connected to the xBUS\n");
  }
  OD01.println();
}