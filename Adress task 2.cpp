#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Adress {
private:
    string _city;
    string _street;
    int _house;
    int _flat;

public:
    Adress() {}
    Adress(string city, string street, int house, int flat) : _city{ city }, _street{ street }, _house{ house }, _flat{ flat } {}

    string getOutputString() const {
        return _city + ", " + _street + ", " + to_string(_house) + ", " + to_string(_flat);
    }
};

void inFile(int counter, ifstream& intxt, ofstream& outtxt) {
    Adress* adresses = new Adress[counter];
    for (int i = 0; i < counter; i++) {
        string city, street;
        int house, flat;
        intxt >> city >> street >> house >> flat;
        adresses[i] = Adress(city, street, house, flat);
    }

    for (int i = 0; i < counter; i++) {
        outtxt << adresses[i].getOutputString() << endl;
    }

    delete[] adresses;
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream intxt("in.txt");
    ofstream outtxt("out.txt");

    if (!intxt.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    int counter;
    intxt >> counter;
    outtxt << counter << endl;

    inFile(counter, intxt, outtxt);

    intxt.close();
    outtxt.close();
    return 0;
} 