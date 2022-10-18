#include <iostream>


class A {

	public :
	typedef int col;
	static int y;
};

int main()
{
	typedef typename A::col rr;

	return 0;
}