#ifndef _MYSTRING
#define __MYSTRING
#include <string.h>
#include <stdio.h>
#include "Vector.h"
typedef unsigned int uint;
/*
class MyString{

private:
	char* buffer = nullptr;
	
	unsigned int MaxSize = 50;
public:
	MyString()
	{
	unsigned int MinSize = 1;
	buffer = new char[MinSize];
	}

	MyString(const char* str)
	{
		int length = (strlen(str))+1;
		buffer = new char[length];
		MaxSize = length;
		strcpy_s(buffer, length, str);
		

	}
	MyString(const MyString& str)
	{
		int length = (strlen(str.buffer)+1);
		buffer = new char[length];
		MaxSize = length;
		strcpy_s(this->buffer, length, str.buffer);
		
	}
	
	unsigned int MyLength() const
	{
		int length = (strlen(buffer));
		return length;
	}
	const char* c_str()const //function to print 
	{
		return buffer;
	}

	bool empty()const//checks if buffer is null
	{
		return strlen(buffer) == 0;
	}
	bool operator == (const MyString& another)const
	{
		return strcmp(buffer, another.buffer) == 0;

	}
	bool operator == (const char* another)const
	{
		
		return strcmp(buffer, another) == 0;

	}
	bool operator != (const char* another)const
	{

		return strcmp(buffer, another) != 0;

	}
	/*
	void operator += (const MyString& one)
	{
	char *temp = nullptr;
	temp = new char[strlen(buffer) + 1];
	strcpy_s(temp, strlen(buffer) + 1, buffer);
	delete[]buffer;
	int lenght = strlen(temp) + strlen(one.buffer) + 1;
	buffer = new char[lenght];
	strcpy_s(buffer, lenght, temp);
	}
	void operator = (const MyString& one)
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
	MyString operator + (const MyString& one)
	{
		MyString third;
		int lenght = strlen(buffer) + strlen(one.buffer) + 1;
		third.buffer = new char[lenght];
		strcpy_s(third.buffer, lenght, buffer);
		strcat_s(third.buffer, lenght, one.buffer);
		return third;
	}
	void Get(const char* string)
	{
		int len = strlen(string);
		delete[]buffer;
		buffer = new char[len + 1];
		strcpy_s(buffer, len + 1, string);
	}
	//EXTRA OPERATIONS FOR ZORK
	MyString operator = (const char* word)
	{
		int len = strlen(word) + 1;
		buffer = new char[len];
		strcpy_s(buffer, len, word);
		return buffer;
	}
	
	Vector<MyString> tokenize(const char* symbol, char* option)
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


	
	~MyString()
	{
	delete[] buffer;

	}

};*/

class MyString{
private:
char *buffer = nullptr;
unsigned int maxcapacity=50;
public:
const char* C_Str() const;
MyString();
MyString(const char* STR);
MyString(const MyString& otherclas);
unsigned int lenght();
bool empty() const;
bool operator ==(const MyString& otherclas) const;
bool operator ==(const char* otherstring) const;
bool operator !=(const char* otherstring) const;
void operator =(const MyString& otherclas);
void operator =(const char* otherstring);
void operator +=(const MyString& otherclas);
MyString operator+(const MyString &otherclas);
bool SameLenght(const MyString& str);
bool IsSmaller(const MyString& str);
void clear();
void set();
void Get(const char*);
Vector<MyString> Tokenize(const char *parameters, char* option);
~MyString();
};
#endif