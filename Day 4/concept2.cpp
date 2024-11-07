#include <iostream>
#include <vector>
#include <type_traits>  
#include <concepts>

// C++20 ���� �����ϴ� �̹� ������� concept
// 1. concept ����� ���� �˾ƾ� �մϴ�.
// 2. �̹� ������� concept �� �ֽ��ϴ�.
// 3. template ���� �� concept �� �����ϴ� �͸� ����ϰ� �� �� �ֽ��ϴ�.

// concept �Ǵ� traits ó�� ���� ����
template<typename T> requires std::input_iterator<T>
void foo(T a)
{
}

// ���� �����ѵ� concept�� ���ؼ� �����ϰ� ���� (traits �Ұ�)
template<std::input_iterator T>
void foo(T a)
{
}

// ���� �����ϰ�, concept�� �����ϰ�, T�� ��� ����
void foo(std::input_iterator auto a)
{
}

// �׷���, �Ʒ� �ڵ尡 "������ ���� ���ø�"�� �ȴ�.
void foo(auto a)
{
}
