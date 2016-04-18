#ifndef _MYSTRING
#define __MYSTRING
#include <string.h>
#include <stdio.h>
#include "Vector.h"
typedef unsigned int uint;

class MyString{

private:
	char* buffer = nullptr;
	unsigned int MaxSize = 30;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	unsigned int MyLength() const;
	const char* c_str()const; //function to print 
	bool empty()const;//checks if buffer is null
	bool operator == (const MyString& another)const;
	bool operator == (const char* another)const;
	bool operator != (const char* another)const;
	void operator += (const MyString& one);
	void operator = (const MyString& one);
	MyString operator + (const MyString& one);
	void Answer(const char* string);
	//EXTRA OPERATIONS FOR ZORK
	MyString operator = (const char* word);
	Vector<MyString> tokenize(const char* symbol, char* option);
	~MyString();
	
};

#endif