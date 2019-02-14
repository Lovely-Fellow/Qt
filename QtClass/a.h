#ifndef A_H
#define A_H
class A
{
    static int a;
public:
    static void set_val(int val)
    {
        a = val;
    }
    static int get_val()
    {
        return a;
    }
};
#endif // A_H
