// Kyler Rynear
// 1/21/20
// The purpose of this program is to determine what pay goes to
// sales representatives
#include <iostream>
#include <cstdlib>
#include <iomanip>
const double LESS_THAN_10_THOU_SALES = 9,999;
const double 50_THOU_SALES = 49,999;
const double 50_THOU_SALES_COMMISSION_PCNT = 0.01;
const double 100_THOU_SALES = 99,999;
const double 100_THOU_SALES_COMMISSION_PCNT = 0.02;
const double 200_THOU_SALES = 199,999;
const double 200_THOU_SALES_COMMISSION_PCNT = 0.03;
const double OVER_200_SALES = 200,000;
const double OVER_200_SALES_COMMISSION_PCNT = 0.04;
const double 250_THOU_SALES = 250,000;
const double 250_THOU_SALES_BONUS = 500;
using namespace std;

double main()
{
    double salesAmount;
    double draw;
    double commission;

    cout << fixed << setprecision(2);
    cout << "Enter Sales amount: ";
    cin >> salesAmount;
    cout << endl;

    if(salesAmount < 0)
    {
        cout << "ERROR: VALUE IS A NEGATIVE NUMBER" << endl
             << "Please enter a value greater than zero: ";
        cin >> salesAmount;
        cout << endl;
    }

    cout << "Enter draw amount: ";
    cin >> draw;
    cout << endl;

    if (draw < 0)
    {
        cout << "ERROR: VALUE IS A NEGATIVE NUMBER" << endl
             << "Please enter a value greater than zero: ";
        cin >> draw;
        cout << endl;
    }

    if (salesAmount < LESS_THAN_10_THOU_SALES)
    {
        cout << "Employee receives draw, to the amount of $" << draw << endl;
    }
    else if (salesAmount > LESS_THAN_10_THOU_SALES)
    {
        if(salesAmount > 50_THOU_SALES)
        {
            if(salesAmount > 100_THOU_SALES)
            {
                if(salesAmount > 200_THOU_SALES)
                {
                    if(salesAmount >= 250_THOU_SALES)
                    {
                        commission = salesAmount
                            * 200_THOU_SALES_COMMISSION_PCNT
                            + 250_THOU_SALES_BONUS;
                        cout << "$250,000 CLUB MEMBER!" << endl;
                             << "Employee receives commission, "
                             << "to the amount of $"
                             << commission << endl;
                    }
                }
                else
                {
                    commission = salesAmount * 200_THOU_SALES_COMMISSION_PCNT;
                    cout << "Employee receives commission, to the amount of $"
                         << commission << endl;
                }
            }
            else
            {
                commission = salesAmount * 100_THOU_SALES_COMMISSION_PCNT;
                cout << "Employee receives commission, to the amount of $"
                     << commission << endl;
            }
        }
        else
        {
            commission = salesAmount * 50_THOU_SALES_COMMISSION_PCNT;
            cout << "Employee receives commission, to the amount of $"
                 << commission << endl;
        }
    }

    return 0;
}
