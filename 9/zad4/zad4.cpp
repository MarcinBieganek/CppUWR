#include <iostream>
#include <regex>

using namespace std;


int main() {

    string input = "";
    
    cout << "Give complex number:" << endl;
    getline(cin, input);
    
    bool test = regex_match(input, regex("\\(-?[0-9]+(\\.[0-9]+)?[\\+-][0-9]+(\\.[0-9]+)?[iI]\\)"));

    string result = "false";
    if(test) result = "true";

    cout << "Test result for \"" << input << "\": " << result << endl;

  	return 0;
}