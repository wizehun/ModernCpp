// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>
//#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	//int v[5] = { 1,2,3,4,5 };

	// 반복자를 꺼내는 방법

	// #1. C++98 시절
	// 컨테이너 변경 시 코드 수정해야 함 (사용하지 마세요)
	std::vector<int>::iterator p1 = v.begin();
	std::vector<int>::iterator p2 = v.end();

	// #2. C++11, auto
	// raw array 이면 에러 발생 (멤버함수 begin, end)
	auto p1 = v.begin();
	auto p2 = v.end();

	// #3. C++11, 멤버함수 begin이 아닌 일반함수 begin
	// v가 컨테이너 뿐 아니라 배열도 가능
	auto p1 = std::begin(v);
	auto p2 = std::end(v);

	// #4. C++20, 새로운 begin
	// "std::ranges" 라는 namespace 안에 있음
	auto p3 = std::ranges::begin(v);
	auto p4 = std::ranges::end(v);

	// 왜 새로운 것이 나와야 하나요 ??
	auto p5 = std::begin(std::string("hello"));
						// 임시 객체 (이 문장의 끝에서 파괴됨)
						// 반환된 p5 는 절대 사용하면 안된다.
	auto p6 = std::ranges::begin(std::string("hello"));
						// 컴파일 에러
						// 즉, 인자가 임시객체라면 에러가 발생한다.
						// (그 외에도 장점들이 있다)

}
