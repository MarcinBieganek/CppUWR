#include <iostream>
#include <cmath>

void equation(float a, float b, float c)
{
	if(float delta = b * b - (4 * a * c); delta > 0.0)
	{
		float xOne = (-b - std::sqrt(delta)) / (2 * a);
		float xTwo = (-b + std::sqrt(delta)) / (2 * a);
		std::cout << "x1: " << xOne << " x2: " << xTwo << std::endl;
	} else if (delta == 0.0) {
		float xOne = (-b) / (2 * a);
		std::cout << "x: " << xOne << std::endl;
	} else {
		std::cout << "No x1 and x2" << std::endl;
	}
	
}

int main()
{
	equation(1.0, 2.0, 1.0);
	equation(1.0, 4.0, 3.0);

	return 0;
}