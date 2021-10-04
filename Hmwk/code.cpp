#include <iostream>
 
  using namespace std;
 
  string outfit(double temp);
  
  int main() {
 	double temp;
 	char answer;
	
 	do{
 	 cout << "What's the temperature outside?" << endl;
	 cin >> temp;
 
     cout << "You should wear " << outfit(temp) << "!" << endl;
 
     cout << "Would you like another suggestion (y/n)?" << endl;
     cin >> answer;
 
     while(answer != 'y' && answer != 'n'){
       	cout << "Invalid input. Please type only y or n." << endl;
       	cout << "Would you like another suggestion (y/n)?" << endl;
       	cin >> answer;
    }
      
	}while(answer != 'n');

	 cout << "Goodbye!" << endl;
	 return 0;
 }
 
  string outfit(double temp){
	   //suggests an accessory for the weather
	     string suggestion;
	
	     if(temp <= 40){
              suggestion = "a heavy coat";
    	}else if(temp >= 75){
              suggestion = "sunglasses";
	     }else{
              suggestion = "a scarf";
	     }
	
	 return suggestion;
 }
