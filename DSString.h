#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>

using namespace std;

class String{

    public:
	
	int length;
	char *charArray;

    public:

        String(){
		length=0;
		charArray=new char[1];
		charArray[0]='\0';
	}
        String(const char* cString){
		length=strlen(cString);
		charArray=new char[length];
		strcpy(charArray, cString);
	}
	String(const String& myString){
		length=myString.size();
		charArray=new char[length];
		strcpy(charArray, myString.c_str());
	}

/*        String& operator= (const char*){
        String& operator= (const String&);
        String operator+ (const String&);
        bool operator== (const char*);
        bool operator== (const String&);
        bool operator> (const String&);
        char& operator[] (const int);
*/
        int size() const{
		return length;
	}
	String substring(int start, int end){
		char *subArray=new char[end-start];
		memcpy(subArray, charArray+start, end-start);
		subArray[end-start]='\0';
		String *subString=new String(subArray);
/*		for (int i=start;i<end;i++){
			subArray[i]=charArray[i];
		}
*/		return *subString;
	}
	char* c_str() const{
		char *cString=new char[length];
		strcpy(cString, charArray);
		return charArray;
	}

	friend std::ostream& operator<< (std::ostream&, const String&){
		

        ~String(){
		delete[] charArray;
	}

};


#endif
