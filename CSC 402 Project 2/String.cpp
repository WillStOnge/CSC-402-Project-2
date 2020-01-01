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
	// Allocates newChar with the length of the parameters' value and copies the parameters' value to the newChar.
	value = new char[strlen(str) + 1];
	strcpy(value, str);
}

String::String(const String& str)
{
	// Allocates newChar with the length of the parameters' value and copies the parameters' value to the newChar.
	value = new char[strlen(str.value) + 1];
	strcpy(value, str.value);
}

String::String(String&& str)
{
	// Allocates newChar with the length of the parameters' value and copies the parameters' value to the newChar. Set paramters value to null.
	value = new char[strlen(str.value) + 1];
	strcpy(value, str.value);
	str.value = nullptr;
}

String::~String()
{
	// Deallocate the value
	delete value;
}

String& String::operator=(const String& other)
{
	// Frees the value and allocates a new char for the assignment. Returns a pointer to the instance.
	delete value;
	value = new char[strlen(other.value) + 1];
	strcpy(value, other.value);
	return *this;
}

String& String::operator=(String&& other)
{
	// Frees the value and allocates a new char for the assignment then sets the parameters' value pointer to null. Returns a pointer to the instance.
	delete value;
	value = new char[strlen(other.value) + 1];
	strcpy(value, other.value);
	other.value = nullptr;
	return *this;
}

char& String::operator[](int i)
{
	// Grabs the ith character from the internal value and returns it.
	return value[i];
}

const char& String::operator[](int i) const
{
	// Grabs the ith character from the internal value and returns it.
	return value[i];
}

ostream& operator<<(ostream& out, const String& value)
{
	// Adds the internal value to the stream and returns said stream.
	value.print(out);
	return out;
}

String operator+(const String& lhs, const String& rhs)
{
	// Uses the append function to all rhs onto the lhs which is part of a new String instance, then returns.
	String ret(lhs);
	ret.append(rhs);
	return ret;
}

int String::length() const
{
	// If the value is a null pointer, return 0 else return the output the length of the internal value.
	if (value == nullptr)
		return 0;
	return strlen(value);
}

bool String::empty() const
{
	// If the length of the internal value is 0, return true and vise versa.
	return strlen(value) == 0;
}

void String::print(ostream& out) const
{
	// If the value isn't a null pointer add the value to the stream.
	if(value != nullptr)
		out << value;
}

void String::clear()
{
	// Set the internal value to an empty string.
	delete value;
	value = new char[1];
}

String& String::append(const String& str)
{
	// Hold the internal value in a temperary variable and frees the value.
	char* temp = value;
	// Allocate a new char based on the combined length of the old value and new value, then set the internal value to the new character.
	value = new char[strlen(temp) + strlen(str.value)];
	// Move the strings into the internal value and return this instance of String.
	strcpy(value, temp);
	strcat(value, str.value);
	delete temp;
	return *this;
}

String& String::append(const char* s)
{
	// Hold the internal value in a temperary variable and frees the value.
	char* temp = value;
	// Allocate a new char based on the combined length of the old value and new value, then set the internal value to the new character.
	value = new char[strlen(temp) + strlen(s)];
	// Move the strings into the internal value and return this instance of String.
	strcpy(value, temp);
	strcat(value, s);
	delete temp;
	return *this;
}