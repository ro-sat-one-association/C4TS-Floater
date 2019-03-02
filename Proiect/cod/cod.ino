#include <Wire.h>
#include "BlueDot_BME280.h"

BlueDot_BME280 bme2; 
int bme2Detected = 0;   
void setup() {
  Serial.begin(38400);
  Serial.println(F("Basic Weather Station"));
  bme2.parameter.communication = 0;    
  bme2.parameter.I2CAddress = 0x76;  
  bme2.parameter.sensorMode = 0b11;
  bme2.parameter.IIRfilter = 0b100; 
  bme2.parameter.humidOversampling = 0b101;
  bme2.parameter.tempOversampling = 0b101;
  bme2.parameter.pressOversampling = 0b101;
  bme2.parameter.pressureSeaLevel = 1013.25;
  bme2.parameter.tempOutsideCelsius = 15;  
  bme2.parameter.tempOutsideFahrenheit = 59;  
   if (bme2.init() != 0x60)
  {    
    Serial.println(F("Ops! Second BME280 Sensor not found!"));
    bme2Detected = 0;
  }

  else
  {
    Serial.println(F("Second BME280 Sensor detected!"));
    bme2Detected = 1;
  }
  if (bme2Detected == 0)
  {
    Serial.println();
    Serial.println();
    Serial.println(F("Troubleshooting Guide"));
    Serial.println(F("*************************************************************"));
    Serial.println(F("1. Let's check the basics: Are the VCC and GND pins connected correctly? If the BME280 is getting really hot, then the wires are crossed."));
    Serial.println();
    Serial.println(F("2. Did you connect the SDI pin from your BME280 to the SDA line from the Arduino?"));
    Serial.println();
    Serial.println(F("3. And did you connect the SCK pin from the BME280 to the SCL line from your Arduino?"));
    Serial.println();
    Serial.println(F("4. One of your sensors should be using the alternative I2C Address(0x76). Did you remember to connect the SDO pin to GND?"));
    Serial.println();
    Serial.println(F("5. The other sensor should be using the default I2C Address (0x77. Did you remember to leave the SDO pin unconnected?"));

    Serial.println();
    
    while(1);
  }
  Serial.println();
  Serial.println();

     
}


void loop() {
  Serial.print(F("Duration in Seconds:  "));
  Serial.println(float(millis())/1000);
    if (bme2Detected)
  {
    Serial.print(F("Temperature Sensor 2 [°C]:\t\t")); 
    Serial.println(bme2.readTempC());
    //Serial.print(F("Temperature Sensor 2 [°F]:\t\t")); 
    //Serial.println(bme2.readTempF());
    Serial.print(F("Humidity Sensor 2 [%]:\t\t\t")); 
    Serial.println(bme2.readHumidity());
    Serial.print(F("Pressure Sensor 2 [hPa]:\t\t")); 
    Serial.println(bme2.readPressure());
    Serial.print(F("Altitude Sensor 2 [m]:\t\t\t")); 
    Serial.println(bme2.readAltitudeMeter());
    //Serial.print(F("Altitude Sensor 2 [ft]:\t\t\t")); 
    //Serial.println(bme2.readAltitudeFeet());    
  }

  else
  {
    Serial.print(F("Temperature Sensor 2 [°C]:\t\t")); 
    Serial.println(F("Null"));
    //Serial.print(F("Temperature Sensor 2 [°F]:\t\t")); 
    //Serial.println(F("Null"));
    Serial.print(F("Humidity Sensor 2 [%]:\t\t\t")); 
    Serial.println(F("Null"));
    Serial.print(F("Pressure Sensor 2 [hPa]:\t\t")); 
    Serial.println(F("Null"));
    Serial.print(F("Altitude Sensor 2 [m]:\t\t\t")); 
    Serial.println(F("Null"));
    //Serial.print(F("Altitude Sensor 2 [ft]:\t\t\t")); 
    //Serial.println(F("Null"));
  }
   
   Serial.println();
   Serial.println();

   delay(1000);

                
}
