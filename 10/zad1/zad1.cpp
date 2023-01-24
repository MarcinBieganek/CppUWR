#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    vector<double> numbers;

    istream_iterator<double> doubleReader(cin);
    istream_iterator<double> doubleReaderEOF;


    while (doubleReader != doubleReaderEOF) {
        numbers.push_back(*doubleReader);

        ++doubleReader;
    }

    double mid = (double) accumulate(numbers.begin(), numbers.end(), 0.0) / (double) numbers.size();

    double o = accumulate(numbers.begin(), numbers.end(), 0.0, [mid](double acc, double e){
        return acc + pow(e - mid, 2.0);
    });

    o = o / (double) numbers.size();
    o = sqrt(o);

    for(auto p : numbers) {
        cout << p << endl;
    }

    cout << "Mid: " << setprecision(3) << mid << endl;
    cout << "Odchylenie standardowe: " << setprecision(3) << o << endl;

  	return 0;
}