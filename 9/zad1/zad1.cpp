#include <iostream>
#include <regex>

using namespace std;


int main() {

    string input = "";
    
    cout << "Give date:" << endl;
    cin >> input;
    
    bool test = regex_match(input, regex("(([01][0-9])|(2[0-3])):([0-5][0-9])(:([0-5][0-9]))*"));

    string result = "false";
    if(test) result = "true";

    cout << "Test result: " << result << endl;

  	return 0;
}