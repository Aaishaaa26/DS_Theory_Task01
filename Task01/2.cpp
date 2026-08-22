#include <iostream>
#include <cstring>
using namespace std;
 class Document{
 	char* text;
 	public:
 		Document(const char* iContent){
 			text = new char[strlen(iContent)+1];
 			strcpy(text,iContent);
		 }
		 ~Document(){
		 	delete[] text;
		 }
		 Document(const Document& d){
		 	text = new char[strlen(d.text)+1];
		 	strcpy(text, d.text);
		 }
		 Document& operator=(const Document& d){
		 	delete [] text;
		 	text = new char[strlen(d.text)+1];
		 	strcpy(text, d.text);
		 	return *this;
		 }
		 void modify(const char* newContent){
		 	delete []text;
		 	text = new char[strlen(newContent)+1];
		 	strcpy(text, newContent);

		 }
		 void show(){
		 	cout << text << endl << endl;
		 }
 	
 }; 
 
 int main(){
 	Document d1("Hello World");
 	Document d2(d1);
 	Document d3 = d1;
 	d3.modify("Bye WOrld");
 	d2.modify("NAH");
 	d1.show();
 	d2.show();
 	d3.show();
 	
 }
