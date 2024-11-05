#include <iostream>
#include <string>

// max �� ����� ���ô�.
// => C++ ǥ���� max �� �Ʒ��� ������ ����Դϴ�.
template<typename T>
const T& Max(const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "abc";
	std::string s2 = "efg";

	std::string s3 = Max(s1, s2); // ok. ��, s3�� s2�� ���纻
	const std::string& s4 = Max(s1, s2); // ok. s4�� s2�� ����

	// 
	const std::string& s5 = Max(std::string("ab"), std::string("ef"));

	// s5�� ����ص� �����ұ�� ?
	// => �ӽð�ü�� �������� ���� const& �� ���ؼ��� �����մϴ�.
	// => Max ȣ�� �����Ŀ��� �ӽð�ü�� ��� �ı� �˴ϴ�.
	// => s5 �� dangling �Դϴ�.

	// cppreference.com ���� std::max �˻�
}