#include<iostream>
#include<string>
#include<fstream>
#define num_electors 100
#define max_admin 5

int adminCount = 0;
int electorCount = 1;
int j = 5; //Election ID counter
using namespace std;


// elector's struct

struct Electorinfo
{
	string ID;
	string Name;
	string Password;
	string Email;
	string Address;
	string Phone;
	int ElectorCode;

}electors[100];// Elector's struct


// Struct for storing Election Administrator data
struct ElectionAdmin {
	string ID;
	string name;
	string password;
	string email;
	string address;
	string phone;
	int AdminCode;
	int numElections = 0; // Number of elections for this administrator
} admins[5];

// Election Struct

struct Election // Struct for storing Election  data
{
	int ID;
	string Name;
	string Description;
	string Nominees[100];
	int Votes[6] = {};
	int ElectionCode;
	int ElectionAdminCode;

	int AllowedVoters[10];

	bool Finished = false;

}Election[100];// an array of struct type for storing election data

void main_menu();
//admin privileges with respect to the election


int inputElection(int& size);
void displayElection();
void displayElection_only();
void edit_Election_Description(); //Admin edits the description of the selected election
void Edit_Nominee();//Admin edits the description of the selected election






// Administrator Function prototypes
bool login(ElectionAdmin admins[], int adminCount);
void editInfo();
void signup(ElectionAdmin admins[], int& adminCount);
void admin_page();
void end_election();
void admindisplayElection();
void FinishedElection();
void admin_login_signup(); // administrator login and signup function


// Elector's functions

bool Elector_login(Electorinfo electors[], int electorCount);          // a function for logging in
void Elector_signup(Electorinfo electors[], int& electorCount);  // a fuction for singing up
void Elector_edit_info();      // a funtion for editing infomation

void elector_login_signup();   //a fuction for both sign in and login
void elector_page();  // a function for editing information,viewing finished election and voting
void Electors_vote();
void displayVotes();


// the main function
int main()
{
	Election[0].ID = 100000;
	Election[0].Name = "Minister";
	Election[0].Description = "Finance and Planning";
	Election[0].Nominees[1] = "Adam Thomas";
	Election[0].Nominees[2] = "Wilson George";
	Election[0].Nominees[3] = "Yusuf Ahmed";
	Election[0].ElectionCode = 1;

	Election[1].ID = 100001;
	Election[1].Name = "Minister";
	Election[1].Description = "Sports and Culture";
	Election[1].Nominees[1] = "Sarah David";
	Election[1].Nominees[2] = "Leslie Charles";
	Election[1].Nominees[3] = "Mark Johnson";
	Election[1].ElectionCode = 1;
	Election[1].ElectionAdminCode = 911;

	Election[2].ID = 100002;
	Election[2].Name = "Minister";
	Election[2].Description = "Internal Affairs";
	Election[2].Nominees[1] = "Francis Jacob";
	Election[2].Nominees[2] = "Wendy Williams";
	Election[2].Nominees[3] = "Darla McCarther";
	Election[2].ElectionCode = 2;

	Election[3].ID = 100003;
	Election[3].Name = "Minister";
	Election[3].Description = "Foreign Affairs";
	Election[3].Nominees[1] = "Naomi Peter";
	Election[3].Nominees[2] = "Edward George";
	Election[3].Nominees[3] = "Sandra Oswald";
	Election[2].ElectionCode = 1;


	Election[4].ID = 100004;
	Election[4].Name = "Minister";
	Election[4].Description = "Transport";
	Election[4].Nominees[1] = "Victor Steven";
	Election[4].Nominees[2] = "Ahmed Salah";
	Election[4].Nominees[3] = "Brain Adam";
	Election[2].ElectionCode = 1;


	electors[0].ID = "toretto";
	electors[0].Name = "Dominic Toretto";
	electors[0].Password = "toretto10";
	electors[0].Email = "torettod@gmail.com";
	electors[0].Address = "Maadi";
	electors[0].Phone = 010133;
	electors[0].ElectorCode = 1;



	main_menu();
}// end of main function


