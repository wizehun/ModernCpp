// 16_constexpr1

// 용도
// 1. constexpr 상수
// 2. constexpr 함수
// 3. constexpr if 문

// constexpr 상수이야기

// 프로그램에서 사용되는 상수의 2가지 의미
// #1. 컴파일 할 때 값을 알 수 있는 것
// #2. 실행 시 변경할 수 없는 것

int main()
{
	int n = 10;
	
	// const 는 (#2) 만 만족
	const int c1 = 10;
	const int c2 = n;	// 컴파일 할 때 c2 값을 알 수 없다.

	// 배열의 크기, 템플릿 인자는 컴파일 할 때 값을 알아야 한다.
	int arr1[10];	// ok
	int arr2[n ];	// error
	int arr3[c1];	// ok
	int arr4[c2];	// error
}

// C#
// const : 컴파일 시에 값을 알아야 한다.
// readonly : 값을 변경할수 없다.

// Rust
// const : 컴파일 시에 값을 알아야 한다.
// immut : 값을 변경할수 없다.

// C++11
// constexpr : 컴파일 할때 값을 알아야 한다.
// const     : 값을 변경할수 없다.