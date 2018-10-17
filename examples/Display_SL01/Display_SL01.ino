/*************************************************************
	This is an examples for the OD01 0.96 inch OLED Display
	
	You can buy one on our store!
	-----> https://xinabox.cc/OD01/
	
	This example display a UV light measurement
	from the SL01 ☒CHIP text on the OLED display.
	
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

#include <xSL01.h>
#include <xCore.h>
#include <xOD01.h>

const int DELAY_TIME = 1500;

xSL01 SL01;
xOD01 OD01;

void setup() {
  // Starts the I2C communication
#ifdef ESP8266
  Wire.pins(2, 14);
#endif
  Wire.begin();
  
  // Start the OLED Display OD01
  OD01.begin();

  // Start the  SW01 Sensor
  SL01.begin();
   
  // Display Example Name on OD01
  OD01.println("SL01 UV Light");

  delay(DELAY_TIME);

  // send command to clear the display
  OD01.clear();

  delay(DELAY_TIME);
}

void loop() {
  // Create a variable to store the data read from SL01
  float uv;
  uv = 0;

  // Poll Sensor for collect data
  SL01.poll();
  
  // Request SL01 to return calculated UVB intensity
  uv = SL01.getUVA();

  // Display Data on the Serial monitor
  OD01.println("UVA Intensity: ");
  OD01.print(uv);
  OD01.println(" uW/cm^2");

  OD01.println();
  // Request SL01 to return calculated UVB intensity
  uv = SL01.getUVB();

  // Display Data on the Serial monitor
  OD01.println("UVB Intensity: ");
  OD01.print(uv);
  OD01.println(" uW/cm^2"); 
  
  // delay between sensor reads
  delay(DELAY_TIME);  
  
  // send command to clear the display
  OD01.clear();
}