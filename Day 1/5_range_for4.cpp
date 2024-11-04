// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

template<typename T>
class take_view
{
	T& c;
	int cnt;
public:
	take_view(T& c, int cnt) : c(c), cnt(cnt) {}

	auto begin() { return c.begin(); }
	auto end() { return c.begin() + cnt; }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	take_view tv(v, 3);

	for (auto& n : tv)
	{
		std::cout << n << std::endl;
	}
}

