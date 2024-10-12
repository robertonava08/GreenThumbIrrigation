
#define relay_pin 4

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(A0,INPUT_PULLUP);
  pinMode(relay_pin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

   // Calls the readSensor() function and prints the returned magnitude value 
   int soil_mouisture = readSensor();

   // Prints what the soil mouisture sensor is every .5 seconds
   Serial.print("Soil Moisture Level: ");
   Serial.print(soil_mouisture);
   Serial.println("%");

   // delays it .5 seconds will probably change later when full circuit is functioning
   delay(500);


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
  delay(5000);                    // Wait for 5 seconds (the pump runs)
  digitalWrite(relay_pin, HIGH);  // Turn off the relay (open the circuit to the pump)
  //delay(1000);                    // Wait for 1 second (no pump operation) 

}
