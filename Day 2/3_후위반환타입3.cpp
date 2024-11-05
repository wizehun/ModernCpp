#include <iostream>

// �Ʒ� 3���� �������� ������ ���ô�.
// Mul1    : C++11 ���� ����
// Mul2, 3 : C++14 ���� ����


// #1. ������ȯŸ�� ���
// => �Լ� ������� ���� (����ڰ� Ȯ���ϰ� �������)
template<typename T1, typename T2>
auto Mul1(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

// #2. �����Ϸ����� ��ȯ Ÿ���� �߷��� �޶�� ��
// => return ������ ���� �߷� (return ������ 2�� �̻��̸� ����)
// => ��Ģ�� auto ��Ģ (���ϰ��� "����"���� �� Ÿ�� ��ȯ)
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b)
{
	if (a == 0) return 0; // �� �ڵ尡 ������ error
	return a * b;
}

// #3. ���� ���������� ��Ģ�� decltype�� ������ ��
// => auto�� �ƴ� decltype ��Ģ (���ϰ��� "����"��� ���� ��ȯ)
template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b)
{
	return a * b;
}


int main()
{


}
