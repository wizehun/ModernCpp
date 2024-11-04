// 8_nullptr2
#include <iostream>

void foo(int* p) {}

int main()
{
	int n = 0;
	foo(0);	// ok
	foo(n);	// error.
				// literal "0" 은 포인터로 암시적 변환되지만,
				// 0 으로 초기화 된 변수는 포인터로 변환할 수 없다.
}

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)
{
	f(arg);
}






