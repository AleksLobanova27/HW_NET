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