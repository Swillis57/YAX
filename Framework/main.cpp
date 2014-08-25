#include <iostream>
#include <chrono>
#include "include/Utils.h"
using std::cout;
using std::cin;
using std::endl;
using namespace XNA;
//typedef __int64 i64;
using namespace std::chrono;
typedef duration<i64, std::ratio<1, 10000000>> Ticks;



class test
{
public:
	int i = 2;
	test() { cout << "ctor" << endl; }
	test(const test& t) { cout << "copy" << endl; }
	test(test&& t) { i = t.i; t.i = 0; cout << "move" << endl; }
};

void f(Nullable<float> t)
{
	float a2 = t.Value();
	cout << a2 << endl;
}

int main()
{
	test a {};
	f(2.5);
	
	cin.get();
}