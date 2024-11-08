#include <iostream>

template<typename ... Ts>
struct tuple
{
	static constexpr int N = 0;
};
template<typename T, typename ... Ts>
struct tuple<T, Ts...> : public tuple<Ts...>
{
	using base = tuple<Ts...>;

	T value;
	tuple() = default;
	tuple(const T& value, const Ts& ... args)
		: value(value), base(args...) {}

	static constexpr int N = base::N + 1;
};

int main()
{
	//	tuple<> t0;						// ���� ����. primary template ���
	//	tuple<             short> t1;	// short  ����
	//	tuple<     double, short> t2;	// double ����
	//	tuple<int, double, short> t3;	// int ����

	tuple<int, double, short> t3(1, 3.4, 'A');

	std::cout << t3.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t3).value << std::endl; // 3.4 ������ �غ�����

	std::cout << static_cast<tuple<short>&>(t3).value << std::endl; // 'A' ������ �غ�����

	// get �� ������ ���ô�.
	auto a = get<0>(t3);

	get<0>(t3) = 30;
}

template<int N, typename TP>
Ʃ��TPŸ���� N��° ����� Ÿ��&
get(TP& tp)
{
	return static_cast<TP�� N��° �θ� Ÿ��&>(tp).value;
}

// �� �ѱ��� �ڵ�� ����� �ϼ�!!
// => �ᱹ, Ÿ�� ���ϱ�!!!
// => TP �� N��° ��� Ÿ�� ���ϱ�
// => TP �� N��° �θ� Ÿ�� ���ϱ