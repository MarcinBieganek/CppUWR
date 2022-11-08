#include <iostream>
#include <memory>
#include <fstream>

using namespace std;

class Line_writer {
  	public:
    	ofstream file;
		Line_writer() {
			file.open("file.txt", ios::out);
		}
    	virtual ~Line_writer() {
      		file.close();
			cout << "File closed." << endl;
    	}
};

int main() {
	auto lw = new Line_writer();

	shared_ptr<Line_writer> alw(lw);
	shared_ptr<Line_writer> blw(alw);
	shared_ptr<Line_writer> clw(blw);

	alw->file << "ALW !" << endl;
	blw->file << "BLW !" << endl;
	clw->file << "CLW !" << endl;


  	return 0;
}