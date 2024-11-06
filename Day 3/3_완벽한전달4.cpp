void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);	// ���� ���� ���� �ڵ� �Դϴ�.
	f(static_cast<int&>(arg)); // �� �ڵ嵵 �ᱹ ���� �����մϴ�.
								// ������嵵 �����ϴ�.
								// �����Ͻ� ���ŵ˴ϴ�.(�ʿ�����ڵ�)
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

// T&& �� ����ϸ�
// 1. �� 2���� �ڵ������Ҽ� �ִ�.
// 2. int �� �ƴ϶� ��� Ÿ�Կ� ���ؼ��� ����. 

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;
	// �Ʒ� �ڵ� ����� 
	// 1. ������ �Լ� ���
	// 2. ĳ���� �ڵ� �� ������ ������
	chronometry(foo, 10);	// T = int     T&& = int&&
	// chronometry( �Լ�������, int&& arg )
	// => static_cast< int&& >(arg) 

	chronometry(goo, n);	// T = int&     T&& = int& && => int&
	// chronometry( �Լ�������, int& )
	// => static_cast<  int&  > (arg)
	// => �ʿ���� ĳ���������� �־ ���� ����

}




