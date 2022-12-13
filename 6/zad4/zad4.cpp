#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>

using namespace std;

map<char, float> lettersOccur(vector<char> text) {
    vector<char> copy = text;

    transform(text.begin(), text.end(), text.begin(), [](char c){
        return tolower(c);
    });

    text.erase(remove_if(text.begin(), text.end(), [](char c) {
                    return !isalpha(c);
                }),
                text.end());

    map<char, int> occurMap;
    for(auto i : text) {
        occurMap[i]++;
    }

    int count = text.size();
    map<char, float> res;
    for(auto p : occurMap) {
        res[p.first] = (float)p.second / (float)count;
    }

    return res;
}

int main() {
    ifstream File("test.txt");
    vector<char> text;

    char c;
    while(File.get(c))
    {
        text.push_back(c);
    }

    File.close();

    auto hist = lettersOccur(text);
    for(auto p : hist) {
        cout << p.first << " : " << p.second << endl;
    }

  	return 0;
}