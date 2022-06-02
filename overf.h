#pragma once
#include "abc.h"
class overf :
    public abc
{
private:
    bool flag;

public:
    overf(int mant, int exp, bool flag);
    overf(abc x, bool flag);
    overf();
    void print();
    friend  overf operator+ (overf, overf);
    friend  overf operator- (overf, overf);
    friend  overf operator* (overf, overf);
    friend  overf operator/ (overf, overf);

};

