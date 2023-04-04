#include <iostream>
#include <string>
using namespace std;
int j = 1; //Election name counter
struct Election
{
	int ID;
	string Name;
	string Description;
	string Nominees[100];
} Election[100];
int inputElection()
{
	int result = j;
	int size; // nominees size
	char answer;
	do
	{
		cout << "Enter Election name:" << endl;
		cin >> Election[j].Name;

		cout << "Enter Election description:" << endl;
		cin >> Election[j].Description;

		Election[j].ID = 100000 + j;
		cout << "The ELection ID is: " << Election[j].ID << endl;
		j++;

		cout << "How many nominees do you want to register?" << endl;
		cin >> size;

		cout << "Enter nominees names" << endl;
		for (int i = 0; i < size; i++) //nominees input
		{
			cin >> Election[j].Nominees[i];
		}

		cout << " Do you want to add more elections? (y / n ) " << endl;
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	return result;
}

void displayElection()
{
	cout << "The registered elections and their candidates are: " << endl;

	for (int i = 1; i < j; i++)
	{
		cout << "Election name:\t" << Election[i].Name << '\t';
		cout << Election[i].Description << '\t';
		for (int k = 0; k < 6; k++) //nominees output
			cout << Election[i].Nominees[k] << endl;
	}
}
int main()
{
	inputElection();
	displayElection();
}