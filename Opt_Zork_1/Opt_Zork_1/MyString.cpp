#include"MyString.h"

MyString::MyString()

{
MaxSize = 1;
buffer = new char[MaxSize];
}
MyString::MyString(const char* str)
{
int length = (strlen(str))+1;
buffer = new char[length];
MaxSize = length;
strcpy_s(buffer, length, str);
}
MyString::MyString(const MyString& str)
{
int length = (strlen(str.buffer)+1);
buffer = new char[length];
MaxSize = length;
strcpy_s(this->buffer, length, str.buffer);
}
unsigned int  MyString::  MyLength() const
{
int length = (strlen(buffer));
return length;
}
const char* MyString:: c_str()const
{
return buffer;
}
bool MyString:: empty()const
{
return strlen(buffer)==0;
}
bool MyString:: operator == (const MyString& another)const
{
return strcmp(buffer, another.buffer) == 0;
}
bool MyString:: operator == (const char* another)const
{
return strcmp(buffer, another) == 0;
}
bool MyString:: operator != (const char* another)const
{
return strcmp(buffer, another) != 0;
}
void  MyString:: operator += (const MyString& one)
{/*
char *temp = nullptr;
temp = new char[strlen(buffer) + 1];
strcpy_s(temp, strlen(buffer) + 1, buffer);
delete[]buffer;
int lenght = strlen(temp) + strlen(one.buffer) + 1;
buffer = new char[lenght];
strcpy_s(buffer, lenght, temp);
*/
}
void MyString:: operator = (const MyString& one)
{

int lenght = (strlen(one.buffer)+1);

if ((MaxSize < lenght)) //Revise
{

delete[]buffer;
MaxSize = lenght;
buffer = new char[MaxSize];
}

strcpy_s(buffer, MaxSize, one.buffer);
}

MyString MyString:: operator + (const MyString& one)
{
MyString third;
int lenght = strlen(buffer) + strlen(one.buffer) + 1;
third.buffer = new char[lenght];
strcpy_s(third.buffer, lenght, buffer);
strcat_s(third.buffer, lenght, one.buffer);
return third;
}
void MyString:: Answer(const char* string)
{
	
	int length = strlen(string) + 1;
	if (MaxSize < length){
		delete[]buffer;
		MaxSize = length;
		buffer = new char[MaxSize];
	}
	strcpy_s(buffer, length, string);
	
}
MyString MyString:: operator = (const char* word)
{
int len = strlen(word) + 1;
buffer = new char[len];
strcpy_s(buffer, len, word);
return buffer;
}

Vector<MyString> MyString:: tokenize(const char* symbol, char* option)
{

char *Counter;
char* single;
char*temporal;
Vector <MyString> tokens;
unsigned int length = strlen(option) + 1;
temporal = new char[length];
strcpy_s(temporal, length, option);
single = strtok_s(temporal, symbol, &Counter);

while (single != NULL)
{
tokens.Push_back(single);
single = strtok_s(NULL, symbol, &Counter);

}
delete[] temporal;
return tokens;
}

MyString::~MyString()
{
	delete[] buffer;

}

