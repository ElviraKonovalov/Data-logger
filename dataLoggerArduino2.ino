#include <SPI.h>
#include <SD.h>
#include "Wire.h"    // imports the wire library for talking over I2C 
#include "Adafruit_BMP085.h"  // import the Pressure Sensor Library *NEEDED ONLY FOR THE TEST*
Adafruit_BMP085 mySensor;  // create sensor object called mySensor *NEEDED ONLY FOR THE TEST*

int sensorOne = 4; // First sensor connected to analog pin 4
int sensorTwo = 5; // Second sensor connected to analog pin 5
unsigned long time; // Variable to read time
const int chipSelect = 8;

void setup()
{

  Serial.begin(9600);
  mySensor.begin();   //initialize mySensor *NEEDED ONLU FOR THE TEST*

  while (!Serial) {
    ; // wait for serial port to connect. 
  }


  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it
  pinMode(10, OUTPUT);

  // The chipSelect pin you use should also be set to output
  pinMode(chipSelect, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
  String dataString = "TIME: "; // Makes a string for assembling the data to log
  time = millis(); // Starts timer
  dataString += String(time); // Prints time since program started
  dataString += "    "
   
  dataString = "Sensor1: ";

  sensorOneValue = analogRead(sensorOne); // Read the input pin 4
  sensorTwoValue = analogRead(sensorTwo); // Read the input pin 5
  
  // Append sensor data to the string
  
    dataString += String(sensorOneValue);
    dataString += "         Sensor2: ";
    dataString += String(sensorTwoValue);


  File dataFile = SD.open(fileName, FILE_WRITE); // Open file

  // if the file is available, write to it
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }

  // Code for creating multiple files *TO RUN&CHECK WITH ARDUINO AND SHIELD*
  // If sensor data value changes drastically (-+15) create new file with with new file name
  if(sensorOneValue == sensorOnevalue + 15 || sensorOnevalue == sensorOneValue - 15) { 
    while (SD.exists(filename)) {
    if (filename[BASE_NAME_SIZE + 1] != '9') {
      filename[BASE_NAME_SIZE + 1]++;
    } 
    else if (filename[BASE_NAME_SIZE] != '9') {
      filename[BASE_NAME_SIZE + 1] = '0';
     filename[BASE_NAME_SIZE]++;
    } 
  }

}

