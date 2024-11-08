// Step3. ��� ����Ÿ �����ϱ�

template<typename ... Ts>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Ts>
struct tuple<T, Ts...> : public tuple<Ts...>
{
	T value;

	tuple() = default;

	tuple(const T& value) : value(value) {}

	static constexpr int N = 1;
};


int main()
{
	//	tuple<> t0;						// ���� ����. primary template ���
	//	tuple<short> t1;				// short  ����
	//	tuple<double, short> t2;		// double ����
	tuple<int, double, short> t3;	// int ����
}
/*
struct tuple_no_argument {};

struct tuple_short : public tuple_no_argument
{
	short value;
};
struct tuple_double : public tuple_short
{
	double value;
};
struct tuple_int : public tuple_double
{
	int value;
};

tuple_int t3; // 3���� value
*/