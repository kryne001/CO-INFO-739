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
    cout << fixed << setprecision(2);
    cout << "The purpose of this program is to assist a Vineyard with their "
         << "inventory. The user will provide the number of racks desired, "
         << "the number of squares in each rack, and how many bottles in each "
         << "rack. We will then calculate the number of total bottles, total "
         << "cubes, number of empty cubes, and ratio of full to empty cubes."
         << endl << endl;

    int inputRacks;
    int totalRacks;
    int numOfEmptyRacks = 0;
    double emptyRackCounter = 1;
    int squaresPerRack = 0;
    int totalSquares = 0;
    int bottlesPerRack = 0;
    int totalBottles = 0;
    int totalEmptyCubes = 0;
    int inventoryPercentageFull = 0;
    vector<int> rackSizeCounter;


    cout << "Enter the number of racks in the wine cellar: ";
    cin >> inputRacks;
    cout << endl;

    while (inputRacks < 0)
    {
        cout << "Please enter a value of zero or greater: ";
        cin >> inputRacks;
        cout << endl;
    }


    for (int i = 0; i < inputRacks; i++)
    {

        if((emptyRackCounter / EMPTY_RACK) != 1)
        {
            cout << "Enter number of squares in rack " << i+1 << ": ";
            cin >> squaresPerRack;
            cout << endl;
            while (squaresPerRack < 0)
            {
                cout << "Please enter a value of zero or greater: ";
                cin >> squaresPerRack;
                cout << endl;
            }
            totalSquares += squaresPerRack;
            rackSizeCounter.push_back(squaresPerRack);
        }
        else
        {
            rackSizeCounter.push_back(0);
        }
        emptyRackCounter++;
    }

    emptyRackCounter = 1;

    for (int i = 0; i < inputRacks; i++)
    {
        if((emptyRackCounter / EMPTY_RACK) != 1)
        {
            cout << "Enter number of bottles in rack " << i+1 << ": ";
            cin >> bottlesPerRack;
            cout << endl;
            while (bottlesPerRack < 0)
            {
                cout << "Please enter a value of zero or greater: ";
                cin >> bottlesPerRack;
                cout << endl;
            }
            while (bottlesPerRack > rackSizeCounter.at(i))
            {
                cout << "Please enter an amount for bottles that is less than "
                     << "the size for the rack: ";
                cin >> bottlesPerRack;
                cout << endl;
            }
            totalBottles += bottlesPerRack;
        }
        emptyRackCounter++;
    }

    totalEmptyCubes = totalSquares - totalBottles;
    inventoryPercentageFull = (totalBottles/totalSquares) * TWO_DECIMAL_PLACES;

    cout << "Total number of cubes: " << totalSquares << endl;
    cout << "Total number of bottles: " << totalBottles << endl;
    cout << "Number of empty cubes: " << totalEmptyCubes << endl;
    cout << "The cellar is " << inventoryPercentageFull << "% full." << endl;

}
