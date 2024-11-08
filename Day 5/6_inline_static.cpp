// C++17 inline static 

// Object.h
class Object
{
public:
	static int data;

	// inline static : static ��������� �ܺμ����� �ʿ� ����.
	//					C++17
	inline static int data2 = 0;
};

// Object.cpp 
int Object::data = 0;	// static ������ �ܺμ�����
// �ݵ�� �ҽ� �ʿ� �־�� �մϴ�.
// �ᱹ "���������� ���� ����" �Դϴ�.
// ����� ������ ���������� include �ÿ�
// ���������� ������ �ִ� �Ͱ� ����

int main()
{

}