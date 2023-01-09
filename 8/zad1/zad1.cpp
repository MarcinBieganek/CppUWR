#include <iostream>
#include <vector>
#include <complex>
#include <numeric>

using namespace std;

complex<double> polynomial(vector<complex<double>> pol, complex<double> z) {
    return accumulate(pol.begin(), 
                    pol.end(), 
                    complex<double> (0.0, 0.0), 
                    [z](complex<double> acc, complex<double> elem) {
                        return (acc * z) + elem;
                    });
}

int main() {

    vector<complex<double>> v = {complex<double> (2.0, 1.0), complex<double> (1.0, 0.0), complex<double> (-10.0, -5.0)};
    complex<double> z(2.0, 2.0);

    cout << "polynomial parameters:" << endl;
    for(auto p : v) {
        cout << p << endl;
    }
    
    complex<double> res = polynomial(v, z);

    cout << "result:" << endl;
    cout << res << endl;

  	return 0;
}