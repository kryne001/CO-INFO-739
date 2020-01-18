// Kyler Rynear
// 1/17/2020
// The purpose of this program is to find the number of circles that can fit
// inside a square. Length of square side and diameter length will be
// provided by user.
#include <iostream>
#include <iomanip>
#include <cstdlib>
const double PI = 3.14159265358979;
const int DEMICAL_PLACE = 2;
using namespace std;

int main()
{
    double squareSide;
    double circleDiameter;
    double squareArea;
    double circleArea;
    double numOfCircles;
    double circleRadius;

    cout << "Enter the length of a side of the square: ";
    cin >> squareSide;
    cout << endl;

    cout << "Enter the diameter of the circle: ";
    cin >> circleDiameter;
    cout << endl;

    squareArea = squareSide * squareSide;
    circleRadius = circleDiameter / 2;
    circleArea = PI * (circleRadius * circleRadius);
    numOfCircles = squareArea / circleArea;

    cout << fixed << setprecision(DECIMAL_PLACE);

    cout << "There are " << numOfCircles
         << " circles that can fit inside this square." << endl;


    return 0;
}
