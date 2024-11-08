#include <vector>

class Object
{
	int data = 0;
public:
	// �Լ��� & �� ��ȯ�ϸ� "�Լ� ȣ���� �캯�� ������ �ֽ��ϴ�."
	// => �����̸��� "����", "���" ��� �Լ��� ���ÿ� ����� �ֽ��ϴ�.

	// �����ü : ��� �Լ��� ȣ�� ����
	// 
	// ������ü : 1. ���� �Լ� ȣ��.
	//              2. ���ٸ� ������ �Լ� ȣ��

	int& get() { return data; }
	const int& get() const { return data; }
};

int main()
{
	Object obj;

	int n1 = obj.get();
	obj.get() = 0;


	const Object cobj;

	int n2 = cobj.get();
	cobj.get() = 0;   // �����ü�̹Ƿ� �ȵž� �մϴ�.

	//-------------------------------------------------
	std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	auto p1 = v1.begin();
	auto p2 = v2.begin();

	*p1 = 10; // �ž� �մϴ�.
	*p2 = 10; // �ȵž� �մϴ�.
}