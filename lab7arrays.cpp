#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{

    cout << fixed << setprecision(2) << setw(20);
    // statement of purpose
    cout << "The purpose of this program is for a retail store to store the "
         << "sales and number of employees for the week. The program will then "
         << "calculate the average sales per employee and display all the "
         << "results. " << endl;
    // initilization of arrays
    string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    double dailySales[7];
    int dailyEmployees[7];
    double salesPerEmployee[7];
    // variables for input
    double sales;
    int employees;

    // loop to gather input from user for sales and employees for each
    // day of the week
    for (int i = 0; i < 7; i++)
    {
        cout << "Input the total sales for " << daysOfWeek[i] << ": $";
        cin >> sales;
        // check for negative input for sale amount
        while (sales < 0)
        {
            cout << "Sorry, please enter a value for sales of zero or greater: $";
            cin >> sales;
        }
        // populate index with sale amount
        dailySales[i] = sales;

        cout << "Input the number of employees on " << daysOfWeek[i] << ": ";
        cin >> employees;

        // check for employee amount less than 1
        while (employees < 1)
        {
            cout << "Sorry, Please enter a nubmer of employees greater than zero: ";
            cin >> employees;
        }
        cout << endl;

        // populate index with number of employees
        dailyEmployees[i] = employees;

        // calculate average sales per employee for that day, insert into index
        salesPerEmployee[i] = dailySales[i] / dailyEmployees [i];
    }
    cout << "--------------------------------" << endl;

    // display results
    for (int i = 0; i < 7; i++)
    {
        cout << "Total sales for " << daysOfWeek[i] << ": $" << dailySales[i]
             << "\nNumber of employees worked: " << dailyEmployees[i]
             << "\nAverage sales per employee: $" << salesPerEmployee[i]
             << endl << endl;
    }

    return 0;

}
