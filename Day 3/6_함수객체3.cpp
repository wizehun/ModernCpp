#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure. 상태를 가지는 함수

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	// find_if 의 3번째 인자 : 인자가 한개인 함수(단항함수)를 전달
	auto p1 = std::find_if(v.begin(), v.end(), foo);

	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 "k의 배수" 를 찾고 싶다.
	// => k 값도 전달을 해야하는데, ? 자리에는 인자 1개만 전달이 가능하다.
	// => 전역변수를 사용하는 것 외에는 방법이 없다.
	// ==>> 함수객체를 사용하면 쉽게 해결된다.
	auto p2 = std::find_if(v.begin(), v.end(), ? );
}



