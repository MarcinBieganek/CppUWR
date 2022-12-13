#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class Coordinates {
    public:
        float x;
        float y;
        Coordinates(float x1, float y1) {
            x = x1;
            y = y1;
        };
        string printfy() {
            return "[" + to_string(x) + " , " + to_string(y) + "]";
        }
};

class RGB {
    public:
        unsigned int red;
        unsigned int green;
        unsigned int blue;
        RGB(unsigned int r, unsigned int g, unsigned int b) {
            red = r;
            green = g;
            blue = b;
        };
        string printfy() {
            return "(" + to_string(red) + " , " + to_string(green) + " , " + to_string(blue) + ")";
        }
        float lumi() {
            return 0.3 * red + 0.59 * green + 0.11 * blue;
        }
};

class Point {
  	public:
    	string name;
        Coordinates position;
        RGB color;
        Point(): position(0.0, 0.0), color(0, 0, 0) {
            name = "";
        }
        Point(string n, Coordinates p, RGB c): position(p), color(c) {
            name = n;
        };
        string printfy() {
            return name + " " + position.printfy() + " " + color.printfy();
        }
};

void printList(list<Point> l) {
    for(auto p : l) {
        cout << p.printfy() << endl;
    }
}

int main() {
	list<Point> li = {
        Point("p1", Coordinates(0.5, 0.5), RGB(0, 0, 0)),
        Point("p2", Coordinates(1.0, 0.5), RGB(0, 255, 0)),
        Point("p3", Coordinates(2.0, 0.5), RGB(0, 0, 255)),
        Point("p4", Coordinates(-1.0, -1.0), RGB(100, 100, 0)),
        Point("p5", Coordinates(0.5, 3.0), RGB(0, 50, 10)),
        Point("p600000000", Coordinates(-2.0, 2.0), RGB(0, 50, 255)),
        Point("p7", Coordinates(-10.0, 11.0), RGB(54, 55, 100)),
        Point("p8", Coordinates(2.5, 2.1), RGB(100, 21, 255)),
        Point("p9", Coordinates(-20.0, -2.0), RGB(255, 255, 255)),
        Point("p10000000", Coordinates(10.0, 0.0), RGB(100, 100, 100)),
        Point("p11", Coordinates(0.5, 10.0), RGB(125, 140, 140)),
        Point("p12", Coordinates(-4.0, 1.0), RGB(80, 0, 0)),
        Point("p13", Coordinates(4.0, -1.0), RGB(0, 25, 10)),
        Point("p14", Coordinates(-11.0, 0.5), RGB(10, 10, 10)),
        Point("p15", Coordinates(-12.0, 0.5), RGB(100, 255, 0)),
        Point("p16", Coordinates(0.5, -14.0), RGB(10, 100, 255)),
        Point("p17", Coordinates(0.5, -10.0), RGB(150, 150, 255)),
    };

    printList(li);

    // delete names longer than 5
    li.erase(remove_if(li.begin(), li.end(), [](Point& p) {
                    return p.name.length() > 5;
                }),
                li.end());
    
    cout << endl << "=======   After delete:   =================" << endl;
    printList(li);

    // count I, II, III, IV part of plane
    int countI = count_if(li.begin(), li.end(), [](Point& p) {
                    return p.position.x > 0.0 && p.position.y > 0.0;
                });
    int countII = count_if(li.begin(), li.end(), [](Point& p) {
                    return p.position.x < 0.0 && p.position.y > 0.0;
                });
    int countIII = count_if(li.begin(), li.end(), [](Point& p) {
                    return p.position.x < 0.0 && p.position.y < 0.0;
                });
    int countIV = count_if(li.begin(), li.end(), [](Point& p) {
                    return p.position.x > 0.0 && p.position.y < 0.0;
                });

    cout << endl << "=======  After count:   =================" << endl;
    cout << "Number in I: " << countI << endl;
    cout << "Number in II: " << countII << endl;
    cout << "Number in III: " << countIII << endl;
    cout << "Number in IV: " << countIV << endl;

    // sort by lumination
    li.sort([](Point& p1, Point& p2) {
        return p1.color.lumi() < p2.color.lumi();
    });

    cout << endl << "=======   After sort:   =================" << endl;
    printList(li);

    // partition copy
    int countDark = count_if(li.begin(), li.end(), [](Point& p) {
                    return p.color.lumi() < 64.0;
                });

    list<Point> darkPoints = {};
    darkPoints.resize(countDark);

    list<Point> liPoints = {};
    liPoints.resize(li.size() - countDark);

    partition_copy(li.begin(), li.end(), darkPoints.begin(), liPoints.begin(), [](Point& p) {
                    return p.color.lumi() < 64.0;
                });

    cout << endl << "=======   After partition:   =================" << endl;
    cout << "count: " << countDark << endl;
    printList(darkPoints);

  	return 0;
}