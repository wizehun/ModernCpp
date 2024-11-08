#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<std::string> v = { "A", "BBB", "CC" };

	std::sort(v.begin(), v.end());	// ���ڿ� ��ü�� < �����ڷ� ��
									// ��, ��������

	// ���������� �ƴ� "���ڿ� ���� ����"�� �����ϰ� �ʹ�.

	// C++98 : �� ��å���� "���� �Լ� ����"
	// => �׷���, 2���� ���ڸ� ���� ����(size()�Լ�) �� ��
	std::sort(v.begin(), v.end(),
		[](const std::string& s1, const std::string& s2) { return s1.size() < s2.size(); });
	
	// ���̽��� sort()�� �� ��å���� �����Լ��� �޴´�!!

	// C++20 : ���װ� ������ ��� �޴´�..
	//		   ���� : �� ���
	//		   ���� : projection (�� ������ ������Ų��)
	std::ranges::sort(v, std::less<int>{}, [](const std::string& s) { return s.size(); });
}