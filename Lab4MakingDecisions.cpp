// Kyler Rynear
// 1/21/20
// The purpose of this program is to determine what pay goes to
// sales representatives
#include <iostream>
#include <cstdlib>
#include <iomanip>
const double LESS_THAN_TEN_THOU_SALES = 9999;
const double FIFTY_THOU_SALES = 49999;
const double FIFTY_THOU_SALES_COMMISSION_PCNT = 0.01;
const double HUNDRED_THOU_SALES = 99999;
const double HUNDRED_THOU_SALES_COMMISSION_PCNT = 0.02;
const double TWOHUN_THOU_SALES = 199999;
const double TWOHUN_THOU_SALES_COMMISSION_PCNT = 0.03;
const double OVER_TWOHUN_SALES = 200000;
const double OVER_TWOHUN_SALES_COMMISSION_PCNT = 0.04;
const double TWOFIFTY_THOU_SALES = 250000;
const double TWOFIFTY_THOU_SALES_BONUS = 500;
using namespace std;

int main()
{
    double salesAmount;
    double draw;
    double commission;

    cout << fixed << setprecision(2);
    cout << "Enter Sales amount: $";
    cin >> salesAmount;
    cout << endl;

    if(salesAmount < 0)
    {
        cout << "ERROR: VALUE IS A NEGATIVE NUMBER" << endl
             << "Please enter a value greater than zero: $";
        cin >> salesAmount;
        cout << endl;
    }

    cout << "Enter draw amount: $";
    cin >> draw;
    cout << endl;

    if (draw < 0)
    {
        cout << "ERROR: VALUE IS A NEGATIVE NUMBER" << endl
             << "Please enter a value greater than zero: $";
        cin >> draw;
        cout << endl;
    }

    if (salesAmount < LESS_THAN_TEN_THOU_SALES)
    {
        cout << "Employee receives draw, to the amount of $" << draw << endl;
    }
    else if (salesAmount > LESS_THAN_TEN_THOU_SALES)
    {
        if(salesAmount > FIFTY_THOU_SALES)
        {
            if(salesAmount > HUNDRED_THOU_SALES)
            {
                if(salesAmount > TWOHUN_THOU_SALES)
                {
                    if(salesAmount >= TWOFIFTY_THOU_SALES)
                    {
                        commission = salesAmount
                            * TWOHUN_THOU_SALES_COMMISSION_PCNT
                            + TWOFIFTY_THOU_SALES_BONUS;
                        cout << "$250,000 CLUB MEMBER!" << endl
                             << "Employee receives commission, "
                             << "to the amount of $"
                             << commission << endl;
                    }
                }
                else
                {
                    commission = salesAmount * TWOHUN_THOU_SALES_COMMISSION_PCNT;
                    cout << "Employee receives commission, to the amount of $"
                         << commission << endl;
                }
            }
            else
            {
                commission = salesAmount * HUNDRED_THOU_SALES_COMMISSION_PCNT;
                cout << "Employee receives commission, to the amount of $"
                     << commission << endl;
            }
        }
        else
        {
            commission = salesAmount * FIFTY_THOU_SALES_COMMISSION_PCNT;
            cout << "Employee receives commission, to the amount of $"
                 << commission << endl;
        }
    }

    return 0;
}
