#pragma once
class abc
{
protected:
	int integer;
	int frac;
public:
	abc(double a = 0);
	abc(int, int);
	
	friend  abc operator+ (abc, abc);
	friend  abc operator- (abc, abc);
	friend  abc operator* (abc, abc);
	
	void print();
};

