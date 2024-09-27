


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(A0,INPUT_PULLUP);


}

void loop() {
  // put your main code here, to run repeatedly:


   // Prints what the soil mouisture sensor is every .5 seconds
   Serial.print("Soil Moisture Level: ");

   // Calls the readSensor() function and prints the returned magnitude value 
   Serial.println(readSensor());
   Serial.print("%");

   // delays it .5 seconds will probably change later when full circuit is functioning
   delay(500);


}

//  This function returns the analog data to calling function (the moisture level from 0 - 100 )
int readSensor() {

  int sensorValue = analogRead(A0);  // Read the analog value from sensor

  int outputValue = map(sensorValue, 0, 1023, 0, 100); // Should map values from 0 to 100 but need to double check

  return outputValue;   // Return analog moisture value

}
