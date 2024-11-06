﻿#include <iostream>

// 람다표현식을 이해하려면 반드시 "함수객체"를 이해해야 한다.
// 함수객체 : C++98 부터 있던 기술

// function object(함수 객체)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

struct Plus
{
	int operator()(int a, int b) 
	{
		return a + b;
	}
};

int main()
{
	Plus p;				// p는 함수가 아닌 객체입니다.

	int n1 = p(1, 2);	// 객체인 p를 함수처럼 사용한다.
						// "함수객체"라고 한다.

	int n2 = p.operator()(1, 2); // 위 코드를 컴파일러가 이렇게 변경한다.
								 // 사용자가 직접 이렇게 해도 된다.
}

// 일반함수로 하면 되는데 ?? 왜 함수객체를 사용하나요 ??
// 1. 상태를 가지는 함수
// 2. 특정 상황에서 일반함수보다 함수객체가 빠릅니다.
// 3. ADL 회피 등...
// 많은 장점이 있습니다.

// C++98 : std::max() 는 함수
// C++11 : std::ranges::max() 는 함수가 아닌 함수객체
//		   std::ranges::begin() 도 함수객체
//         std::ranges::begin.operator()(컨테이너)