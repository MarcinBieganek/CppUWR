#include <iostream>

enum Names : uint16_t {John, Adam, Anna, Marta};

void printInfo(std::string info, Names name)
{
	switch (name)
	{
	case John:
		std::cout << "Hi John, " << info << std::endl;
		break;

	case Adam:
		std::cout << "Hi Adam, " << info << std::endl;
		break;

	case Anna:
		std::cout << "Hi Anna, " << info << std::endl;
		break;
	
	case Marta:
		std::cout << "Hi Marta, " << info << std::endl;
		break;
	
	default:
		std::cout << "Hi, " << info << std::endl;
		break;
	}
}

int main()
{
	printInfo("info number 1", Marta);
	printInfo("info number 2 and 3", Adam);
	
	return 0;
}