#ifndef B_H
#define B_H
#include "a.h"
class B
{
public:
    void set_val(int val)
    {
        A::set_val(val);
    }

};
#endif // B_H
