#pragma once
#ifndef MYSET_H
#define MYSET_H
#include <iostream>
#include "MyVector.h"

using namespace std;

class MySet :public MyVector
{
public:
	MySet(const char* el = NULL) :MyVector(el) {}
	MySet(const MySet& v) :MyVector(v) {}


	friend ostream& operator<<(ostream& out, MySet& s);
	friend MySet operator+(MySet& s1, MySet& s2);
	friend MySet operator-(MySet& s1, MySet& s2);
	friend MySet operator*(MySet& s1, MySet& s2);

	bool operator==(MySet& s);
	MySet& operator+=(MySet& s);
	MySet& operator-=(MySet& s);
	MySet& operator*=(MySet& s);
	MySet& operator = (MySet& v);
	
	//void add_element(char* el);
	void delete_element( int n);
	bool is_element(const char* el);
};

#endif

