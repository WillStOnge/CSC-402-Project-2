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
	char* newChar = new char[strlen(str) + 1];
	strcpy(newChar, str);
	// Deallocates and sets the value to the newChar.
	delete value;
	value = newChar;
}

String::String(const String& str)
{
	// Allocates newChar with the length of the parameters' value and copies the parameters' value to the newChar.
	char* newChar = new char[strlen(str.value) + 1];
	strcpy(newChar, str.value);
	// Deallocates and sets the value to the newChar.
	delete value;
	value = newChar;
}

String::String(String&& str)
{
	// Allocates newChar with the length of the parameters' value and copies the parameters' value to the newChar.
	char* newChar = new char[strlen(str.value) + 1];
	strcpy(newChar, str.value);
	// Deallocates and sets the value to the newChar and sets the parameters' value to a null pointer.
	delete value;
	value = newChar;
	str.value = nullptr;
}

String::~String()
{
	// Deallocate the value
	delete value;
}

String& String::operator=(const String& other)
{
	// Allocates newChar with the length of the parameters' value and copies the parameters' value to the newChar.
	char* newChar = new char[strlen(other.value) + 1];
	strcpy(newChar, other.value);
	// Frees the internal value to the heap and sets the value to the newChar, then returns this instance.
	delete value;
	value = newChar;
	return *this;
}

String& String::operator=(String&& other)
{
	// Allocates newChar with the length of the parameters' value and copies the parameters' value to the newChar.
	char* newChar = new char[strlen(other.value) + 1];
	strcpy(newChar, other.value);
	// Frees the internal value to the heap and sets the value to the newChar, then returns this instance. Also makes the parameters' value pointer null.
	delete value;
	value = newChar;
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

int String::length()
{
	// If the value is a null pointer, return 0 else return the output the length of the internal value.
	if (value == nullptr)
		return 0;
	return strlen(value);
}

bool String::empty()
{
	// If the length of the internal value is 0, return true and vise versa.
	return length() == 0;
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
	value = (char*)"";
}

String& String::append(const String& str)
{
	// Hold the internal value in a temperary variable.
	char* temp = value;
	// Allocate a new char based on the combined length of the old value and new value, then set the internal value to the new character.
	value = new char[strlen(value) + strlen(str.value) + 1];
	// Move the strings into the internal value and return this instance of String.
	strcpy(value, temp);
	strcat(value, str.value);
	return *this;
}

String& String::append(const char* s)
{
	// Hold the internal value in a temperary variable.
	char* temp = value;
	// Allocate a new char based on the combined length of the old value and new value, then set the internal value to the new character.
	value = new char[strlen(value) + strlen(s) + 1];
	// Move the strings into the internal value and return this instance of String.
	strcpy(value, temp);
	strcat(value, s);
	return *this;
}