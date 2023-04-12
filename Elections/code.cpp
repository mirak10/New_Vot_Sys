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

int inputElection(int& size)
{
	int result = j;
	char answer;
	do
	{
		cout << "Enter Election name:" << endl;
		getline(cin, Election[j].Name);

		cout << "Enter Election description:" << endl;
		getline(cin, Election[j].Description);

		Election[j].ID = 100000 + j;
		cout << "The ELection ID is: " << Election[j].ID << endl;
		

		cout << "How many nominees do you want to register?" << endl;
		cin >> size;

		cout << "Enter nominees names" << endl;
		for (int i = 1; i <= size; i++) //nominees input
		{
			cin.ignore();
			getline(cin, Election[j].Nominees[i]);
			
		}
		j++;
		cout << " Do you want to add more elections? (y / n ) " << endl;
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	return result;
}

void displayElection()
{
	int n = 0;
	cout << "The registered elections and their candidates are: " << endl;

	for (int i = 1; i < j; i++)
	{
		
		cout << "Election name:\t" << Election[i].Name << '\t';
		cout << Election[i].Description << '\t';
		int inputElection(n);
		for (int k = 1; k <= n; k++) //nominees output
			cout << Election[i].Nominees[k] << endl;
	}
}
int main()
{
	int n;
	inputElection(n);
	displayElection();
}