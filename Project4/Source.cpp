#include <iostream>
#include <fstream>
using namespace std;
struct donors {
	
	string Surname;
	string Sex;
	int typeblood;
	char rhesusfactor;
};
int main() {
	int donor;
	string s;
	cout << "Print w-to write information about donors"<<endl;
	cout << "Print r-to read information about donors" << endl;
	cout << "Print w or r:" ;
	cin >> s;
	
	if (s == "w")
	{
		remove("INFO.DAT");
		ofstream INFO("INFO.DAT", ios::binary);
		cout << "Input number of donors: ";
		cin >> donor;
		for (int i = 0;i < donor;i++)
		{
			
			donors donor1;
			
			cout << "Input surname of donor: ";
			cin >> donor1.Surname;
			cout << "Input sex of donor(M/F): ";
			cin >> donor1.Sex;
			cout << "Input blood type of donor(1-4): ";
			cin >> donor1.typeblood;
			cout << "Input rhesus factor of donor(+ or -): ";
			cin >> donor1.rhesusfactor;
			INFO.write((char*)&donor1, sizeof(donor1));
		}
		INFO.close();
	}
	
	else if (s == "r")
	{
		int donors_number=0;
		donors* tmp = new donors[1];
		ifstream INFO("INFO.DAT", ios::binary);

		while (!INFO.eof())
		{
			INFO.read((char*)&tmp[0], sizeof(donors));
			donors_number++;
		}
		INFO.close();
		donors* arr = new donors[donors_number];
		
		ifstream INFO2("INFO.DAT", ios::binary);
		for (int i = 0;i < donors_number;i++)
		{
			INFO2.read((char*)&arr[i], sizeof(donors));
		}
		INFO2.close();

		for (int i = 0;i < donors_number;i++)
		{
			if (arr[i].typeblood == 1 && arr[i].rhesusfactor=='+')
			{
				cout <<"Surname of donor: " << arr[i].Surname << endl;
			}
		}
	}
	return 0;
}
