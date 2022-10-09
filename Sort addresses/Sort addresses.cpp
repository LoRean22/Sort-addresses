#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Address 
{
private:
	string townName;
	string streetName;
	int houseNum;
	int apartmentNum;

public:
	Address(string townName, string streetName, int houseNum, int apartmentNum) 
	{
		this->townName = townName;
		this->streetName = streetName;
		this->houseNum = houseNum;
		this->apartmentNum = apartmentNum;
	}
	Address() 
	{

	}

	string collectString() 
	{
		string string = townName + ", " + streetName + ", " + to_string(houseNum) + ", " + to_string(apartmentNum);

		return string;
	}

	void sort(string* stringArr, int size) 
	{
		for (int i = 0; i < size; ++i) 
		{
			for (int j = i + 1; j < size; ++j) 
			{
				if (stringArr[i] > stringArr[j]) 
				{
					string tempStorage = stringArr[i];
					stringArr[i] = stringArr[j];
					stringArr[j] = tempStorage;
				}
			}
		}
	}
};

int main() 
{
	ifstream in("in.txt");
	int size;
	in >> size;
	int count = size;

	string* stringArr = new string[size];
	if (in.is_open()) {
		while (!in.eof()) {
			string townName;
			string streetName;
			int houseNumber = 0;
			int apartmentNumber = 0;

			in >> townName >> streetName >> houseNumber >> apartmentNumber;

			Address addr(townName, streetName, houseNumber, apartmentNumber);
			string address = addr.collectString();

			stringArr[size - count] = address;

			--count;
		}
	}
	else 
	{
		cout << "Не удалось открыть файл!" << endl;
	}
	in.close();

	Address addr;
	addr.sort(stringArr, size);

	ofstream out("out.txt");
	out << size << endl;
	for (int i = 0; i < size; ++i) {
		string string = stringArr[i];
		out << string << endl;
	}
	out.close();

	delete[] stringArr;

	return 0;
}