#include <iostream>
#include <string>
#define max_admin 5
int j = 1; //Election ID counter

using namespace std;

struct ElectionAdmin // Struct for storing Election Administrator data
{
    string ID;
    string name;
    string password;
    string email;
    string address;
    string phone;

    int numElections = 0; // Number of elections for this administrator
} admins[5];
struct Election // Struct for storing Election  data
{
    int ID;
    string Name;
    string Description;
    string Nominees[100];
} Election[100];

bool login();
void editInfo();
ElectionAdmin signup();
void admin_login_signup(); // administrator login and signup function


//Admin privileges
void admin_menu();
int inputElection(int& size);
void displayElection();
void displayElection_only();

void admin_edit_choices(); //Admin to choose to edit description or nominees
void edit_Election_Description(); //Admin edits the description of the selected election
void Edit_Nominee();//Admin edits the description of the selected election

int main()
{
    admin_login_signup();

}


// Adminstrator Signup function

ElectionAdmin signup()
{
    int count = 0;
    if (count < max_admin)
    {
        ElectionAdmin admin;

        cout << "Please Enter Your Details to Signup." << endl;

        cout << "Enter Your ID:";
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

        cout << "Enter Your Phone number(minimum 10 didits.) ";
        cin >> admin.phone;

        admins[count] = admin;
        count++;

        return admin;
    }
    cout << "Maximum number of Adminstrators reached ! " << endl;
    system("cls");

}

// Administrator login function
bool login()
{
    string adminId, adminPassword;

    cout << "Enter Your UserID :";
    cin >> adminId;
    cout << "Enter Your Password :";
    cin >> adminPassword;
    for (int i = 0; i < 5; i++)
    {
        if (admins[i].ID == adminId && admins[i].password == adminPassword)
            return true;


    }
    return false;
    cout << "ERROR!, Invalid UserID or Password . Please Try Again! " << endl;
    system("cls");
}
void admin_login_signup()
{
    bool islogin = false;
    int count = 0;
    int choice;

    do
    {
        cout << "\n\n\t\t_____Administrator Login and Signup Page______\t\t\n\n\n";

        cout << "\t\tPress 1 :\t Signup \t\t" << endl;
        cout << "\t\tPress 2 :\t login \t\t" << endl;
        cout << "\t\tPress 3 :\t Logout \t\t\n\n" << endl;

        cout << "Please Enter your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            signup();
            system("cls");
            cout << "\nYou have signup successfully !\n" << endl;
            break;

        case 2:

            islogin = login();
            system("cls");
            if (islogin)
            {
                cout << "login successful !\n\n" << endl;
                admin_menu();

            }
            else
            {
                cout << " login failed ! , please try again.\n\n" << endl;

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

// Adminstrator edit info function, the admin is not allowed to edit key info like id and name
void editInfo()
{
    string n_id;
    string n_password;
    string n_email;
    string n_address;
    string n_phone;

    cout << "Enter Your UserID :";
    cin >> n_id;

    for (int i = 0; i < max_admin; i++)
    {
        if (admins[i].ID == n_id)
        {
            cout << "Enter your new password : ";
            cin >> n_password;
            cout << "Enter your new email : ";
            cin >> n_email;
            cout << "Enter your new address : ";
            cin >> n_address;
            cout << "Enter your new phone number : ";
            cin >> n_phone;

            admins[i].password = n_password;
            admins[i].email = n_email;
            admins[i].address = n_address;
            admins[i].phone = n_phone;

            cout << "Information updated successfully ! thanks " << admins[i].name << "!" << endl;
        }
    }
    cout << " User not found or please enter a valid UserID !" << endl;
}

//Administrator privileges:

int inputElection(int& size)//Election registration function
{
    int result = j;
    char answer;
    do
    {
        cout << "Enter Election name:" << endl;
        cin.ignore();
        getline(cin, Election[j].Name);

        cout << "Enter Election description:" << endl;
        getline(cin, Election[j].Description);

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
void displayElection() //Election display function
{
    int n = 0;
    cout << "The registered elections and their candidates are: " << endl;

    for (int i = 1; i < j; i++)
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
        int n = 0;
        cout << "The registered elections and their candidates are: " << endl;

        for (int i = 1; i < j; i++)
        {
            cout << Election[i].ID << '\t';
            cout << "Election name:\t" << Election[i].Name << '\t';
            cout << Election[i].Description << '\t' << endl;
        }
    }
}
void admin_menu()
{
    int choice;

    do
    {
        cout << "\n\n\t\t_____Welcome to the Administrator Menu______\t\t\n\n\n";

        cout << "\t\tPress 1 :\t Edit Information \t\t" << endl;
        cout << "\t\tPress 2 :\t Create a New Election \t\t" << endl;
        cout << "\t\tPress 3 :\t Edit Elections \t\t" << endl;
        cout << "\t\tPress 4 :\t Logout \t\t\n\n" << endl;


        cout << "Please Enter your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

        case 2:

            int n;
            inputElection(n);
            displayElection_only();
            system("cls");
            break;

        case 3:

            admin_edit_choices();
            system("cls");
            break;

        case 4:
            cout << "\n\n You are logged out successfully !\n\n" << endl;
            system("cls");
            break;
            main();

        default:
            cout << "\n\nInvalid Entry , please try again.\n\n" << endl;

            break;

        }

    } while (choice != 4);

}
void admin_edit_choices()
{
    int choice;

    do
    {
        cout << "\n\n\t\t_____Edit Election Menu______\t\t\n\n\n";

        cout << "\t\tPress 1 :\t Edit Election Description \t\t" << endl;
        cout << "\t\tPress 2 :\t Election Nominees \t\t" << endl;
        cout << "\t\tPress 3 :\t Go Back to the previous Menu \t\t\n\n" << endl;


        cout << "Please Enter your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            edit_Election_Description();
            break;
        case 2:
            Edit_Nominee();
            break;

        default:
            cout << "\n\nInvalid Entry , please try again.\n\n" << endl;

            break;

        }

    } while (choice != 3);

}
void edit_Election_Description()
{
    displayElection_only();
    int i; //The election ID index
    cout << "Enter the ID of the Election to be edited" << endl;
    cin >> i;

    i = i - 100000;

    if (i <= j)
    {
        cout << "Enter the Updated Election description:" << endl;
        cin.ignore();
        getline(cin, Election[i].Description);
    }
    else
        cout << "Invalid Election ID.";

    displayElection_only();
}
void Edit_Nominee()
{
    int i,//The election ID index
        n;//The nominees index

    displayElection();

    cout << "Enter the ID of the Election to be edited" << endl;
    cin >> i;
    i = i - 100000;

    if (i <= j)
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

        displayElection();
    }
    else
    {
        cout << "I'm sorry, that is an invalid selection.\n"
            << "The speakers range from 0-9.\n"
            << "Please select this option again.\n\n";
    }
}