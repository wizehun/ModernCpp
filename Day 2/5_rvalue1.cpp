﻿﻿// 4_rvalue - 87 page
int x = 0;

int  foo() { return x; }
int& goo() { return x; }

// lvalue : 등호의 양쪽에 모두 올수 있다.
//	=> 이름을 가지고 있고, 
//  => 단일식이 벗어나서도 사용가능.
//  => 주소 연산자로 주소를 구할수 있다.
//  => 참조를 반환하는 함수
//  => 문자열 리터럴
// 
// rvalue : 등호의 오른쪽에만 올수 있다.
//	=> 이름이 없다.
//  => 단일식에서만 사용가능.
//  => 주소 연산자로 주소를 구할수 없다.
//  => 값을 반환하는 함수
//  => 임시객체, 정수, 실수 리터럴

int main()
{
	int v1 = 10, v2 = 10;

	v1 = 20;	// ok.    v1 : 등호의 왼쪽에 올수 있다. lvalue
	10 = v1;	// error. 10 : 등호의 왼쪽에 올수 없다. rvalue
	v2 = v1;

	int* p1 = &v1;
	int* p2 = &10;

	foo() = 10; // error
	goo() = 10; // ok 

	//-----------------
	const int c = 10;

	c = 20; // error
	// c는 rvalue ? lvalue 
	// => "immutable lvalue"
	// => 단지 등호의 "왼쪽"에 올수 있느냐가 아니라
	// => "이름" 을 중요시 하세요. 그리고, 메모리가 존재하는가 ?

// rvalue 는 상수이다 ??? 아니다..!!
	Point(1, 2).x = 10;  // 이 코드는 에러지만
	Point(1, 2).set(10, 20); // 이 코드는 에러가 아니다.
	// 단지 문법적으로 왼쪽에 못올뿐
	// 상수는 아니다.
}








