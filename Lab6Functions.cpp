// Kyler Rynear
// 1/29/2020
// The purpose of this function is g
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
const char ADDITION = '+';
const char SUBTRACTION = '-';
const char MULTIPLICATION = '*';

using namespace std;

void getRandNum(int *rnd)
{
    *rnd = rand() % 9 + 1;
}

bool isAnswerRight(int numberOne, int numberTwo, int userAnswer, char symbol)
{
    int correctAnswer;

    if (symbol == ADDITION)
    {
        correctAnswer = numberOne + numberTwo;
        if (correctAnswer != userAnswer)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (symbol == SUBTRACTION)
    {
        correctAnswer = numberOne - numberTwo;
        if (correctAnswer != userAnswer)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (symbol == MULTIPLICATION)
    {
        correctAnswer = numberOne * numberTwo;
        if (correctAnswer != userAnswer)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}

void add(int numberOne, int numberTwo)
{
    int userAnswer;
    bool answerCheck;

    cout << "Add the two numbers together. Your answer: ";
    cin >> userAnswer;
    cout << endl;
    answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, ADDITION);

    while (!answerCheck)
    {
        cout << "Answer incorrect. Please enter correct answer: ";
        cin >> userAnswer;
        cout << endl;
        answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, ADDITION);
    }
    cout << "Correct!" << endl;

    return;
}

void subtract(int numberOne, int numberTwo)
{
    int userAnswer;
    bool answerCheck;

    cout << "Subtract the two numbers. Your answer: ";
    cin >> userAnswer;
    cout << endl;
    answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, SUBTRACTION);

    while (!answerCheck)
    {
        cout << "Answer incorrect. Please enter correct answer: ";
        cin >> userAnswer;
        cout << endl;
        answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, SUBTRACTION);
    }
    cout << "Correct!" << endl;

    return;
}

void multiply(int numberOne, int numberTwo)
{
    int userAnswer;
    bool answerCheck;

    cout << "Multiply the two numbers. Your answer: ";
    cin >> userAnswer;
    cout << endl;
    answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, MULTIPLICATION);

    while (!answerCheck)
    {
        cout << "Answer incorrect. Please enter correct answer: ";
        cin >> userAnswer;
        cout << endl;
        answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, MULTIPLICATION);
    }
    cout << "Correct!" << endl;

    return;
}


int main()
{

    int randNumOne;
    int randNumTwo;
    char retryAnswer;
    bool retrySignal = 0;

    srand(time(0));

    do
    {
        getRandNum(&randNumOne);
        getRandNum(&randNumTwo);

        cout << "The two random numbers are " << randNumOne << " and "
             << randNumTwo << endl;

        add(randNumOne, randNumTwo);
        subtract(randNumOne, randNumTwo);
        multiply(randNumOne, randNumTwo);

        cout << "You've answered all of them correctly! Congratulations! "
             << "\nWould you like to try again? Please enter Y or N: ";
        cin >> retryAnswer;
        cout << endl;

        while (retryAnswer != 'Y' && retryAnswer != 'y' && retryAnswer != 'N' && retryAnswer != 'n')
        {
            cout << "ERROR: Incorrect Response. Please enter Y or N: ";
            cin >> retryAnswer;
            cout << endl;
        }

        if (retryAnswer == 'Y' || retryAnswer == 'y')
        {
            retrySignal = 1;
        }
        else if (retryAnswer == 'N' || retryAnswer == 'n')
        {
            retrySignal = 0;
        }
    } while (retrySignal);

    return 0;
}
