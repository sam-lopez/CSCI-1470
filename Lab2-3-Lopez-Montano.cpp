//Samantha Lopez-Montano
//Calculates the change for coins

#include <iostream>
using namespace std;

int main()
{
	//Variable
	int numberOfPennies, 
		numberOfNickels, 
		numberOfDimes, 
		numberOfQuarters, 
		numberOfHalfDollars, 
		numberOfOneDollars;
	const double pennyWorth = 0.01, 
		nickelWorth = 0.05, 
		dimeWorth = 0.10, 
		quarterWorth = 0.25, 
		halfDollarWorth = 0.50, 
		oneDollarWorth = 1.00;
	double totalChange;

	cout << "Enter the number of pennies: ";
	cin >> numberOfPennies;
	cout << "Enter the number of nickels: ";
	cin >> numberOfNickels;
	cout << "Enter the number of dimes: ";
	cin >> numberOfDimes;
	cout << "Enter the number of quarters: ";
	cin >> numberOfQuarters;
	cout << "Enter the number of half-dollars: ";
	cin >> numberOfHalfDollars;
	cout << "Enter the number of one-dollars: ";
	cin >> numberOfOneDollars;

	//Calculates total change
	totalChange = (numberOfPennies * pennyWorth) + 
		(numberOfNickels * nickelWorth) + 
		(numberOfDimes * dimeWorth) + 
		(numberOfQuarters * quarterWorth) + 
		(numberOfHalfDollars * halfDollarWorth) + 
		(numberOfOneDollars * oneDollarWorth);

	//Displays change and total change
	cout << "\n\nYou have: " << endl;
	cout << numberOfPennies << " pennies" << endl;
	cout << numberOfNickels << " nickels" << endl;
	cout << numberOfDimes << " dimes" << endl;
	cout << numberOfQuarters << " quarters" << endl;
	cout << numberOfHalfDollars << " half-dollars" << endl;
	cout << numberOfOneDollars << " one-dollars" << endl;
	cout << "for a total of $" << totalChange << endl;
}