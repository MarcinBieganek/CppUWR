#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

vector<pair<const int, int>> theMostOccur(vector<int> l) {
    map<int, int> occurMap;
    for(auto i : l) {
        occurMap[i]++;
    }
    auto maxElem = max_element(occurMap.begin(), occurMap.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    });

    vector<pair<const int, int>> res;
    for(auto p : occurMap) {
        if(p.second == maxElem->second) {
            res.push_back(p);
        }
    }
    return res;
}

int main() {
	vector<int> li = {1, 1, 3, 5, 8, 9, 5, 8, 8, 5};

    cout << endl << "=======   After partition:   =================" << endl;
    
    vector<pair<const int, int>> m = theMostOccur(li);

    for(auto p : m) {
        cout << p.first << " , " << p.second << endl;
    }

  	return 0;
}