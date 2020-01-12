// Kyler Rynear
// 1/12/2020
// The purpose of this program is to create a sales receipt
// based on items purchased
#include <iostream>
#include <iomanip>
#include <cstdlib>
const float tax_percent = 0.0925;
using namespace std;

int main()
{
  // container for all prices
  float items[] = {12.95, 33.14, 4.32, 5.18, 23.99};

  // size of array
  int itemsSize = sizeof(items)/sizeof(*items);

  // initializing values
  float subtotal = 0.0;
  float tax = 0.0;
  float total = 0.0;

  // loop to sum contents of array for subtotal
  for (int i=0; i<itemsSize; ++i)
  {
    subtotal += items[i];
  }

  // calculate tax added
  tax = subtotal * tax_percent;

  // add tax to subtotal
  total = subtotal + tax;

  // display results
  cout << fixed << setprecision(2)
       << "Novel"    << setw(10) << "$" << items[0] << endl
       << "Socks"    << setw(10) << "$" << items[1] << endl
       << "Pen"      << setw(12) << "$" << items[2] << endl
       << "Pencil"   << setw(9)  << "$" << items[3] << endl
       << "Album"    << setw(10) << "$" << items[4] << endl
       << "--------------------"                    << endl
       << "Subtotal" << setw(7)  << "$" << subtotal << endl
       << "Tax"      << setw(12) << "$" << tax      << endl
       << "Total"    << setw(10) << "$" << total    << endl;


  return 0;
}
