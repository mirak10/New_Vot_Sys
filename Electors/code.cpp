#include <iostream>
#include <string>
using namespace std;
int j = 1; //Electors name counter
struct Electors
{
	int ID;
	string Name;
	string Email;
	string Address;
	int PhoneNum;
} Electors[100];
int inputElectors()
{

	int result = j;
	char answer;
	do
	{
		cout << "Enter Electors name:" << endl;
		cin >> Electors[j].Name;

		cout << "Enter Electors Email:" << endl;
		cin >> Electors[j].Email;

		cout << "Enter Electors Address:" << endl;
		cin >> Electors[j].Address;

		cout << "Enter Electors Phone Number:" << endl;
		cin >> Electors[j].PhoneNum;

		Electors[j].ID = 20230000 + j;
		cout << "Your Elector's ID is: " << Electors[j].ID << endl;
		j++;

		cout << " Do you want to add more? (y / n ) " << endl;
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	return result;
}
void displayElectors()
{
	cout << "The registered voters are: " << endl;

	for (int i = 1; i < j; i++)
	{
		cout << "Voter #:\t" << Electors[i].ID << '\t';
		cout << Electors[i].Name << '\t';
		cout << Electors[i].PhoneNum << '\t';
	}
}
int main()
	{
		inputElectors();
		displayElectors();
	}