// 9_deducing_this1
#include <iostream>

// C++23 ���� "1��°" �� �̾߱�Ǵ� ��ȭ!!
// => deducing this ����

struct Point
{
	int x = 0;
	int y = 0;
	
	// C++23 ���� �Ʒ��� ���� �Ϲ����� ��� �Լ��� 
	// "implicit object parameter"
	void set1(int a, int b)	// void set1( Point* this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;  // this->y = b;
	}

	// C++23 : explicit object parameter ��� �Ҹ��� ����
	void set2(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}
};

int main()
{
	Point pt;
	pt.set1(1, 2); // ������ �ϸ� set1(&pt, 1, 2) �� �˴ϴ�.
	pt.set2(1, 2); // set2(pt, 1, 2)
}