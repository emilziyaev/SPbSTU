#pragma once

#include"abc.h"
#include<iostream>
class vector
{
public: /*private:*/
	abc* vec;
	int sz;
public:
	vector(int = 100);
	vector(vector&);
	~vector();
	vector & operator=(const vector&);

	const void print();

	inline int size()const { return sz; }
	abc& operator [](int a); 
	inline abc& elem(int i)const { return vec[i]; }; 

	vector operator+(vector&);
};
vector operator-(vector& a, vector& b);
void error(char p);

