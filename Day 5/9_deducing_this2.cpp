#include <iostream>

struct Point
{
	int x = 0;
	int y = 0;

	void set(int a, int b)
	{
		x = a;
		y = b;
	}

	void print() const
	{
		std::cout << x << std::endl;
	}
};

int main()
{
	const Point pt;

	pt.x = 10;		// error. x�� public ������ pt�� �����ü�̹Ƿ�
	pt.set(10, 20);	// error. set(&pt, 10, 20)
	pt.print();		// error. print(&pt) 
						// (�ٲٴ� �͵� ���µ�?)
						// => ���� Ŭ���� ���ο����� ���� �� (�ٲٴ��� ���� ��)
						// => �������� : this ��ġ�� &pt�� �Ѿ (const�� �ѱ� �� ����)
}

// �����ü�� ��� ��� �Լ��� ȣ�� �����մϴ�.
// 
// C++���� ��� ��ü�� ���� �θ� ���˴ϴ�.
// => �Լ� ���ڰ� "const Point&" �� �ʹ� �����ϴ�.

// ��� �Լ��� ���� �������� ������ �ݵ�� ��� ��� �Լ��� �ؾ� �մϴ�.