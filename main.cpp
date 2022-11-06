#include <iostream>
#include <vector>

using namespace std;


class A 
{
	public:
	int a = 1;
	A(){};
	void print(){cout << "A\n";}
};

class B : public A
{
	public:
	int b = 2;
	B(){};
	void print2(){cout << "b\n";}
};

int main()
{
	
	A *a = new A();

	B *b = reinterpret_cast<B *> (a);

	 b->print2();
	cout << b->a << "\n";

	// for(int i = 0; i < 5; i++)
	// {
	// 	string h;
	// 	h = string(ss[i][0].begin(), ss[i][0].end());
	// 	res += h;
	// }
	
	return 0;
}