#include <string>

std::string foo()
{
	std::string s("abcd");
	return s;
}
int main()
{
	// �Ʒ� �ڵ�� �����Ѱ��� ?
	// => �����մϴ�. for �� ����� ���� temporary �ı��ȵ�
	for (auto e : std::string("abcd"))
	{
		// ... 
	}
	// �Ʒ� �ڵ�� �����Ѱ��� ?
	for (auto e : foo())
	{
		// ... 
	}
}