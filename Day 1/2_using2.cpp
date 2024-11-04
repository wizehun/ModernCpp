#include <unordered_set>

// std::unordered_set<int> 의 별명을 만들어 보자.
// #1. typedef
typedef std::unordered_set<int>		USET_I;
typedef std::unordered_set<double>	USET_D;

// "std::unordered_set<int>" 라는 타입의 별명이 아닌
// "std::unordered_set" 라는 template 의 별명을 만들 수 없을까?

typedef std::unordered_set USET; // error. 

// typedef	: 타입의 별명만 가능
// using	: 타입의 별명 + template의 별명

template<typename T>
using USET = std::unordered_set<T>;

int main()
{
	USET_I s1;
	USET_D s2;

	USET<int> s3;
	USET<double> s4;
}
