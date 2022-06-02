#include "vector.h"

vector::vector(int s)
{
	if (s < 1) error('1');
	vec = new abc[s];
	sz = s;
}

abc& vector::operator[](int i)
{
	if (i < 0 || i >= sz) error('2');
	return vec[i];
}

vector::~vector()
{
	if (vec == 0) return;
	delete[]vec;
	vec = 0;
}

vector::vector(vector& a) :vector(a.size())
{
	for (int i = 0; i < size(); i++) 
	{
		elem(i) = a.elem(i);
	}
}

 vector & vector::operator=(const vector& a)
{
	if (a.size() != size()) {
		delete[] vec;
		sz = a.size();
		vec = new abc[sz];
	}
	
	for (int i = 0; i < size(); i++)
	{
		elem(i) = a.elem(i);
	}
	return *this;
}

const void vector::print()
{
	std::cout << "size = " << sz << std::endl;
	for (int i = 0; i < sz; i++) { elem(i).print();  }
	
}

vector vector::operator+(vector& a)
{
	if (size() != a.size()) error('4');
	vector sum(size());
	for (int i = 0; i < size() /*sz*/; i++)
	{
		sum.elem(i) = a.elem(i) + elem(i);
	}
	return sum;
}

vector operator-(vector& a, vector& b)
{
	if (a.size() != b.size()) error('5');
	int as = a.size();
	vector sub(as);
	abc* sp = sub.vec;
	abc* ap = a.vec;
	abc* bp = b.vec;
	while (as--) *sp++ = *ap++ - *bp++;
	return sub;
}

void error(char p)
{
	std::cout << p;
	exit(1);
}
