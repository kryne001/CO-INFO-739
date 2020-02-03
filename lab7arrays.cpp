// Kyler RYnear
// 2/2/2020
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{

    cout << fixed << setprecision(2) << setw(20);
    const int SIZE = 7;
    // statement of purpose
    cout << "The purpose of this program is for a retail store to store the "
         << "sales and number of employees for the week. The program will then "
         << "calculate the average sales per employee and display all the "
         << "results. " << endl;
    // initilization of arrays
    string daysOfWeek[SIZE] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    double dailySales[SIZE];
    int dailyEmployees[SIZE];
    double salesPerEmployee[SIZE];
    // variables for input
    double sales;
    int employees;
    double highestSales = 0;

    // loop to gather input from user for sales and employees for each
    // day of the week
    for (int i = 0; i < SIZE; i++)
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
        if (sales > highestSales)
        {
            highestSales = sales;
        }

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
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Total sales for " << daysOfWeek[i] << ": $" << dailySales[i]
             << "\nNumber of employees worked: " << dailyEmployees[i]
             << "\nAverage sales per employee: $" << salesPerEmployee[i]
             << endl << endl;
    }

    cout << "--------------------------------" << endl;

    cout << "Best day(s) for sale: " << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (highestSales == dailySales[i])
        {
            cout << daysOfWeek[i] << endl;
        }
    }

    return 0;

}
