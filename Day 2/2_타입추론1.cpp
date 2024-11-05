// 20_타입추론1 - 69 page
// 타입 추론 문법

template<typename T>
void foo(T a)
{

}

int main()
{
	auto n = 3;		// int n = 3;
	
	decltype(n) d;	// () 안에 있는 표현식의 타입을 조사해달라
					// int d;
		
	foo(3);			// T = int
}

// type deduction(type inference, 타입추론, 타입 연역)
// => 주어진 표현식을 가지고 컴파일러가 타입을 
//    결정하는것

// 1. template
// 2. auto
// 3. decltype