# GreenThumbIrrigation
Smart Irrigation System Using an ESP8266 for Automated Plant Watering 




**PROGRESS** (Contains sub-categories for ISSUES, FIXES and FUTURE TASKS)


      **ISSUES**

          • 10/05/24 The wiring for the water pump is short and the wires are very thin, will have to figure out how to fix that
          • 10/05/24 My Mac is not recognizing the usb port for some random reason now, so cant upload new code
          • 10/05/24 Thinking about how after I get the circuit fully functioning how will I create and add it into a casing 
          • 10/05/24 Not really an issue but need to start investigating how to make the app the interact with the system after it is done


          • 10/12/24 The map function is not outputting the values correctly so I need to find the values to calibrate the SMS
          • 10/12/24 Need to write the code so that the water pump only turns on when the soil moisture level (SML) reaches a certain level


          • 10/26/24 I would not really call this an issue however, I need to order an OLED display on Amazon so I can properly display the SML and battery life
          • 10/26/24 Other than the OLED screen the system itself and the code is pretty much done all I need now is to learn KiCad to create the PCB design



        **FIXES** 
          
          • 10/05/24 Figured out why I couldnt upload code ( I needed to restart the ESP)
          • 10/05/24 Got the whole prototype system running now I can start making code for real application

          • 10/12/24 Printed the raw values that the analog pin is reading and used that to calibrate the SMS (299-707)
          • 10/12/24 The values still go a little over and under 0 and 100 but it is so small that it is negligible to consider
          • 10/12/24 Wrote the code so that the water pump only turns on when the SML reaches at or below 35 (will test on real soil sample next time)


    





