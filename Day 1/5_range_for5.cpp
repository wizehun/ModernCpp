#include <iostream>
#include <vector>
#include <ranges> // C++20 ���� ���ԵǴ� �پ��� view (�ð�) �� ...

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �Ʒ� ��� �ڵ�� "�������� ���纻"�� �������� �ʴ´�.
	// ���� �ð�(view) �� �����Ѵ�.
	// ��ø�� �ȴٴ� ���� �ٽ�
	std::ranges::take_view tv(v, 3);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 1; });
	std::ranges::reverse_view rv(fv);

	// �Ʒ� �ڵ�� �� �ڵ�� �����մϴ�. (operator | ������ �����Ƿ� ���� ��)
	auto rv = v | std::views::take(3)
				| std::views::filter([](int n) { return n % 2 == 1; })
				| std::views::reverse;

	for (auto& n : tv)
	{
		std::cout << n << std::endl;
	}
}