void main_menu()
{

	int choice;
	int count = 0;
	do
	{
		cout << "\t\t\t___________________________________________________________________________\n\n\n";
		cout << "\t\t\t                    THE VOTING SYSTEM LOGIN PAGE                           \n\n\n";
		cout << "\t\t\t______________________           MENU          ____________________________\n\n\n";
		cout << "\t\t\t\        PLEASE PRESS 1: IF YOU ARE AN ADMINSTRATOR                  \n\n";
		cout << "\t\t\t\        PLEASE PRESS 2: IF YOU ARE AN ELECTOR                       \n\n";
		cout << "\t\t\t\        PLEASE PRESS 3: TO EXIT THE PAGE                            \n\n";
		cout << "\t\t\t___________________________________________________________________________\n\n\n";

		cout << "Enter Your Choice:";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:

			admin_login_signup();
			system("cls");
			break;

		case 2:

			elector_login_signup();
			system("cls");
			break;

		case 3:

			system("cls");
			cout << "\n\nGoodbye!thanks for your time!" << endl;

			break;

		default:

			system("cls");
			cout << "\n\nInvalid Entry! please try again." << endl;

			main();
			break;

		}

	} while (choice != 3);

}
// elector loggin function

bool Elector_login(Electorinfo electors[], int electorCount)
{
	string Username, password;
	cout << "Enter your Username : ";
	cin.ignore();
	getline(cin, Username);
	cout << "Enter your password: ";
	cin >> password;
	for (int i = 0; i < num_electors; i++) {
		if (electors[i].ID == Username && electors[i].Password == password) {
			return true;
			cout << "you are logged in successfully" << endl;

		}
	}
	return false;
	cout << "\n\nInvalid Username or password.\n\n" << endl;
}


//  elector  function for signing up

void Elector_signup(Electorinfo electors[], int& electorCount)

{


	if (electorCount < num_electors)
	{
		Electorinfo newUser;



		cout << "Enter Your Username: ";
		cin >> newUser.ID;
		cout << "Enter your name: ";
		cin.ignore();
		getline(cin, newUser.Name);
		cout << "Enter your password: ";
		cin >> newUser.Password;
		cout << "Enter your email: ";
		cin >> newUser.Email;
		cout << "Enter your address: ";
		cin >> newUser.Address;
		cout << "Enter your phone number: ";
		cin >> newUser.Phone;
		cout << "Enter your code (1 - 3): ";
		cin >> newUser.ElectorCode;
		electors[electorCount] = newUser;
		electorCount++;
		cout << "\n\nYou have signed up successfully!\n\n" << endl;


	}

	cout << "\n Maximum Number of Voters reached!!\n\n ";

}

// edit elector's infomation function

void Elector_edit_info()
{
	int option;
	bool info_updated = false;
	string Username, password;
	cout << "Enter your Username: ";
	cin >> Username;
	cout << "Enter your Password: ";
	cin >> password;

	bool elector_info_updated = false;

	for (int i = 0; i < num_electors; i++)
	{
		if (electors[i].ID == Username && electors[i].Password == password)
		{
			cout << "\nWelcome! " << electors[i].Name << endl;
			cout << "\n____You can now edit your details._____\n\n" << endl;
			cout << "\t\t\t Press 1: Change Your Password.\n\n" << endl;
			cout << "\t\t\t Press 2: Change Your Email Address.\n\n" << endl;
			cout << "\t\t\t Press 3: Change Your Phone Number.\n\n" << endl;
			cout << "\t\t\t Press 4: Change Your Address.\n\n" << endl;
			cout << "\t\t\t Press 5: Previous Menu.\n\n" << endl;


			cout << "Enter Your Option:";
			cin >> option;

			switch (option)
			{
			case 1:
				cout << "Enter your new password : ";
				cin >> electors[i].Password;
				break;

			case 2:
				cout << "Enter your new email : ";
				cin >> admins[i].email;
				break;

			case 3:
				cout << "Enter your new address : ";
				cin >> electors[i].Address;
				break;

			case 4:
				cout << "Enter your new phone number : ";
				cin >> electors[i].Phone;
				break;

			case 5:
				elector_page();
				break;

			default:
				cout << "\n\nInvalid Entry or Choice please try again!" << endl;
				break;



			}
			cout << endl;
			info_updated = true;

			cout << admins[i].name;
		}
	}
	if (info_updated)
	{
		cout << "Information updated successfully ! thanks,\n " << endl;
	}
	else
	{
		cout << " \nUser not found , please enter a valid Username !\n\n" << endl;
	}
}

