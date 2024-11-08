#include <iostream>

int  hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : e1, e2, e3

	goo(args);		// error. pack을 직접 인자로 사용할 수 없다.

	// pack expansion
	// => pack 안의 모든 요소를 , 를 사용해서 열거하는 기술
	// [1] "pack이름"...			=> e1, e2, e3
	// [2] "pack이름사용패턴"...	=> e1패턴, e2패턴, e3패턴

	goo(args...);	   // goo(e1, e2, e3) 콤마로 연결해줌
	goo((++args)...);  // goo(++e1, ++e2, ++e3) 각 요소에 패턴 적용
					   // () 없어도 됨 "goo(++args...)"
	goo(hoo(args)...); // goo(hoo(e1), hoo(e2), hoo(e3)
}


int main()
{
	foo(1, 2, 3);
}
