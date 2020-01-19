// Kyler Rynear
// 1/21/20
// The purpose of this program is to determine what pay goes to
// sales representatives
#include <iostream>
#include <cstdlib>
#include <iomanip>
// constant declarations for different sales levels
const double LESS_THAN_TEN_THOU_SALES = 9999;
const double UNDER_FIFTY_THOU_SALES = 49999;
const double UNDER_FIFTY_THOU_SALES_COMMISSION_PCNT = 0.01;
const double UNDER_HUNDRED_THOU_SALES = 99999;
const double UNDER_HUNDRED_THOU_SALES_COMMISSION_PCNT = 0.02;
const double UNDER_TWOHUN_THOU_SALES = 199999;
const double UNDER_TWOHUN_THOU_SALES_COMMISSION_PCNT = 0.03;
const double OVER_TWOHUN_SALES_COMMISSION_PCNT = 0.04;
const double TWOFIFTY_THOU_SALES = 250000;
const double TWOFIFTY_THOU_SALES_BONUS = 500;
using namespace std;

int main()
{
    // Setting decimal precision to 2 decimal points
    cout << fixed << setprecision(2);
    // Purpose of the program
    cout << "Use this program to calculate the salary for a sales "
         << "representative. It will determine whether the employee has "
         << "earned enough for commission or if they will receive the draw. "
         << "If they have earned enough for commission, their commission "
         << "percentage will be based on amount of sales. If they sold more "
         << "than $250,000 in sales, they will be recognized as being part "
         << "of the $250,000 club and receive a $500 bonus. "
         << "User will provide the sales amount for the reprsentative and the "
         << "draw amount. " << endl << endl;



    double salesAmount;
    double draw;
    double commission = 0;



    // Receive user input for sales of rep
    cout << "Enter Sales amount: $";
    cin >> salesAmount;
    cout << endl;

    // check for negative value input, ask for input again
    if(salesAmount < 0)
    {
        cout << "ERROR: VALUE IS A NEGATIVE NUMBER" << endl
             << "Please enter a value greater than zero: $";
        cin >> salesAmount;
        cout << endl;
    }

    // Receive user input for draw amount
    cout << "Enter draw amount: $";
    cin >> draw;
    cout << endl;

    // check for negative value input, ask for input again
    if (draw < 0)
    {
        cout << "ERROR: VALUE IS A NEGATIVE NUMBER" << endl
             << "Please enter a value greater than zero: $";
        cin >> draw;
        cout << endl;
    }

    // start first check to see if user has less than 10,000 in sales
    if (salesAmount <= LESS_THAN_TEN_THOU_SALES)
    {
        cout << "Employee receives draw, to the amount of $" << draw << endl;
    }
    // check if sales is 10,000 or more
    else if (salesAmount > LESS_THAN_TEN_THOU_SALES)
    {
        // check if sales is 50,000 or more
        if(salesAmount > UNDER_FIFTY_THOU_SALES)
        {
            // check if sales is 100,000 or more
            if (salesAmount > UNDER_HUNDRED_THOU_SALES)
            {
                // check if sales is 200,000 or more
                if (salesAmount > UNDER_TWOHUN_THOU_SALES)
                {
                    // check if sales is 250,000 or more
                    if (salesAmount >= TWOFIFTY_THOU_SALES)
                    {
                        // display 250,000 club member message, assign bonus to
                        // commission
                        cout << "$250,000 CLUB MEMBER!" << endl;
                        commission = TWOFIFTY_THOU_SALES_BONUS;
                    }
                    // sales over 200,000, calculate commission with 0.4% great
                    // if sales over 250,000, bonus already added
                    commission += salesAmount *
                                    OVER_TWOHUN_SALES_COMMISSION_PCNT;
                    cout << "Employee receives commission, to the amount of $"
                         << commission << endl;
                }
                // sales between 100,000 and 200,000, calculate commission with
                // 0.3% rate
                else
                {
                    commission = salesAmount *
                                    UNDER_TWOHUN_THOU_SALES_COMMISSION_PCNT;
                    cout << "Employee receives commission, to the amount of $"
                         << commission << endl;
                }

            }
            // sales between 50,000 and 100,000, calculate commission with
            // 0.2% rate
            else
            {
                commission = salesAmount *
                                UNDER_HUNDRED_THOU_SALES_COMMISSION_PCNT;
                cout << "Employee receives commission, to the amount of $"
                     << commission << endl;
            }
        }
        // sales is between 10,000 and 50,000, calculate commission with 0.1%
        // rate
        else
        {
            commission = salesAmount * UNDER_FIFTY_THOU_SALES_COMMISSION_PCNT;
            cout << "Employee receives commission, to the amount of $"
                 << commission << endl;
        }
    }
    cout << endl;
    return 0;
}
