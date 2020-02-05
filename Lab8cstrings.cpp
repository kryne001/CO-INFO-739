// Kyler Rynear
// 2/6/2020
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const string LINE = "-------------------------------";

// function gets password input from user
void getPassword (char []);
// function checks to see if password meets criteria for strength
bool checkStrength (char []);
// function handles re-typing password
void reEnterPass (char[]);
// function checks if second entry of password is same as first
bool checkSame(char[], char[]);


int main()
{
    char password[50];
    bool isStrongEnough = false;

    cout << endl << "The purpose of this lab is to create a program for users "
         << "to create a password of sufficient strength. The user will input "
         << "a password and the program will check if the password contains an "
         << "upper case letter, lower case letter, number, special character, "
         << "is at least 6 characters long and contains no spaces. If the "
         << "password does not meet this criteria, the program will prompt the "
         << "user to re-enter a different password until the criteria is met. "
         << "The program will then ask the user to re-enter the password to "
         << "make sure the password is correct, and will prompt them to re-enter "
         << "until the same password is input." << endl << LINE << endl;
    // call get password and check criteria, repeat if not strong enough
    do
    {
        getPassword(password);
        cout << LINE << endl;
        isStrongEnough = checkStrength(password);
    } while (!isStrongEnough);

    // handle password re-entry after sufficient input
    reEnterPass(password);
    cout << "Succesfully created password." << endl;
    return 0;
}

// get user input for password
void getPassword(char password[])
{
    cout << "Enter your password. Please make sure it is strong (at least "
         << "six characters, with at least one uppercase letter, one lowercase "
         << "letter, one number, and one special character): ";
    cin.getline(password, 50);
}

// check criteria of password
bool checkStrength(char password[])
{
    int size = 0;
    int minSize = 6;
    // flags for each criteria. will be false until they're found in cstring
    bool lowerCase = false;
    bool upperCase = false;
    bool num = false;
    bool character = false;
    bool sizeCheck = false;
    bool spaces = false;
    // step through indeces, check for each criteria, switch to true if found
    for(int i = 0; i < strlen(password); i++)
    {
        // incrementer to find size of cstring
        size++;
        if (isalpha(password[i]))
        {
            if (isupper(password[i]))
            {
                upperCase = true;
            }
            else
            {
                lowerCase = true;
            }
        }
        else if (isdigit(password[i]))
        {
            num = true;
        }
        else if (ispunct(password[i]))
        {
            character = true;
        }
        else if (isspace(password[i]))
        {
            spaces = true;
        }
    }

    // final check after end of loop for size criteria
    if (size >= minSize)
    {
        sizeCheck = true;
    }

    // if all criteria is met, return true
    if (upperCase && lowerCase && num && character && size && !spaces)
    {
        return true;
    }
    else
    {
        // display portions of criteria missing so user knows what they're
        // missing, return false so that user can be prompted for input again
        // in main
        cout << "Password isn't strong enough. Missing: " << endl << endl;
        if(!upperCase)
        {
            cout << "Upper case letter" << endl;
        }
        if (!lowerCase)
        {
            cout << "Lower case letter" << endl;
        }
        if (!num)
        {
            cout << "Number" << endl;
        }
        if(!character)
        {
            cout << "Special character" << endl;
        }
        if(!sizeCheck)
        {
            cout << "Not long enough" << endl;
        }
        if(spaces)
        {
            cout << "Contains space(s)" << endl;
        }
        cout << "\nPlease try again." << endl;
        return false;
    }
}

// handles re-entry of password
void reEnterPass(char password[])
{
    char resubmit[50];
    bool same = true;

    cout << "Please re-type password: ";
    cin >> resubmit;
    cout << endl;

    // checks if the two cstrings are the same, returns true for yes, false for no
    same = checkSame(password, resubmit);

    // loops until function returns true
    while (!same)
    {
        cout << "ERROR: passwords do not match.\nPlease re-enter password: ";
        cin >> resubmit;
        cout << endl;

        same = checkSame(password, resubmit);

    }
}

// checks if two cstrings are the same
bool checkSame(char password[], char retype[])
{
    // first check to see if they are different length. if true, automatically
    // not the same, return false
    if (strlen(password) != strlen(retype))
    {
        return false;
    }
    else
    {
        // step through indeces to see if they're the same at every index.
        int i = 0;
        while (retype[i] != '\0')
        {
            // if we find index that isn't identical, end function and return false
            if (password[i] != retype[i])
            {
                return false;
            }
            i++;
        }
    }

    // if at this point, means that both cstrings are identical, return true
    return true;
}
