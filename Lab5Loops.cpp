// Kyler Rynear
// 1/25/20
// The purpose of this program is to calculate inventory for a wine cellar
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

const int EMPTY_RACK = 5;
const int TWO_DECIMAL_PLACES = 100;
const string LINE = "---------------------------------";


int main()
{

    cout << endl;
    cout << "The purpose of this program is to assist a Vineyard with their "
         << "inventory. The user will provide the number of racks in the cellar, "
         << "the number of cubes in each rack, and how many bottles are in each "
         << "rack. We will then provide the number of total bottles, total "
         << "cubes, number of empty cubes, and percentage full of inventory."
         << endl << endl;

    int inputRacks;
    int totalRacks;
    int numOfEmptyRacks = 0;
    double emptyRackCounter = 1;
    int squaresPerRack = 0;
    double totalSquares = 0;
    int bottlesPerRack = 0;
    double totalBottles = 0;
    int totalEmptyCubes = 0;
    double inventoryPercentageFull = 0;
    vector<int> rackSizeCounter;

    // initial user input to receive number of racks total
    cout << "Enter the number of racks in the wine cellar: ";
    cin >> inputRacks;
    cout << endl;

    // check for value less than or equal to zero
    while (inputRacks <= 0)
    {
        cout << "Please enter a value greater than zero: ";
        cin >> inputRacks;
        cout << endl;
    }

    // loop to find number of squares in each rack
    for (int i = 0; i < inputRacks; i++)
    {
        // check if on fifth column, skip if true
        if((emptyRackCounter / EMPTY_RACK) != 1)
        {
            cout << "Enter number of squares in rack " << i+1 << ": ";
            cin >> squaresPerRack;
            cout << endl;
            // check for zero or negative number
            while (squaresPerRack <= 0)
            {
                cout << "Please enter a value greater than zero: ";
                cin >> squaresPerRack;
                cout << endl;
            }
            // add iteration amount to total amount
            totalSquares += squaresPerRack;
            // log size of rack at iteration
            rackSizeCounter.push_back(squaresPerRack);
        }
        else
        {
            // on fifth column, size is zero for logging purposes
            rackSizeCounter.push_back(0);
        }
        // increment counter that checks for empty rack
        emptyRackCounter++;
    }

    // reset counter for next user input
    emptyRackCounter = 1;
    cout << LINE << endl;

    // loop to find amount of bottles in each rack
    for (int i = 0; i < inputRacks; i++)
    {
        // check if fifth rack, skip if true
        if((emptyRackCounter / EMPTY_RACK) != 1)
        {
            cout << "Enter number of bottles in rack " << i+1 << ": ";
            cin >> bottlesPerRack;
            cout << endl;

            // check if value is negative number
            while (bottlesPerRack < 0)
            {
                cout << "Please enter a value of zero or greater: ";
                cin >> bottlesPerRack;
                cout << endl;
            }

            // check if number of bottles is greater than size of rack
            while (bottlesPerRack > rackSizeCounter.at(i))
            {
                cout << "Please enter an amount for bottles that is less than "
                     << "the size of rack " << i+1 << " (size is "
                     << rackSizeCounter.at(i) << "): ";
                cin >> bottlesPerRack;
                cout << endl;
            }

            // add iteration number to total count
            totalBottles += bottlesPerRack;
        }

        // increment rack counter to check for empty rack
        emptyRackCounter++;
    }

    // find the remaining total of empty cubes
    totalEmptyCubes = totalSquares - totalBottles;

    // find percentage full of inventory
    inventoryPercentageFull = (totalBottles/totalSquares) * TWO_DECIMAL_PLACES;

    // print results
    cout << fixed << setprecision(0);
    cout << "Total number of cubes: " << totalSquares << endl;
    cout << "Total number of bottles: " << totalBottles << endl;
    cout << "Number of empty cubes: " << totalEmptyCubes << endl;
    cout << fixed << setprecision(2);
    cout << "The cellar is " << inventoryPercentageFull << "% full." << endl;

    return 0;

}
