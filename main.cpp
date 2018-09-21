#include<wiringPi.h>
#include<dirent.h>
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>


#define BITS 8


using namespace std;
int numberOfSongs = 0;
char * path;
vector<string> songList;


string getFileExt(const string& s) {

   size_t i = s.rfind('.', s.length());
   if (i != string::npos) {
      return(s.substr(i+1, s.length() - i));
   }
   return("");
}


int play_audio()
{
	// Build the path for the audio list.
	

	string formedPath(path);

	int randNum = rand()%numberOfSongs + 1;
	string songExt(getFileExt(songList[randNum]));
	char *playCall = new char[500];




	if(strcmp(songExt.c_str(),"mp3") == 0 )
	snprintf(playCall,500,"mpg123 %s",songList[randNum].c_str()); 
    else if(strcmp(songExt.c_str(), "wav") == 0 )
    snprintf(playCall,500,"aplay %s", songList[randNum].c_str());
	 
 	
  
	int ret = 0;
	
	cout << "Calling bash command: " << playCall << endl;
	system(playCall);
	delete(playCall);
	return 0; 
  

}





void initialize_audio(){
	
	DIR *d;
	struct dirent *dir;
	d = opendir("./Apeture");
	string formedPath(path);
    formedPath = formedPath + "/Apeture";
	strcpy(path, formedPath.c_str());


	if (d)
	{
		while((dir = readdir(d)) != NULL)
		{
			
				string formedPath(path);
				string songName(dir->d_name);
				formedPath = formedPath + "/" + songName;

				songList.push_back(formedPath);
				printf("%s\n", formedPath.c_str());
				numberOfSongs++;


			

		}
		closedir(d);
		cout << "Number of Songs: " << numberOfSongs << endl;

	}









}


int main(){

	path = new char[200];
	for(int i =0; i < 200; i++)
		path[i] == '\0';
	getcwd(path, 200);
	printf("%s\n", path);
	string s(path); 
	s = s + "/Apeture/";
	cout << endl << s;


	initialize_audio(); 
	system("espeak 'Alert. glad pi is now online.'");
	srand(5);
	play_audio();



	
	wiringPiSetup(); 
	pinMode(7,INPUT);
	while (true){
	
		
		if(digitalRead(7) >0)
			cout << "I DETECT YOU\n";
			play_audio(); 
			usleep(10000000);
	

		
return 0;
}

