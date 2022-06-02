#include "abc.h"
#include <iostream>

abc::abc(double a)
{
	integer = int(a);
	frac = int((a - integer) * 1000);
}

abc::abc(int a, int b)
{
	integer = a;
	frac = b;
}



void abc::print()
{
	using namespace std;
	if (integer != 0) { cout << integer << '.' << abs(frac) << endl; }
	else if (frac > 0) { cout << "0." << frac << endl; }
	else if (frac < 0) { cout << "-0." << abs(frac) << endl; }
	else if (frac == 0) { cout << "0.0" << endl; }
}

abc operator+(abc one, abc two)
{
	one.frac += two.frac;
	if (one.frac > 999) {
		one.integer += two.integer+1;
		one.frac -= 1000;
	}
	else one.integer += two.integer;
	return abc(one.integer,one.frac);
}
abc operator-(abc one, abc two)
{
	if (abs(one.frac) >= abs(two.frac) && abs(one.integer)>=abs(two.integer)) {
		one.frac -= two.frac;
		one.integer -= two.integer;
		return abc(one.integer, one.frac);
	}
	if (abs(one.frac) < abs(two.frac) && abs(one.integer) > abs(two.integer)) {
		one.frac -= two.frac+1000;
		one.integer -= two.integer-1;
		return abc(one.integer, one.frac);
	}
	if (abs(one.frac) > abs(two.frac) && abs(one.integer) < abs(two.integer)) {
		two.frac -= one.frac - 1000;
		two.integer -= one.integer + 1;
		two.integer = -two.integer;
		two.frac = -two.frac;
		return abc(two.integer, two.frac);
	}
	if (abs(one.frac) <= abs(two.frac) && abs(one.integer) < abs(two.integer)) {
		two.frac -= one.frac ;
		two.integer -= one.integer;
		two.integer = -two.integer;
		two.frac = -two.frac;
		return abc(two.integer, two.frac);
	}	
}

abc operator*(abc one, abc two)
{
	int ff,ii,if1,if2;
	ff = abs(one.frac) * abs(two.frac) / 1000;
	ii = abs(one.integer) * abs(two.integer);
	if1 = abs(one.integer) * abs(two.frac);
	if2 = abs(one.frac) * abs(two.integer);
	ff = if1 + if2+ff;
	while (ff >= 1000) {
		ff -= 1000;
		ii += 1;
	}
	if ((one.integer < 0 && two.integer>0) || (one.integer > 0 && two.integer < 0) || (one.frac < 0 && two.frac>0) || (one.frac > 0 && two.frac < 0)) {
		if (ii != 0) {
		return abc(-ii, ff);
	}
		else {
			return abc(ii, -ff);
		}
	}
	else { return abc(ii, ff); }
	
}


