#include <iostream>

// 아래 3개의 차이점을 생각해 봅시다.
// Mul1    : C++11 부터 가능
// Mul2, 3 : C++14 부터 가능


// #1. 후위반환타입 사용
// => 함수 제약사항 없음 (사용자가 확실하게 명시해줌)
template<typename T1, typename T2>
auto Mul1(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

// #2. 컴파일러에게 반환 타입을 추론해 달라는 것
// => return 문장을 보고 추론 (return 문장이 2개 이상이면 에러)
// => 규칙은 auto 규칙 (리턴값이 "참조"여도 값 타입 반환)
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b)
{
	if (a == 0) return 0; // 이 코드가 있으면 error
	return a * b;
}

// #3. 위와 동일하지만 규칙을 decltype을 따르는 것
// => auto가 아닌 decltype 규칙 (리턴값이 "참조"라면 참조 반환)
template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b)
{
	return a * b;
}


int main()
{


}
