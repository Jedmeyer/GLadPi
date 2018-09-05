#include<wiringPi.h>
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>


#define BITS 8


using namespace std;
int numberOfSongs = 37;
int play_audio()
{
	char *path = new char[500];
	int randNum  = rand()%numberOfSongs +1;


	if(randNum<21)
	snprintf(path,500,"mpg123 /home/pi/dev/gladpi/Apeture/%d.mp3",randNum); 
    else
    snprintf(path,500,"mpg123 /home/pi/dev/gladpi/Apeture/%d.wav",randNum);
	cout << path << endl;
 
	int ret = 0;
	 
	system(path);
	delete(path);
	return 0; 
  

}





int main(){
	system("espeak 'Alert. glad pi is now online.'");
	srand(5);
	wiringPiSetup(); 
	pinMode(7,INPUT);
	while (true){
	
		
		if(digitalRead(7) >0){
			cout << "I DETECT YOU\n";
			play_audio(); 
			usleep(10000000);
		}

	}
return 0;



}

