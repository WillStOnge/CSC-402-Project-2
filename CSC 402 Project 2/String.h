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

using namespace std;

class String 
{
public:
	String(const char* str = "");
	String(const String& str);
	String(String&& a);
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other);
	char& operator[](int i);
	const char& operator[](int i) const;

	int length();
	bool empty();
	void print(ostream& out = cout) const;
	void clear();
	String& append(const String& str);
	String& append(const char* s);

private:
	char* value;
};

ostream& operator<<(ostream& out, const String& value);
String operator+(const String& lhs, const String& rhs);