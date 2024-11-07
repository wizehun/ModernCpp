#include <iostream>
#include <vector>
#include <type_traits>  
#include <concepts>

// C++20 에서 제공하는 이미 만들어진 concept
// 1. concept 만드는 법을 알아야 합니다.
// 2. 이미 만들어진 concept 이 있습니다.
// 3. template 만들 때 concept 를 만족하는 것만 사용하게 할 수 있습니다.

// concept 또는 traits 처리 가능 문법
template<typename T> requires std::input_iterator<T>
void foo(T a)
{
}

// 위와 동일한데 concept에 한해서 간단하게 가능 (traits 불가)
template<std::input_iterator T>
void foo(T a)
{
}

// 위와 동일하고, concept만 가능하고, T를 사용 못함
void foo(std::input_iterator auto a)
{
}

// 그래서, 아래 코드가 "제약이 없는 템플릿"이 된다.
void foo(auto a)
{
}
