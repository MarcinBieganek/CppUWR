#include <iostream>
#include <set>

using stringSet = std::set<std::string>;

int main()
{
	stringSet stringSet = {"one", "two", "three"};

	for (auto string : stringSet)
	{
		std::cout << string << std::endl;
	}
	

	return 0;
}