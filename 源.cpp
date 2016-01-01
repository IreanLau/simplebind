#include <iostream>
using namespace std;

#include <boost/bind.hpp>
using namespace boost;


class Cmp
{
public:
	bool operator()(int a, int b)
	{
		return a > b ;
	}
};

void func(int i)
{
	cout << "func->" << i << endl;
}

void test()
{
	bind(func,_1)(10);
	Cmp objc;
	bool res = objc(8, 3);
	cout << res << endl;
}

void main()
{
	test();
}