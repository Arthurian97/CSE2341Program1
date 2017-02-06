#include <DSString.h>
#include <iostream>
#include <fstream>
#include <string>

using namspace std;

int main(){
	fstream file;
	cout << "Please enter the team file name: " << endl;
	string filename;
	cin >> filename;
	file.open(filename,ios::in);
	 
}
