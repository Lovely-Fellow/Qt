#ifndef C_H
#define C_H
#include "a.h"
class C
{
public:
    int get_val()
    {
        return A::get_val();
    }

};
#endif // C_H