//elector   fuction for viewing election's results

void Elector_viewresults()
{

}

//a function for elector logging in and signup.

void elector_login_signup()
{

	bool 	Islogged_in = false;
	int count = 0;

	int option;

	do
	{

		cout << "\t\t\t__________ Elector's Logging in and Signup page____________\t\t\n\n\n" << endl;

		cout << "\t\t\t PLEASE PRESS 1: To SignUp.\n\n" << endl;
		cout << "\t\t\t PLEASE PRESS 2:To Login.\n\n" << endl;
		cout << "\t\t\t PLEASE PRESS 3:To Exit.\n\n" << endl;

		cout << "Please Enter Your Choice:";
		cin >> option;
		cout << endl;
		switch (option)
		{
		case 1:
			Elector_signup(electors, electorCount);
			system("cls");
			cout << "\nYou have Signed Up Successfully!!\n\n" << endl;
			break;

		case 2:

			Islogged_in = Elector_login(electors, electorCount);
			system("cls");
			if (Islogged_in)
			{
				cout << "\n\nYou are logged in Successfully!\n\n" << endl;
				elector_page();
			}
			else
			{
				cout << "\n\nLogin failed! Please Try Again." << endl;
			}
			break;

		case 3:
			cout << "\n\nGoodbye! Thanks for Your time!." << endl;
			break;
			system("cls");
			main();
			break;

		default:
			cout << "\n\nInvalid Entry or Choice please try again!" << endl;
			main();
			break;

		}

	} while (option != 3);
}




// Adminstrator Signup function

void signup(ElectionAdmin admins[], int& adminCount)
{



	if (adminCount < max_admin)
	{
		ElectionAdmin admin;


		cout << "Please Enter Your Details to Signup.\n" << endl;

		cout << "Enter Your Username:";
		cin >> admin.ID;

		cout << "Enter Your Name:";
		cin.ignore();
		getline(cin, admin.name);

		cout << "Enter Your Password:";
		cin >> admin.password;
		cout << "Enter Your Email :";
		cin >> admin.email;
		cout << "Enter Your Address : ";
		cin.ignore();
		getline(cin, admin.address);

		cout << "Enter Your Phone number(minimum 10 digits.): ";
		cin >> admin.phone;


		admins[0].ID = "admin";
		admins[0].name = "admin";
		admins[0].password = "admin";
		admins[0].email = "admin";
		admins[0].address = "admin";
		admins[0].phone = 001;
		adminCount++;

		admins[adminCount] = admin;
		adminCount++;



	}
	system("cls");
	cout << "\n\nMaximum number of Adminstrators reached !\n\n " << endl;

}

// Administrator login function
bool login(ElectionAdmin admins[], int adminCount)
{
	string adminId, adminPassword;

	cout << "Enter Your Username :";
	cin >> adminId;
	cout << "Enter Your Password :";
	cin >> adminPassword;
	for (int i = 0; i < 5; i++)
	{
		if (admins[i].ID == adminId && admins[i].password == adminPassword)
			return true;


	}
	return false;
	system("cls");
	cout << "ERROR!, Invalid Username or Password . Please Try Again! " << endl;

}


// Adminstrator edit info function, the admin is not allowed to edit key info like id and name

