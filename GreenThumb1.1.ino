


// #define sensorPin A0

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(A0,INPUT_PULLUP);


}

void loop() {
  // put your main code here, to run repeatedly:


   Serial.print("Analog output: ");

   Serial.println(readSensor());

   delay(500);


}

//  This function returns the analog data to calling function

int readSensor() {

  int sensorValue = analogRead(A0);  // Read the analog value from sensor

  int outputValue = map(sensorValue, 0, 1023, 0, 255); // map the 10-bit data to 8-bit data

  return outputValue;             // Return analog moisture value

}
