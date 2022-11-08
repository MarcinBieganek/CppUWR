#include <iostream>
#include <memory>

using namespace std;

int n = 10;

class Counter {
  	public:
    	int counter = 1;
    	virtual ~Counter() {
      		cerr << "Counter destroyed: " << counter << endl;
    	}
};

unique_ptr<Counter[]> change(int m, unique_ptr<Counter[]> tab) {
	if (m == 0) return tab;

	srand((unsigned) time(NULL));

	for(int i = 0; i < n; i++) {
		if(rand() % 10 < 5) {
			tab[i].counter += m;
		}
	}

	return change((m - 1), move(tab));
}

int main() {
	auto tab = unique_ptr<Counter[]>(new Counter[10]);

	tab = change(10, move(tab));

	for(int i = 0; i < n; i++) {
		cout << tab[i].counter << endl;
	}

  	return 0;
}