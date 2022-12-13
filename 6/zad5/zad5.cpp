#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

vector<string> perms(string s) {
    vector<string> res;
    do {
        res.push_back(s);
    } while(next_permutation(s.begin(), s.end()));

    return res;
}

int main() {
	string text = "abc";

    vector<string> textPerms = perms(text);

    for(auto p : textPerms) {
        cout << p << endl;
    }

  	return 0;
}