#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

class Person {
  	public:
    	string firstname;
        string lastname;
        unsigned int age;
        float weight;
        float height;
        Person(string fn, string ln, unsigned int a, float w, float h) {
            firstname = fn;
            lastname = ln;
            age = a;
            weight = w;
            height = h;
        };
        float Bmi() {
            return weight / (height / 100.0) * (height / 100.0);
        }
        string printfy() {
            return firstname + " " + lastname + " " + to_string(age) + " " + to_string(weight) + " " + to_string(height);
        }
};

void printDeq(deque<Person> deq) {
    for(auto p : deq) {
        cout << p.printfy() << endl;
    }
}

int main() {
	deque<Person> deq = {
        Person("Tomek", "Nazwisko", 20, 60, 171),
        Person("Tadek", "Ciasteczko", 24, 79, 176),
        Person("Ola", "Nazwisko", 21, 55, 160),
        Person("Ala", "Nazwisko", 19, 20, 162),
        Person("Ewa", "Agata", 26, 51, 162),
        Person("Tomek", "Kowalski", 29, 80, 180),
        Person("Marek", "Nazwisko", 40, 60, 155),
        Person("Radek", "Nowak", 21, 140, 190),
        Person("Wojtek", "Nak", 29, 69, 179),
        Person("Tomek", "Wojak", 50, 100, 182),
        Person("Tomek", "Ben", 16, 120, 170)
    };

    printDeq(deq);

    // sort by BMI
    sort(deq.begin(), deq.end(), [](Person& p1, Person& p2) {
        return p1.Bmi() < p2.Bmi();
    });

    cout << endl << "=======   After sort:   =================" << endl;
    printDeq(deq);

    // transform weight by 10%
    transform(deq.begin(), deq.end(), deq.begin(), [](Person& p) {
        p.weight *= 0.9;
        return p;
    });

    cout << endl << "=======   After transform:   =================" << endl;
    printDeq(deq);

    // partition by weight
    partition(deq.begin(), deq.end(), [](Person& p) {
       return p.weight > 100.0; 
    });

    cout << endl << "=======   After partition:   =================" << endl;
    printDeq(deq);

    // 5 person by height at 5 index
    nth_element(deq.begin(), deq.begin() + (deq.size() / 2), deq.end(), [](Person& p1, Person& p2) {
        return p1.height < p2.height;
    });

    cout << endl << "=======   After 5th element by height:   =================" << endl;
    printDeq(deq);

    // randomly shuffle first 5 and last 5 elements
    random_shuffle(deq.begin(), deq.begin() + (deq.size() / 2) - 1, [](int i) {
        return rand() % i;
    });
    random_shuffle(deq.begin() + (deq.size() / 2) + 1, deq.end(), [](int i) {
        return rand() % i;
    });

    cout << endl << "=======   After randomly shuffle:   =================" << endl;
    printDeq(deq);

  	return 0;
}