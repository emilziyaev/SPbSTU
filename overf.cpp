#include "overf.h"
#include<iostream>
#include "abc.h"
overf::overf(int mant, int exp, bool flag) : abc(mant, exp)
{
	this->flag = flag;
	if (abs(this->integer) >= 1000) { this->flag = 1;if (this->integer > 0) this->integer = 999; else this->integer = -999; }
}

overf::overf(abc x, bool flag) :abc(x)
{
	this->flag = flag;
	if (abs(this->integer) >= 1000) { this->flag = 1; if (this->integer > 0) this->integer = 999; else this->integer = -999; }
}

overf::overf():abc()
{
	flag = 0;
}

void overf::print()
{
	if (this->flag == 1) std::cout << "* ";
	abc::print();
}

overf operator-(overf a, overf b)
{
	return overf(abc(a) - abc(b), a.flag + b.flag);
}
overf operator+(overf a, overf b)
{
	return overf(abc(a) + abc(b), a.flag + b.flag);
}
overf operator*(overf a, overf b)
{
	return overf(abc(a) * abc(b), a.flag + b.flag);
}

