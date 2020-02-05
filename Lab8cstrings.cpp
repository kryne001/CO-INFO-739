#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const string LINE = "-------------------------------";

void getPassword (char []);
bool checkStrength (char []);
void reEnterPass (char[]);
bool checkSame(char[], char[]);


int main()
{
    cout << fixed << setw(13);
    char password[50];
    int checks = 0;
    bool isStrongEnough = false;
    int size = 0;


    getPassword(password);
    cout << LINE << endl;
    isStrongEnough = checkStrength(password);
    cout << LINE << endl;

    while (!isStrongEnough)
    {
        getPassword(password);
        cout << LINE << endl;
        isStrongEnough = checkStrength(password);
    }

    reEnterPass(password);
    cout << "Succesfully created password." << endl;
    return 0;
}

void getPassword(char password[])
{
    cout << "Enter your password. Please make sure it is strong (at least "
         << "six characters, with at least one uppercase letter, one lowercase "
         << "letter, one number, and one special character): ";
    cin.getline(password, 50);
}

bool checkStrength(char password[])
{
    int size = 0;
    int minSize = 6;
    bool lowerCase = false;
    bool upperCase = false;
    bool num = false;
    bool character = false;
    bool sizeCheck = false;
    bool spaces = false;
    for(int i = 0; i < strlen(password); i++)
    {
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
    if (size >= minSize)
    {
        sizeCheck = true;
    }

    if (upperCase && lowerCase && num && character && size && !spaces)
    {
        return true;
    }
    else
    {
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

void reEnterPass(char password[])
{
    char resubmit[50];
    bool same = true;

    cout << "Please re-type password: ";
    cin >> resubmit;
    cout << endl;

    same = checkSame(password, resubmit);

    while (!same)
    {
        cout << "ERROR: passwords do not match.\nPlease re-enter password: ";
        cin >> resubmit;
        cout << endl;

        same = checkSame(password, resubmit);

    }
}

bool checkSame(char password[], char retype[])
{
    if (strlen(password) != strlen(retype))
    {
        return false;
    }
    else
    {
        int i = 0;
        while (retype[i] != '\0')
        {
            if (password[i] != retype[i])
            {
                return false;
            }
            i++;
        }
    }

    return true;
}
