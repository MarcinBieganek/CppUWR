#include <iostream>
#include <regex>

using namespace std;


int main() {

    string input = "";
    
    cout << "Give date:" << endl;
    cin >> input;
    
    bool test = regex_match(input, regex("(((0[1-9])|(1[0-9])|(2[0-8]))-((0[1-9])|(1[0-2]))-[0-9]{4})|(((0[1-9])|([12][0-9])|(30))-((0[469])|(11))-[0-9]{4})|(((0[1-9])|([12][0-9])|(3[01]))-((0[13578])|(12))-[0-9]{4})"));

    string result = "false";
    if(test) result = "true";

    cout << "Test result: " << result << endl;

  	return 0;
}