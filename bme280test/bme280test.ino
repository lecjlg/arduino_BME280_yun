/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Console.h>
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);


void setup() {
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
    
    Bridge.begin();
    Console.begin();
    while(!Console);
  Console.println("hello world");
  Console.println(F("BME280 test"));


}

void loop() {
 
    Console.print("Temperature = ");
    Console.print(bme.readTemperature());
    Console.println(" *C");

    Console.print("Pressure = ");

    Console.print(bme.readPressure() / 100.0F);
    Console.println(" hPa");

    Console.print("Approx. Altitude = ");
    Console.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Console.println(" m");

    Console.print("Humidity = ");
    Console.print(bme.readHumidity());
    Console.println(" %");

    Console.println();
    delay(200);
   
}
