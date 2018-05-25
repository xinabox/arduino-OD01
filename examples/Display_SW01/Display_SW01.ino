/*************************************************************
	This is an examples for the OD01 0.96 inch OLED Display
	
	You can buy one on our store!
	-----> https://xinabox.cc/OD01/
	
	This example display a temperature and pressure captured
	from the SW01 ☒CHIP text on the OLED display.
	
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

#include <xSW01.h>
#include <xCore.h>
#include <xOD01.h>

const int DELAY_TIME = 1500;

xSW01 SW01;

void setup() {
  // Starts the I2C communication
  Wire.begin(2,14);
  
  // Start the OLED Display OD01
  OLED.begin();

  // Start the  SW01 Sensor
  SW01.begin();

  // Display Example Name on OD01
  OD01.println("SW01 Temperature");

  // send command to clear the display
  OD01.clear();

  delay(DELAY_TIME);
}

void loop() {
  // Create a variable to store the data read from SW01 
  float temperature, pressure;
  temperature = pressure = 0;

  // request the sensor to read data
  SW01.poll();
  
  // Request SW01 to get the temperature measurement 
  // Temperature  request is degrees celcuis  
  temperature = SW01.getTempC();
  
  // Display the temperature on the OLED display OD01   
  OD01.print("Temperature: ");
  OD01.print(temperature);
  OD01.println(" C");

  // Request SW01 to get the temperature measurement 
  // Temperature  request is farenheit  
  temperature = SW01.getTempF();
  
  // Display the temperature on the OLED display OD01   
  OD01.print("Temperature: ");
  OD01.print(temperature);
  OD01.println(" F");

  // Request SW01 to get the pressure measurement 
  // Pressure request is in pascals 
  // This is the converter to kilo pascals
  pressure = SW01.getPressure();

  // Display the pressure on the OLED display OD01   
  OD01.print("Pressure: ");
  // Display a convertered kPa value
  OD01.print(pressure/1000);
  OD01.println(" kPa");  
  
  // delay between sensor reads
  delay(DELAY_TIME);  
  
  // send command to clear the display
  OD01.clear();
}
