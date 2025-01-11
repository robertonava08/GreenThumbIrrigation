
#define relay_pin 4

#include <Wire.h>  // The "Wire" library is used so your microcontroller can communicate with I2C devices
#include <Adafruit_GFX.h> // The "AdrafruitGFX" library is used to render graphics and texts on displays
#include <Adafruit_SSD1306.h> // This library is designed to control SSD1306 based OLED screens

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
/*
  The line of code above basically just initializes the dimensions
  and the I2C communication for the OLED screen
 */

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // Specify I2C pins for OLED display, SDA is on d3 and SCL is on D1
  Wire.begin(D3, D1); // the begin() method in the Wire library means that any I2C devices connected to these pins can communicate with your microcontroller

  pinMode(A0,INPUT_PULLUP);
  pinMode(relay_pin, OUTPUT);


   // This function "display.begin(SSD1306_SWITCHCAPVCC, 0x3C)" initializes the OLED display 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 

    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // If it does not work the rest of the code will not run 

  }

  
  delay(1000);  // Gives the OLED some time to start 
  display.clearDisplay(); // Clears any old data to ensure no remnants are left behind
  display.setTextSize(4); // sets the size of the text on the OLED screen
  display.setTextColor(WHITE); // sets the color of the text on the screen 
  display.setCursor(0, 0); // where the text will begin on the display
  display.println("Display Initialized!"); // prints on the screen
  display.display(); // updates the display to show what you want 
  delay(2000);  // Hold message on screen for 2 seconds
  display.clearDisplay(); 


}


void loop() {
  // put your main code here, to run repeatedly:

   // Calls the readSensor() function and prints the returned magnitude value 
   int soil_mouisture = readSensor();

   // Prints what the soil mouisture sensor is every .5 seconds
   Serial.print("Soil Moisture Level: ");
   Serial.print(soil_mouisture);
   Serial.println("%");


     // Display soil moisture level on OLED
     display.clearDisplay();
     display.setCursor(25, 20);
     //display.print(": ");
     display.print(soil_mouisture);
     display.print("%");
     display.display();

   // delays it .5 seconds will probably change later when full circuit is functioning
   delay(1000);


   // If statement to call relay module if the SML reaches a certain level (we will use 35 for prototyping)
   if(soil_mouisture <= 35){

   // Call the relay module
   relay();

   }
   
}

//  This function returns the analog data to calling function (the moisture level from 0 - 100 )
int readSensor() {

  int sensorValue = analogRead(A0);  // Read the analog value from sensor

  // Print the sensor value to see what analog reads raw
  Serial.print("Raw Sensor Value: ");
  Serial.println(sensorValue);


  int outputValue = map(sensorValue, 299, 707, 100, 0); // Calibrated the map function because the minimum values it reads is 299 and max is 707

  // Constrain the output to be within 0-100 range (The actual values go a couple under and over 0 and 100 but that is negligible)
  outputValue = constrain(outputValue, 0, 100);

  return outputValue;   // Return analog moisture value

}

// Prototype relay function 
void relay(){

  digitalWrite(relay_pin, LOW);    // Turn on the relay (close the circuit to the pump
  delay(3000);                    // Wait for 3 second (the pump runs)
  digitalWrite(relay_pin, HIGH);  // Turn off the relay (open the circuit to the pump)
  

}
