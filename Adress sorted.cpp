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
    Adress(string city, string street, int house, int flat)
        : _city{ city }, _street{ street }, _house{ house }, _flat{ flat } {
    }

    string getCity() const {
        return _city;
    }

    string getOutputString() const {
        return _city + ", " + _street + ", " + to_string(_house) + ", " + to_string(_flat);
    }
};

void sortedFile(Adress* adresses, int counter) {
    for (int i = 0; i < counter - 1; ++i) {
        for (int j = 0; j < counter - i - 1; ++j) {
            if (adresses[j].getCity() < adresses[j + 1].getCity()) {
                swap(adresses[j], adresses[j + 1]);
            }
        }
    }
}

void processAdresses(int counter, ifstream& intxt, ofstream& outtxt) {
    Adress* adresses = new Adress[counter];

    // Чтение адресов из файла
    for (int i = 0; i < counter; i++) {
        string city, street;
        int house, flat;
        intxt >> city >> street >> house >> flat;
        adresses[i] = Adress(city, street, house, flat);
    }

    // Сортировка адресов по городам
    sortedFile(adresses, counter);

    // Запись отсортированных адресов в файл
    for (int i = counter - 1; i >= 0; i--) {
        outtxt << adresses[i].getOutputString() << endl;
    }

    delete[] adresses;
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream intxt("C:\\Users\\katen\\Documents\\in.txt");
    ofstream outtxt("C:\\Users\\katen\\Documents\\out.txt");

    if (!intxt.is_open()) {
        cout << "Ошибка открытия файла in.txt" << endl;
        return 1;
    }

    int counter;
    intxt >> counter;
    outtxt << counter << endl;

    processAdresses(counter, intxt, outtxt);

    intxt.close();
    outtxt.close();
    return 0;
}