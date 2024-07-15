// including necessary header files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h> // assuming this is for getch()

using namespace std;

// global variables
string fname, lname, phone_num;

// Function prototypes
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    short int choice;

    // clearing screen and setting color
    system("cls");
    system("color 0A");

    // main menu display
    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
    cin >> choice;

    // menu choice handling using switch statement
    switch (choice)
    {
    case 1:
        addContact();
        break;
    case 2:
        searchContact();
        break;
    case 3:
        help();
        break;
    case 4:
        self_exit();
        break;
    default:
        cout << "\n\n\tInvalid Input !";
        cout << "\n\tPress Any Key To Continue..";
        getch(); // waiting for a key press
        main();  // restart main function
    }

    return 0;
}

// function to exit the program
void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !";
    exit(1); // exit with code 1
}

// function to display help information
void help()
{
    cout << "This displays help"; // placeholder
}

// function to add a contact
void addContact()
{
    ofstream phone("number.txt", ios::app); // opening file for appending

    // clearing screen and taking user input
    system("cls");
    cout << "\n\n\tEnter First Name : ";
    cin >> fname;
    cout << "\n\tEnter Last Name : ";
    cin >> lname;
    cout << "\n\tEnter 10-Digit Phone Number : ";
    cin >> phone_num;

    // validation checks for phone number
    if (check_digits(phone_num))
    {
        if (check_numbers(phone_num))
        {
            // writing to file if valid
            if (phone.is_open())
            {
                phone << fname << " " << lname << " " << phone_num << endl;
                cout << "\n\tContact Saved Successfully !";
            }
            else
            {
                cout << "\n\tError Opening File !";
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Numbers Only !";
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must Contain Exactly 10 Digits.";
    }

    phone.close(); // closing file
}

// function to search for a contact
void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt"); // opening file for reading
    string keyword;

    // taking input for search keyword
    cout << "\n\tEnter Name To Search : ";
    cin >> keyword;

    // searching through file for matching contacts
    while (myfile >> fname >> lname >> phone_num)
    {
        if (keyword == fname || keyword == lname)
        {
            // displaying contact details if found
            system("cls");
            cout << "\n\n\n\t\tContact details..";
            cout << "\n\n\tFirst Name : " << fname;
            cout << "\n\tLast Name : " << lname;
            cout << "\n\tPhone Number : " << phone_num;
            found = true;
            break;
        }
    }

    // displaying message if contact not found
    if (!found)
        cout << "\n\tNo Such Contact Found";

    myfile.close(); // closing file
}

// function to check if string has exactly 10 digits
bool check_digits(string x)
{
    return x.length() == 10;
}

// function to check if string consists only of numeric digits
bool check_numbers(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (!(x[i] >= '0' && x[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}
