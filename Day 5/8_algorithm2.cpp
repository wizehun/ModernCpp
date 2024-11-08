#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<std::string> v = { "A", "BBB", "CC" };

	std::sort(v.begin(), v.end());	// 문자열 자체를 < 연산자로 비교
									// 즉, 사전순서

	// 사전순서가 아닌 "문자열 길이 순서"로 정렬하고 싶다.

	// C++98 : 비교 정책으로 "이항 함수 전달"
	// => 그런데, 2개의 인자를 같은 연산(size()함수) 후 비교
	std::sort(v.begin(), v.end(),
		[](const std::string& s1, const std::string& s2) { return s1.size() < s2.size(); });
	
	// 파이썬은 sort()의 비교 정책으로 단항함수를 받는다!!

	// C++20 : 이항과 단항을 모두 받는다..
	//		   이항 : 비교 방법
	//		   단항 : projection (각 비교항을 투과시킨다)
	std::ranges::sort(v, std::less<int>{}, [](const std::string& s) { return s.size(); });
}