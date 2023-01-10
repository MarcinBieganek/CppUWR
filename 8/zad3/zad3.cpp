#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <complex>
#include <numeric>
#include <math.h>
#include <fstream>

using namespace std;

complex<double> dzeta(complex<double> z, int n) {
    complex<double> res(1.0, 0.0);
    complex<double> one(1.0, 0.0);

    for(int i = 1; i <= n; i++) {
        complex<double> nth((double) i, 0.0);

        res += pow(one / nth, z);;
    }

    return res;
}

complex<double> third_dzeta(complex<double> z, int n) {
    complex<double> res(1.0, 0.0);
    complex<double> one(1.0, 0.0);
    complex<double> two(2.0, 0.0);

    for(int i = 1; i <= n; i++) {
        complex<double> nth((double) i, 0.0);

        res += pow(-one, nth + one) / pow(nth, z);
    }

    return (one / (one - pow(two, one - z))) * res;
}


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

complex<double> an_dzeta(complex<double> z) {
    complex<double> one(1.0, 0.0);
    complex<double> two(2.0, 0.0);
    complex<double> pi(M_PI, 0.0);

    cout << "start" << endl;

    return pow(two, z) *
            pow(pi, (z - one)) *
            sin((pi * z) / two) *
            gamma(one - z, 1000000) *
            an_dzeta(one - z);
}


vector<complex<double>> calc(double range, double dist) {
    vector<complex<double>> res = {};

    for(double i = -range; i <= range; i += dist) {
        //cout << "i: " << i << endl;
        //cout << "dzeta: " << dzeta(complex<double> (0.5, i), 100000) << endl;
        res.push_back(third_dzeta(complex<double> (0.5, i), 100000));
    }

    return res;
}

void writeFile(string filename, vector<complex<double>>& arr) {
    ofstream myfile;
    myfile.open(filename);
    myfile << "Real,Imag\n"; 
    for(int i = 0; i < arr.size(); i++) {
        myfile << arr[i].real() << "," << arr[i].imag() << "\n";
    }
    myfile.close();
}


int main() {
    vector<complex<double>> vals = calc(25.0, 0.01);

    writeFile("zad3v2.csv", vals);

  	return 0;
}