/*
File Name: String.h
Author: Will St. Onge
Course: CSC 402
Date: 12/30/19
*/

#pragma once

#ifndef _MY_STRING_H
#define _MY_STRING_H
#endif

#include <iostream>
#include <cstring>

using namespace std;

class String 
{
public:
	// Constructors
	String(const char* str = "");
	String(const String& str);
	String(String&& a);

	// Destructor
	~String();

	// Member operator overrides.
	String& operator=(const String& other);
	String& operator=(String&& other);
	char& operator[](int i);
	const char& operator[](int i) const;

	// Accessor fucntions. 
	int length() const;
	bool empty() const;
	void print(ostream& out = cout) const;

	// Mutator functions
	void clear();
	String& append(const String& str);
	String& append(const char* s);

private:
	// Data member.
	char* value;
};

// Non-member operator overrides.
ostream& operator<<(ostream& out, const String& value);
String operator+(const String& lhs, const String& rhs);