void editInfo()
{
	int option;
	string n_id, n_pass;

	bool info_updated = false;

	cout << "Enter Your Username :";
	cin >> n_id;
	cout << "Enter Your Password :";
	cin >> n_pass;


	for (int i = 0; i < max_admin; i++)
	{
		if (admins[i].ID == n_id && admins[i].password == n_pass)
		{
			cout << "\nWelcome!  " << admins[i].name << endl;
			cout << "\n______You can Now Edit Your Information________\n\n" << endl;
			cout << "\t\t\t PRESS 1:To Change Your Password.\n\n" << endl;
			cout << "\t\t\t PRESS 2:To Change Your Email Address.\n\n" << endl;
			cout << "\t\t\t PRESS 3:To Change Your Address.\n\n" << endl;
			cout << "\t\t\t PRESS 4:To Change Your Phone Number.\n\n" << endl;
			cout << "\t\t\t PRESS 5:To Previous Menu.\n\n" << endl;

			cout << "Enter Your Option:";
			cin >> option;
			switch (option)
			{
			case 1:
				cout << "Enter your new password : ";
				cin >> admins[i].password;
				break;

			case 2:
				cout << "Enter your new email : ";
				cin >> admins[i].email;
				break;

			case 3:
				cout << "Enter your new address : ";
				cin >> admins[i].address;
				break;

			case 4:
				cout << "Enter your new phone number : ";
				cin >> admins[i].phone;
				break;

			case 5:
				system("cls");
				admin_page();
				break;

			case 6:

				break;

			default:
				cout << "\n\nInvalid Entry or Choice please try again!" << endl;
				break;



			}
			cout << endl;
			info_updated = true;

			cout << admins[i].name;
		}
	}
	if (info_updated)
	{
		cout << "Information updated successfully ! thanks,\n " << endl;
	}
	else
	{
		cout << " \nUser not found , please enter a valid Username !\n\n" << endl;
	}
}

// administrator login and signup function

void admin_login_signup()
{
	bool islogin = false;
	int adminCount = 0;
	int choice;

	do
	{
		cout << "\n\n\t\t_____Administrator Login and Signup Page______\t\t\n\n\n";

		cout << "\t\tPress 1 :\t To Signup \t\t" << endl;
		cout << "\t\tPress 2 :\t To login \t\t" << endl;
		cout << "\t\tPress 3 :\t To Exit \t\t\n\n" << endl;

		cout << "\t\tPlease Enter your Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:

			signup(admins, adminCount);
			system("cls");
			cout << "\n\nYou have signup successfully !\n" << endl;
			break;

		case 2:

			islogin = login(admins, adminCount);
			system("cls");
			if (islogin)
			{
				cout << "\n\nlogin successful !\n\n" << endl;
				admin_page();
			}
			else
			{
				cout << "\n\n login failed ! , please try again.\n\n" << endl;

			}
			break;

		case 3:
			cout << "\n\n You are logged out successfully !\n\n" << endl;

			break;
			main();

		default:
			cout << "\n\nInvalid Entry , please try again.\n\n" << endl;

			break;

		}




	} while (choice != 3);


}

// a function for editing information,viewing finished election and voting

void elector_page()
{
	int choice;

	do
	{
		cout << "\t\t\t____________ Elector Page_____________\t\t\t\n\n" << endl;

		cout << "\t\t\t Press 1:To Edit Information\n\n" << endl;
		cout << "\t\t\t Press 2:To Vote \n\n" << endl;
		cout << "\t\t\t Press 3:To View Finished Elections\n\n" << endl;
		cout << "\t\t\t Press 4:To Exit the Page\n\n";

		cout << "Enter Your Choice:";
		cin >> choice;
		cout << endl;
		switch (choice)
		{

		case 1:
			system("cls");
			Elector_edit_info();
			break;
		case 2:
			system("cls");
			Electors_vote();
			break;
		case 3:
			system("cls");
			FinishedElection();
			break;
		case 4:
			system("cls");
			cout << "\n\nGoodbye! Thanks for Your time!." << endl;
			break;
		default:
			cout << "\n\nInvalid Entry or Choice please try again!" << endl;
			break;

		}
	} while (choice != 4);


}

