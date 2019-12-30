/*
File Name: String.cpp
Author: Will St. Onge
Course: CSC 402
Date: 12/30/19
*/

#define _CRT_SECURE_NO_WARNINGS

#include "String.h"

String::String(const char* str)
{
	char* newChar = new char[strlen(str)];
	strcpy(newChar, str);
	delete value;
	value = newChar;
}

String::String(const String& str)
{
	char* newChar = new char[strlen(str.value)];
	strcpy(newChar, str.value);
	delete value;
	value = newChar;
}

String::String(String&& str)
{
	char* newChar = new char[strlen(str.value)];
	strcpy(newChar, str.value);
	delete value;
	value = newChar;
	str.value = nullptr;
}

String::~String()
{
	delete value;
}

String& String::operator=(const String& other)
{
	char* newChar = new char[strlen(other.value)];
	strcpy(newChar, other.value);
	value = newChar;
	return *this;
}

String& String::operator=(String&& other)
{
	char* newChar = new char[strlen(other.value)];
	strcpy(newChar, other.value);
	value = newChar;
	other.value = nullptr;
	return *this;
}

char& String::operator[](int i)
{
	return value[i];
}

const char& String::operator[](int i) const
{
	return value[i];
}

ostream& operator<<(ostream& out, const String& value)
{
	value.print(out);
	return out;
}

String operator+(const String& lhs, const String& rhs)
{
	String ret(lhs);
	ret.append(rhs);
	return ret;
}

int String::length()
{
	if (value == nullptr)
		return 0;
	return strlen(value);
}

bool String::empty()
{
	return length() == 0;
}

void String::print(ostream& out) const
{
	if(value != nullptr)
		out << value;
}

void String::clear()
{
	value = (char*)"";
}

String& String::append(const String& str)
{
	char* temp = value;
	value = new char[strlen(value) + strlen(str.value)];
	strcpy(value, temp);
	strcat(value, str.value);
	return *this;
}

String& String::append(const char* s)
{
	char* temp = value;
	value = new char[strlen(value) + strlen(s)];
	strcpy(value, temp);
	strcat(value, s);
	return *this;
}