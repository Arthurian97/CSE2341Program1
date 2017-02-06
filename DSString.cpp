#include <string.h>

class String{
	private:
		int size;
		char* c_ str;
	
	public:
		String(){
			size = 0;
			c_str = "";
		}
	
		String(const char* p){
			size = strlen(p);
			c_str = p
		}
	
	       	String(const String& s){
			size = strlen(s.c_dtr());
			c_str = s.c_str
		}
	
       		String& operator= (const char*){
			string s = "abc";
			const char* c_s = s.c_str();
		}
        	String& operator = (const String&);
       		String operator + (const String&);
       		bool operator == (const char*);
       		bool operator == (const String&);
       		bool operator > (const String&);
       		char& operator[] (const int);
	
       		int size(){
			return size;
		}
	
       		String substring(int, int);
	
       		char* c_str(){
			return c_str;
		}
	
       		friend std::ostream& operator<< (std::ostream&, const String&);
	
       		~String();
	
};
