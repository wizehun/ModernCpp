// Step2. data �Ѱ� ���� �ϱ�

template<typename ... Ts>
struct tuple
{
	static constexpr int N = 0;
};

// ���ø� ���ڰ� �Ѱ� �̻��� ��츦 ���� �κ� Ư��ȭ
template<typename T, typename ... Ts>
struct tuple<T, Ts...>
{
	T value;

	tuple() = default;
	tuple(const T& value) : value(value) {}

	static constexpr int N = 1;
};


int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}