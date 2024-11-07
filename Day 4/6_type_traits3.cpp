#include <iostream>
#include <type_traits>

template<typename T> struct is_array
{
	static constexpr bool value = false;
	static constexpr int size = -1;
};

template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
	static constexpr int size = N;
};

template<typename T> void foo(T& a)
{
	if ( is_array<T>::value ) 
		std::cout << "배열" << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}
