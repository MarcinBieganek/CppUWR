#include <iostream>

using namespace std;

int main()
{
	string rawString = R"del(Instytut Informatyki Uniwersytetu Wrocławskiego
Fryderyka Joliot-Curie 15
50-383 Wrocław
C:\Program Files
"(") "))()))")")del";

	cout << rawString << endl;

	return 0;
}