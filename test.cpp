#include <iostream>
class vec {
    public:
        int a;
        int b;
        vec operator+ (vec &other);
};

vec vec::operator+(vec &other)
{
    vec temp;

    temp.a = other.a + a;
    temp.b = other.b + b;
    return (temp);
}

int main()
{
    vec v1;
    vec v2;
    vec v3 = v1 + v2;
}