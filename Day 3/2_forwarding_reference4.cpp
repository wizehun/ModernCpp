// T&& �� �ǹ�
// => ���� �ϽǶ� �Ʒ� �ڵ带 �� ���� �ϼ���


// T&& : ���� Ÿ���� "lvalue, rvalue" �� ��� ������ �ִ�.

// ��� �޴� �ٴ� ���� "������ �ִ� �Լ��� ����" �Ҽ� �ִ�.
// => ��, �Ѱ��� �Լ��� �ƴ϶�, ������ �Լ��� ���� �Ѵ�.

// ���ڷ� int Ÿ����
// lvalue(n) ���� : T=int&   T&&=int&   f4(int&) 
// rvalue(3) ���� : T=int    T&&=int&&  f4(int&&)
// => �ᱹ, ������ �Լ��� call by value �� �ƴ� call by reference


// int&& : rvalue reference. "int"��� Ÿ���� ������ ��!!
// T&&   : ?			     ���ø� ���� "T" ���


// T&& �̸�
// effective c++ å����  "universal reference" �� ����
// ������, ǥ�� ����ȸ�� "forwarding reference" ��� �̸����� ����
// => perfect forwarding �Ҷ� ����ϰ� �ȴٴ� �ǹ�. 




template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;

	// #1. Ÿ���� ���� �����ϴ� ���
	f4<int>(3);		// T = int		T&& = int&&				f4(int&& a)
	f4<int&>(n);	// T = int&		T&& = int& &&  => int&	f4(int& a)
	f4<int&&>(3);	// T = int&&	T&& = int&& && => int&&	f4(int&& a)


	// #2. Ÿ���� �������� ���� ���(�ٽ�)
	// => �����Ϸ��� �Լ����ڸ� ���� T�� �����ؼ� �Լ��� �����Ѵ�!!
	f4(n);	// n �� int Ÿ��
	// T = int  �����ϸ� "f4(int&& a)" ����. f4(n) �� ����
	// T = int& �����ϸ� "f4(int& a)"  ����. f4(n) �� ���� �ƴ�. 
	// => �׷��� C++ ������ �� ��츸 T = int& �� �����ϱ�� ǥ�� ����

	f4(3);  // T = int �Ǵ� int&& �ϸ� ������ �ִµ�, 
	// ǥ�ؿ����� T=int �� ����
	// �����Լ� �� f4(int&& a)
}

void f1(T a) {}
void f2(T& a) {}
void f3(T&& a) {}

int n = 10;
f1(n); // T= int
f2(n); // T= int
f3(n); // T= int&   <== �̰�츸 �̷���!!