#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
String pressurenow;

#define SEALEVELPRESSURE_HPA (1024)
Adafruit_BME280 bme; // I2C
int incomingByte = 0; 
unsigned long delayTime;

void setup() {
    Serial.begin(9600);

    
    Serial1.println(F("BME280 test"));
    Serial1.begin(9600);

    while(Serial1.available()) {
    pressurenow= Serial1.readString();// read the incoming data as string
    Serial1.println(pressurenow);

}

  // send data only when you receive data:
        if (Serial1.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial1.print("I received: ");
                Serial1.println(incomingByte, DEC);
        }

    bool status;
    
    // default settings
    status = bme.begin();
    if (!status) {
        Serial1.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
    
    Serial1.println("Temperature,Pressure,Altitude,Humidity");
    delayTime = 1000;

    Serial.println("Temperature,Pressure,Altitude,Humidity");


      
}


void loop() { 
  delay(delayTime);
    printValues();
    
}


void printValues() {
 Serial.print(bme.readTemperature());
    Serial.print(",");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.print(",");


    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.print(",");


    Serial.print(bme.readHumidity());
    Serial.print(",");

    Serial1.println();
  
    Serial1.print(bme.readTemperature());
    Serial1.print(",");

    Serial1.print(bme.readPressure() / 100.0F);
    Serial1.print(",");


    Serial1.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial1.print(",");


    Serial1.print(bme.readHumidity());
    Serial1.print(",");

    Serial1.println();
    Serial.println();
}
