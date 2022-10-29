#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

struct Osoba {
    std::string nazwisko;
    std::string imie;
    int rokUrodzenia;
    bool operator<(const Osoba& o) const
    {
        return std::tie(nazwisko, imie, rokUrodzenia) < std::tie(o.nazwisko, o.imie, o.rokUrodzenia);
    }
};

int main()
{
	std::vector<Osoba> v;
	v.push_back({"Tom", "John", 1990});
	v.push_back({"Ane", "Jon", 1991});
	v.push_back({"Ane", "Jon", 2000});
	v.push_back({"Tom", "Bob", 1990});

	for (auto o : v)
	{
		std::cout << o.nazwisko << " " << o.imie << " " << o.rokUrodzenia << std::endl;
	}
	std::cout << std::endl;

	std::sort(v.begin(), v.end());
	
	for (auto o : v)
	{
		std::cout << o.nazwisko << " " << o.imie << " " << o.rokUrodzenia << std::endl;
	}

	return 0;
}