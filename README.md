Welcome to GLaDPi, a randomized blurter that 
yells at whoever walks by!

Place Files you would like the Blurter to yell
inside of the folder labelled "Apeture". The program will autodetect it.
It will then yell one randomly, and stay quiet for 10 seconds.


This requires the wiringPi. Learn more 
about wiringPi at: (http://wiringpi.com/reference/setup/)

The PIR Sensor GPIO Pin must be hardcoded:
See the call to `pinMode` (Line 133) to set yours before 
compilation. 


A speaker and Power Supply must also 
be connected for obvious reasons. 


Compile using:

`g++ -o main main.cpp -lwiringPi`
