#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
int euler(int n)
{
    int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

int main(int argc, char** argv) {
    int k = 2;
    vector<int> numbers;
    ofstream fout("phi.txt");

    if (argc > 1) k = atoi(argv[1]);

    for (int i = 1; i <= k; i++)
        numbers.push_back(euler(i));
    
    copy(numbers.cbegin(), numbers.cend(), ostream_iterator<int>(fout, "; "));

  	return 0;
}