void admin_page()
{
	bool endelection = false;
	int option;
	cout << endl;

	do
	{
		cout << "\t\t\t__________Administrator Page_______________\t\t\t\n\n" << endl;
		cout << "\t\t\t Press 1:To Edit Information\n\n" << endl;
		cout << "\t\t\t Press 2:To Create an Election\n\n" << endl;
		cout << "\t\t\t Press 3:To Edit Election's Description\n\n" << endl;
		cout << "\t\t\t Press 4:To Delete a Nominee\n\n" << endl;
		cout << "\t\t\t Press 5:To End an Election\n\n" << endl;
		cout << "\t\t\t Press 6:To Elector's Profile \n\n" << endl;
		cout << "\t\t\t Press 7:To Log Out\n\n" << endl;

		cout << "Enter Your Option:";
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			editInfo();
			break;

		case 2:
			system("cls");

			int n;
			inputElection(n);
			admindisplayElection();
			break;

		case 3:
			system("cls");
			edit_Election_Description();
			break;

		case 4:
			system("cls");
			Edit_Nominee();
			break;

		case 5:
			system("cls");
			end_election();


			break;

		case 6:
			system("cls");
			elector_login_signup();
			break;

		case 7:
			system("cls");
			cout << "\n\nGoodbye! Thanks for Your time!." << endl;
			break;

		default:
			cout << "\n\nInvalid Entry or Choice please try again!" << endl;
			break;



		}


	} while (option != 7);


}



//admin privileges with respect to the election

