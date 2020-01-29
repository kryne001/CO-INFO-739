// Kyler Rynear
// 1/29/2020
// The purpose of this function is g
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
// constant chars for passing into answer checking function
const char ADDITION = '+';
const char SUBTRACTION = '-';
const char MULTIPLICATION = '*';

using namespace std;

//function is called main to generate a random number
void getRandNum(int *rnd)
{
    // generate a number between 1 and 9
    *rnd = rand() % 9 + 1;
}

// function takes the two random numbers as input, the user answer, and the
// whether it's addition, subtraction, or multiplication. will return 0 for
// false or 1 for true
bool isAnswerRight(int numberOne, int numberTwo, int userAnswer, char symbol)
{
    int correctAnswer;

    // addition check
    if (symbol == ADDITION)
    {
        correctAnswer = numberOne + numberTwo;
        if (correctAnswer != userAnswer)
        {
            // return false for incorrect answer
            return 0;
        }
        else
        {
            // return true
            return 1;
        }
    }
    // subtration check
    else if (symbol == SUBTRACTION)
    {
        correctAnswer = numberOne - numberTwo;
        if (correctAnswer != userAnswer)
        {
            // return false for incorrect answer
            return 0;
        }
        else
        {
            // return true
            return 1;
        }
    }
    // multiplication check
    else if (symbol == MULTIPLICATION)
    {
        correctAnswer = numberOne * numberTwo;
        if (correctAnswer != userAnswer)
        {
            // return false for incorrect answer
            return 0;
        }
        else
        {
            // return true
            return 1;
        }
    }

    return 0;
}

// function handles the add task by taking in the random numbers, prompting
// the user for their answer, then checking the answer using the isAnswerRight
// function. If wrong, will loop until right answer is given
void add(int numberOne, int numberTwo)
{
    int userAnswer;
    bool answerCheck;

    cout << "Add the two numbers together. Your answer: ";
    cin >> userAnswer;
    cout << endl;
    // user answerCheck function to compare user answer to correct answer
    answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, ADDITION);

    // check if isAnswerRight function returned false, iterate until function
    // returns true
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

// function handles the subtract task by taking in the random numbers, prompting
// the user for their answer, then checking the answer using the isAnswerRight
// function. If wrong, will loop until right answer is given
void subtract(int numberOne, int numberTwo)
{
    int userAnswer;
    bool answerCheck;

    cout << "Subtract the two numbers. Your answer: ";
    cin >> userAnswer;
    cout << endl;
    // user answerCheck function to compare user answer to correct answer
    answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, SUBTRACTION);

    // check if isAnswerRight function returned false, iterate until function
    // returns true
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

// function handles the multiply task by taking in the random numbers, prompting
// the user for their answer, then checking the answer using the isAnswerRight
// function. If wrong, will loop until right answer is given
void multiply(int numberOne, int numberTwo)
{
    int userAnswer;
    bool answerCheck;

    cout << "Multiply the two numbers. Your answer: ";
    cin >> userAnswer;
    cout << endl;
    // user answerCheck function to compare user answer to correct answer
    answerCheck = isAnswerRight(numberOne, numberTwo, userAnswer, MULTIPLICATION);

    // check if isAnswerRight function returned false, iterate until function
    // returns true
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

    cout << "The purpose of this program is to generate two random numbers "
         << "and ask the user to add, subtract, and multiply the two number "
         << "together. The program will check the user's answer, and if wrong "
         << "will ask them to resubmit an answer until correct. It will then "
         << "prompt the user to try again, and if they decide to, will generate "
         << "a new set of random numbers and go again." << endl;

    do
    {
        // call getRandNum twice to produce two random numbers, assign values
        // by reference
        getRandNum(&randNumOne);
        getRandNum(&randNumTwo);

        cout << "The two random numbers are " << randNumOne << " and "
             << randNumTwo << endl;

        // call add, subtract, multiply functions
        add(randNumOne, randNumTwo);
        subtract(randNumOne, randNumTwo);
        multiply(randNumOne, randNumTwo);

        // completed all three tasks, check if user wants to go again
        cout << "You've answered all of them correctly! Congratulations! "
             << "\nWould you like to try again? Please enter Y or N: ";
        cin >> retryAnswer;
        cout << endl;

        // check for correct entry of Y, y or N, n
        while (retryAnswer != 'Y' && retryAnswer != 'y' && retryAnswer != 'N' && retryAnswer != 'n')
        {
            cout << "ERROR: Incorrect Response. Please enter Y or N: ";
            cin >> retryAnswer;
            cout << endl;
        }

        // if yes, change signal to 1 to restart program, if no 0 to terminate
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
