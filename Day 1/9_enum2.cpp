
// C/C++98 enum
//enum COLOR { red = 0, green = 1, blue = 2 };

// C++11 �� ���ο� enum
enum class COLOR { red = 0, green = 1, blue = 2 };

int main()
{
	int n1 = red;			// error. COLOR ǥ���ؾ� �Ѵ�.
	int n2 = COLOR::red;	// error. int Ÿ���� �ƴϴ�.

	COLOR n3 = COLOR::red; // ok
}

// ������ ���ڷ� ������
void foo(int color) {} // C++98 
// COLOR::red �Ӿƴ϶� 100�� �������ֽ��ϴ�.

void foo(COLOR color) {} // C++11   COLOR�� ���� ����. ����!!

