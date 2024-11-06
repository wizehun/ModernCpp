#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

// �Լ�     : ���۸� �ִ�.
// �Լ���ü : ���۰� ����(�������)�� �ִ�.
//			  "���¸� ������ �Լ�"

struct IsDivide
{
	int value;
	IsDivide(int v) : value(v) {}

	bool operator()(int n) { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 0;
	std::cin >> k;

	IsDivide f(k);  // f�� k�� ���� (ĸó) 
					// f�� ��ü���� ���ڰ� �Ѱ��� �����Լ�ó�� ��� ����

	bool b = f(10); // 10 % k == 0 

	// �� �ѹ��� ����Ѵٸ� "�ӽð�ü" ���·� �ϸ� ���ϴ�.
	auto p2 = std::find_if(v.begin(), v.end(), IsDivide(k) );
							// ���������� : IsDivide(k)
							// �����Լ� + k ���� ���� �����ϴ� �ǹ�
}


// Closure : ���ƿ� ���� ���������� ĸ���Ҽ� �ִ� �Լ� (��ü)
//			 C++�� �ƴ�, �������� ���α׷��� ���

// �Ϲ��Լ� : Closure�� �� �� ����.
// �Լ���ü : Closure�� �� �� �ִ�.

