//Samantha Lopez-Montano
//Calculates and displays the division of two positive integers

#include <iostream>

using namespace std;

//Function Prototypes
void getIntegers(int&, int&);
void findLargeAndSmall(int, int, int&, int&);
int calcQuotient(int, int);
int calcRemainder(int, int);
void displayResults(int, int, int, int);


int main()
{
	//Variable
	int num1,
		num2,
		larger,
		smaller,
		quotient,
		remainder;
	bool repeat;

	//Repeats program until user stops
	do
	{
		//Function Calls
		getIntegers(num1, num2);
		findLargeAndSmall(num1, num2, larger, smaller);
		quotient = calcQuotient(larger, smaller);
		remainder = calcRemainder(larger, smaller);
		displayResults(larger, smaller, quotient, remainder);

		//Prompts user to repeat program
		cout << "Would you like to process another set of numbers? (1 for Yes, 0 for No) ";
		cin >> repeat;
		cout << endl;
	} while (repeat);
}

//Function Definitions
//Prompts user for two positive integers
void getIntegers(int& num1, int& num2)
{
	cout << "******************************************************************";
	cout << "\n*    This program will ask you to enter two positive integers.   *";
	cout << "\n*     It will divide the large by the smaller and display the    *";
	cout << "\n*               result as a quotient and remainder.              *";
	cout << "\n******************************************************************";
	//Prompts user for first positive integer
	do
	{
		cout << "\nPlease enter your first integer and press <Enter>: ";
		cin >> num1;
	} while (num1 < 0);
	//Prompts user for second positive integer
	do
	{
		cout << "Please enter your second integer and press <Enter>: ";
		cin >> num2;
	} while (num2 < 0);
}

//Determines which integer is larger and smaller
void findLargeAndSmall(int num1, int num2, int& larger, int& smaller)
{
	if (num1 > num2)
	{
		larger = num1;
		smaller = num2;
	}
	else
	{
		larger = num2;
		smaller = num1;
	}
}

//Calculates and returns the quotient of the larger number divided by the smaller
int calcQuotient(int larger, int smaller)
{
	return larger / smaller;
}

//Calculates and returns the remainder of the larger number divided by the smaller 
int calcRemainder(int larger, int smaller)
{
	return larger % smaller;
}

//Displays the quotient and remainder of the division
void displayResults(int larger, int smaller, int quotient, int remainder)
{
	cout << "\nThe answer for " << larger << "/" << smaller << " is " << quotient << " R " << remainder << endl << endl;
}