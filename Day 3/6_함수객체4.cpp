﻿// 3_함수객체4 -  137 page 제일 윗부분내용

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 기계어 코드 치환, 호출보다 빠르다.


	int(*f)(int, int) = &Add2;

	f(1, 2); // 호출 ? 치환 ?
}

// #1. inline 치환은 "컴파일 시간" 문법이다.
// #2. 인라인 함수라도, 함수 포인터에 담아서 사용하면 인라인 치환될수 없다.

// 함수 이름 으로 호출하면 인라인 치환가능
// 함수 주소를 사용해서 호출하면 인라인 치환 안됨

