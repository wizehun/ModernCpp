#include <iostream>

template<typename T> void foo(T& a)
{
	a = 100;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);		// T = int,			a : int& 
	foo(c);		// T = const int	a : const int&
	foo(r);		// T = int			a : int& 
	foo(cr);	// T = const int	a : const int&
}
