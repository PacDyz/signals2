// signals2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/signals2.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace boost::signals2;

template <typename T>
struct return_all
{
	typedef T result_type;

	template <typename InputIterator>
	T operator()(InputIterator first, InputIterator last) const
	{
		return T(first, last);
	}
};

int main()
{
	signal<int(), return_all<std::vector<int>>> s;
	s.connect([] { return 1; });
	s.connect([] { return 2; });
	s.connect([] {return 5; });
	s.connect([] {return 0; });
	std::vector<int> v = s();
	std::cout << *std::min_element(v.begin(), v.end()) << '\n';
	for (const auto& itr : v)
		std::cout << itr << std::endl;
}

