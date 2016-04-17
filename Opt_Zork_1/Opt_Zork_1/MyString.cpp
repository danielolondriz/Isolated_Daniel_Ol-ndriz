#include"MyString.h"


const char* MyString::C_Str() const{//to print buffer in main
	return buffer;
}
MyString::MyString(){
	maxcapacity = 1;
	buffer = new char[maxcapacity];
}

MyString::MyString(const char* STR){
	int len = (strlen(STR)) + 1;
	maxcapacity = len;
	buffer = new char[len];//+1 because '\0'
	strcpy_s(buffer, len, STR);
}

MyString::MyString(const MyString& otherclas){
	int len = (strlen(otherclas.buffer)) + 1;
	maxcapacity = len;
	buffer = new char[len];//+1 because '\0'
	strcpy_s(buffer, len, otherclas.buffer);
}

unsigned int MyString::lenght(){
	unsigned int i = strlen(buffer);
	return i;
}

bool MyString::empty() const{
	return strlen(buffer) == 0;
}

bool MyString::operator ==(const MyString& otherclas) const{
	return strcmp(buffer, otherclas.buffer) == 0;
}

bool MyString::operator ==(const char* otherstring) const{
	return strcmp(buffer, otherstring) == 0;
}

bool MyString::operator !=(const char* otherstring) const{
	return strcmp(buffer, otherstring) != 0;
}

void MyString::operator =(const MyString& otherclas){
	int lent = (strlen(otherclas.buffer) + 1);
	if (maxcapacity < lent){
		delete[]buffer;
		maxcapacity = lent;
		buffer = new char[maxcapacity];
	}
	strcpy_s(buffer, maxcapacity, otherclas.buffer);
}

void MyString::operator =(const char* otherstring){
	int lent = (strlen(otherstring) + 1);
	if (maxcapacity < lent){
		delete[]buffer;
		maxcapacity = lent;
		buffer = new char[maxcapacity];
	}
	strcpy_s(buffer, maxcapacity, otherstring);
}


void MyString::operator +=(const MyString& otherclas){
	int lent = (strlen(otherclas.buffer) + lenght() + 1);
	if (maxcapacity < lent){
		char *temp = nullptr;
		temp = new char[strlen(buffer) + 1];
		strcpy_s(temp, strlen(buffer) + 1, buffer);
		delete[]buffer;
		lent = strlen(temp) + strlen(otherclas.buffer) + 1;
		maxcapacity = lent;
		buffer = new char[lent];
		strcpy_s(buffer, lent, temp);
		strcat_s(buffer, lent, otherclas.buffer);
		//printf("hola");
	}
	else{
		strcat_s(buffer, strlen(buffer), otherclas.buffer);
	}


}

MyString  MyString::operator+(const MyString &otherclas)
{
	MyString newstring;
	int len = strlen(buffer) + strlen(otherclas.buffer) + 1;
	maxcapacity = len;
	newstring.buffer = new char[len];
	strcpy_s(newstring.buffer, len, buffer);
	strcat_s(newstring.buffer, len, otherclas.buffer);
	return newstring;
}

void  MyString::clear()
{
	buffer[0] = '\0';
}

void MyString::set()
{
	char otherstring[50];
	gets_s(otherstring, 50);
	int lent = strlen(otherstring) + 1;
	if (maxcapacity < lent){
		delete[]buffer;
		maxcapacity = lent;
		buffer = new char[maxcapacity];
	}
	strcpy_s(buffer, maxcapacity, otherstring);
}

Vector<MyString> MyString::Tokenize(const char *parameters, char* option){

	uint len = strlen(option) + 1;
	Vector<MyString> stringvector;
	char *finalstring, *other, *repeat;
	finalstring = new char[len];
	strcpy_s(finalstring, len, option);

	other = strtok_s(finalstring, parameters, &repeat);
	while (other != NULL){
		stringvector.Push_back(other);
		other = strtok_s(NULL, parameters, &repeat);
	}
	delete[] finalstring;
	return stringvector;
}
void MyString:: Get(const char* string)
{
	int len = strlen(string);
	delete[]buffer;
	buffer = new char[len + 1];
	strcpy_s(buffer, len + 1, string);
}

MyString::~MyString(){
	delete[] buffer;
}