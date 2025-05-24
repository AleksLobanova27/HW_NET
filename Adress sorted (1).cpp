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

	void outFile(Adress adress, ofstream& outtxt) {
		outtxt << adress._city << ", " << adress._street << ", " << adress._house << ", " << adress._flat << endl;
	}
    string getCity() const {
        return _city;
    }
	void sortedFile(Adress* adress, int counter) {
        for (int i = 0; i < counter - 1; ++i) {
            for (int j = 0; j < counter - i - 1; ++j) {
                if (adress[j].getCity() < adress[j + 1].getCity()) {
                    // Меняем местами адреса
                    Adress temp = adress[j];
                    adress[j] = adress[j + 1];
                    adress[j + 1] = temp;
                }
            }
        }
    }
public:
	Adress() {}
	Adress(string city, string street, int house, int flat) :_city{ city }, _street{ street }, _house{ house }, _flat{ flat } {}
	void inFile(int counter, ifstream& intxt, ofstream& outtxt) {
        Adress* adress = new Adress[counter];
        for (int i = 0; i < counter; i++) {
			string city, street;
			int house, flat;
			intxt >> city >> street >> house >> flat;
			adress[i] = Adress(city, street, house, flat);
		}
        sortedFile(adress, counter);
		for (int i = counter - 1; i >= 0; i--) {
			adress[i].outFile(adress[i], outtxt);
		}
		delete[] adress;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	ifstream intxt("C:\\Users\\katen\\Documents\\in.txt");
	ofstream outtxt("C:\\Users\\katen\\Documents\\out.txt");
	if (!intxt.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	int counter;
	intxt >> counter;
	outtxt << counter << endl;
    Adress adresses;
	adresses.inFile(counter, intxt, outtxt);
	intxt.close();
	outtxt.close();
	return 0;

}




