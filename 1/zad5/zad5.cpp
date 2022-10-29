#include <iostream>

auto Lucas(uint32_t n)
{
	switch (n)
	{
	case 0:
		return 2;
	case 1:
		return 1;
	
	default:
		return Lucas(n-1) + Lucas(n-2);
	}
}

int main()
{
	std::cout << "Lucas of 11: " << Lucas(11) << std::endl;

	return 0;
}