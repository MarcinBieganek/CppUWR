#include <iostream>
#include <vector>
#include <complex>
#include <numeric>

using namespace std;

complex<double> gamma(complex<double> z, int n) {
    complex<double> res(1.0, 0.0);
    complex<double> one(1.0, 0.0);

    for(int i = 1; i <= n; i++) {
        complex<double> nth((double) i, 0.0);

        complex<double> nom = pow(one + (one / nth), z);
        complex<double> den = (z / nth) + one;

        res *= (nom / den);
    }

    return (one / z) * res;
}

complex<double> rev_gamma(complex<double> z, int n) {
    complex<double> res(1.0, 0.0);
    complex<double> one(1.0, 0.0);
    complex<double> y(0.5772156649, 0.0);

    for(int i = 1; i <= n; i++) {
        complex<double> nth((double) i, 0.0);

        complex<double> second_half = exp(-(z / nth));
        complex<double> first_half = (z / nth) + one;

        res *= first_half * second_half;
    }

    return (z * exp(y*z)) * res;
}


int main() {
    complex<double> z(4.0, 2.0);
    
    complex<double> res = gamma(z, 10000000);

    cout << "result:" << endl;
    cout << res << endl;

    complex<double> rev_res = rev_gamma(z, 1000000);

    cout << "rev result: " << endl;
    cout << rev_res << endl;

  	return 0;
}