#include <iostream>
#include <regex>

using namespace std;


int main() {

    smatch m;
    smatch mhref;
    string input = "";
    
    while(getline(cin, input)) {
    
      bool test = regex_search(input, m, regex("<a[ a-zA-Z0-9\"\\\\/\\+-=\\.]+href=\"[ a-zA-Z0-9\\\\/\\+-=\\.]+\"[ a-zA-Z0-9\"\\\\/\\+-=\\.]*>"));

      if(test) {
        for (int i = 0; i < m.size(); ++i) {
          //cout << m.str(i) << endl;

          bool testhref = regex_search(input, mhref, regex("href=\"[ a-zA-Z0-9\\\\/\\+-=\\.]+\""));

          if(testhref) {
            for (int j = 0; j < mhref.size(); ++j) {
              string href = regex_replace(mhref.str(j), regex("(href=\")|\""), "");

              cout << href << endl;
            }
          }
        }
      }
    
    }

  	return 0;
}