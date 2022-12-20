#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <random>
#include <utility>

using namespace std;

template <typename T>
void shuff(vector<T>& arr) {
    default_random_engine generator(time(0));

    uniform_int_distribution<int> distribution(0, arr.size() - 1);

    for(int i = arr.size() - 1; i > 0; i--) {
        int j = distribution(generator);

        swap(arr[i], arr[j]);
    }
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(auto p : v) {
        cout << p << endl;
    }

    shuff<int>(v);

    cout << "After shuffle" << endl;
    for(auto p : v) {
        cout << p << endl;
    }

  	return 0;
}