int inputElection(int& size)//Election registration function
{
	int result = j;
	int adminCode;
	char answer;

	cout << "Enter your Admin code: " << endl;
	cin >> adminCode;
	do
	{

		Election[j].ElectionAdminCode = adminCode;
		cout << "Enter Election name:" << endl;
		cin.ignore();
		getline(cin, Election[j].Name);

		cout << "Enter Election description:" << endl;
		getline(cin, Election[j].Description);

		Election[j].ElectionCode = 1 + (rand() % 3);
		cout << "The ELection CODE is: " << Election[j].ElectionCode << endl;

		Election[j].ID = 100000 + j;
		cout << "The ELection ID is: " << Election[j].ID << endl;


		cout << "How many nominees do you want to register?" << endl;
		cin >> size;

		cout << "Enter nominees names" << endl;
		cin.ignore();
		for (int i = 1; i <= size; i++) //nominees input
		{
			getline(cin, Election[j].Nominees[i]);

		}
		j++;
		cout << " Do you want to add more elections? (y / n ) " << endl;
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	return result;
}


void displayElection() //Election and Nominees' display function
{
	int n = 0;
	cout << "The registered elections and their candidates are: " << endl;

	for (int i = 0; i < j; i++)
	{
		cout << Election[i].ID << '\t';
		cout << "Election name:\t" << Election[i].Name << '\t';
		cout << Election[i].Description << '\t' << endl;

		cout << "Nominees are:" << endl;
		for (int k = 1; k <= 6; k++) //nominees output
		{
			cout << k << ".\t" << Election[i].Nominees[k] << endl;
		}

	}
}

void displayElection_only()//Displays the registered elections only
{
	{
		cout << "The registered elections are: " << endl;


		for (int i = 0; i < j; i++)
		{
			if (electors[i].ElectorCode == Election[i].ElectionCode)

			{
				cout << Election[i].ID << '\t';
				cout << "Election name:\t" << Election[i].Name << '\t';
				cout << Election[i].Description << '\t' << endl;
			}
		}
	}
}

void edit_Election_Description() //Edit Election Description function
{
	admindisplayElection();
	int i; //The election ID index
	cout << "\nEnter the ID of the Election to be edited" << endl;
	cin >> i;

	i = i - 100000;

	if (i <= j)
	{
		cout << "\nEnter the Updated Election description:" << endl;
		cin.ignore();
		getline(cin, Election[i].Description);
	}
	else
		cout << "Invalid Election ID.";

	admindisplayElection();
}

void Edit_Nominee() //Edit Election Description function
{
	int i,//The election ID index
		n;//The nominees index

	admindisplayElection();

	cout << "Enter the ID of the Election to be edited" << endl;
	cin >> i;
	i = i - 100000;

	if (i >= 0 && i <= j)
	{
		cout << "Election name:\t" << Election[i].Name << '\t';
		cout << Election[i].Description << '\t' << endl;
		cout << "Nominees are:" << endl;
		for (int k = 1; k <= 6; k++) //nominees output
		{
			cout << k << ".\t" << Election[i].Nominees[k] << endl;
		}

		cout << "Enter the Number to be edited" << endl;
		cin >> n;
		cout << "Enter the Updated Nominee:" << endl;
		cin.ignore();
		getline(cin, Election[i].Nominees[n]);

	}
	else
	{
		cout << "I'm sorry, that is an invalid selection.\n"
			<< "The speakers range from 0-9.\n"
			<< "Please select this option again.\n\n";
	}
}

void Electors_vote() //Edit Election Description function
{
	int i,//The election ID index
		n;//The nominees index

	displayElection_only();

	cout << "Enter the ID of the Election to vote in" << endl;
	cin >> i;
	i = i - 100000;

	if (i >= 0 && i <= j)
	{
		cout << "Election name:\t" << Election[i].Name << '\t';
		cout << Election[i].Description << '\t' << endl;
		cout << "Nominees are:" << endl;
		for (int k = 1; k <= 6; k++) //nominees output
		{
			cout << k << ".\t" << Election[i].Nominees[k] << endl;
		}

		cout << "Enter the Number to be voted" << endl;
		cin >> n;

		if (n >= 1 && n <= 6)
		{
			Election[i].Votes[n] = Election[i].Votes[n] + 1;
		}
		else
		{
			cout << "I'm sorry, that is an invalid nominee number.\n"
				<< "The speakers range from 1-6.\n"
				<< "Please select this option again.\n\n";
		}
	}
	else
	{
		cout << "I'm sorry, that is an invalid selection.\n"
			<< "The speakers range from 0-9.\n"
			<< "Please select this option again.\n\n";
	}

}
void displayVotes() //Election and Nominees' display function
{
	cout << "The registered elections and their candidates are: " << endl;

	for (int i = 0; i < j; i++)
	{
		if (electors[i].ElectorCode == Election[i].ElectionCode)

		{
			cout << Election[i].ID << '\t';
			cout << "Election name:\t" << Election[i].Name << '\t';
			cout << Election[i].Description << '\t' << endl;

			cout << "Nominees are:" << endl;
			for (int k = 1; k <= 6; k++) //nominees output
			{
				cout << k << ".\t" << Election[i].Nominees[k];

				cout << ".\t Votes: " << Election[i].Votes[k] << endl;
			}
		}

	}
}

void admindisplayElection() //Election and Nominees' display function
{
	int i;
	int admincode;
	cout << "Enter your Admin Code" << endl;
	cin >> admincode;


	cout << "The registered elections and their candidates are: " << endl;

	for (int i = 0; i < j; i++)
	{
		if (admincode == Election[i].ElectionAdminCode)
		{
			cout << Election[i].ID << '\t';
			cout << "Election name:\t" << Election[i].Name << '\t';
			cout << Election[i].Description << '\t' << endl;
		}


	}


}


void end_election()
{
	admindisplayElection();
	int i;

	cout << "Enter the ID of the Election to end" << endl;
	cin >> i;
	i = i - 100000;

	if (i >= 0 && i <= j)
	{
		cout << "Election name:\t" << Election[i].Name << '\t';
		cout << Election[i].Description << endl;

		Election[i].Finished = true;

		cout << "You have successfully ended the Election" << endl;

	}
	else
	{
		cout << "I'm sorry, that is an invalid selection.\n"
			<< "The speakers range from 0-9.\n"
			<< "Please select this option again.\n\n";
	}
}

void FinishedElection() //Election and Nominees' display function
{

	cout << "The following are the finished Elections:\n\n " << endl;

	for (int i = 0; i < j; i++)
	{
		if (Election[i].Finished == true)
		{
			cout << Election[i].ID << '\t';
			cout << "Election name:\t" << Election[i].Name << '\t';
			cout << Election[i].Description << '\t' << endl;
		}


	}


}