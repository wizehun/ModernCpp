#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<std::string> v = { "A", "CCC", "BB" };

	// C++20 �˰��� Ư¡ #1. �����̳� ���ް���
	// => std::ranges �̸�����

	std::sort(v.begin(), v.end());	// �ݵ�� �ݺ��ڷ� ������ �մϴ�.

	std::ranges::sort(v);
	std::ranges::sort(v.begin(), v.end());
}