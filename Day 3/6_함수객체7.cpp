#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };
	
	// std::sort() 는 모든 인자가 템플릿 입니다.
	// => 사용자가 전달한 인자에 따라서 함수가 생성된다는 의미

	// #1. 비교 정책으로 일반함수를 사용하는 경우
	// 장점 : 비교정책을 여러 번 교체해도 sort() 함수는 1개만 생성된다.
	//		  코드 메모리가 증가하지 않는다.
	// 단점 : 비교정책 함수의 인라인 치환이 되지 않는다.
	//		  느리다. (데이터 양이 많을 때 주의)

	std::sort(x, x + 10, cmp1);	// sort(int*, int*, bool(*)(int,int)) 인 함수를 생성
	std::sort(x, x + 10, cmp2);	// sort(int*, int*, bool(*)(int,int)) 인 함수를 생성

	//=======================================================================//

	// #2. 비교 정책으로 함수객체를 사용하는 경우
	// 장점 : 비교정책의 인라인 치환이 가능하다.
	//		  빠르다.
	// 단점 : 비교함수 객체를 여러 번 교체하면 sort() 도 여러 개 생성된다.
	//		  코드 메모리가 증가한다.

	Less f1;
	Greater f2;
	std::sort(x, x + 10, f1);	// sort(int*, int*, Less) 인 함수를 생성
	std::sort(x, x + 10, f2);	// sort(int*, int*, Greater) 인 함수를 생성
}