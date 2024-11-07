#include <iostream>
#include <algorithm>
#include <functional> 
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// �Ʒ� �ڵ忡 ���ؼ� ������ ������. ������ ã������
	// => sort() �Լ��� 3�� �����˴ϴ�.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });


	// �ٽ� : ����ǥ������ ������ ���Ǵ� ��� auto������ ��Ƽ� ����ϼ���
	// => �Ʒ� �ڵ�� sort �� �Ѱ� ����

	auto cmp = [](int a, int b) { return a < b; }; // Ÿ�԰���

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// ���� < ������ �ʿ� �ߴٸ� 
	// ���� ǥ���Ĵ�� std::less ����ص� �˴ϴ�.
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
}




