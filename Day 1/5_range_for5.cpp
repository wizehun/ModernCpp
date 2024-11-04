#include <iostream>
#include <vector>
#include <ranges> // C++20 에서 도입되는 다양한 view (시각) 들 ...

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 아래 모든 코드는 "데이터의 복사본"을 만들지는 않는다.
	// 단지 시각(view) 만 제공한다.
	// 중첩이 된다는 것이 핵심
	std::ranges::take_view tv(v, 3);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 1; });
	std::ranges::reverse_view rv(fv);

	// 아래 코드는 위 코드와 동일합니다. (operator | 연산자 재정의로 만든 것)
	auto rv = v | std::views::take(3)
				| std::views::filter([](int n) { return n % 2 == 1; })
				| std::views::reverse;

	for (auto& n : tv)
	{
		std::cout << n << std::endl;
	}
}

