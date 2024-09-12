//Samantha Lopez-Montano
//Determines if the integer entered is odd or even and positive or negative

#include <iostream>

using namespace std;

//Function Prototypes
int getNumber();
string determineEvenOrOdd(int);
string determinePositiveOrNegative(int);
void displayResults(int, string, string);

int main()
{
	int number;
	string evenOrOdd;
	string positiveOrNegative;
	char repeat;

	do
	{
		//Function Calls
		number = getNumber();
		evenOrOdd = determineEvenOrOdd(number);
		positiveOrNegative = determinePositiveOrNegative(number);
		displayResults(number, evenOrOdd, positiveOrNegative);

		cout << "\n\nWould you like to process another number (Y or N)? ";
		cin >> repeat;
		cin.ignore();
		cout << endl;
	} while (repeat == 'y' || repeat == 'Y');
}

//Function Definitons
int getNumber()
{
	int number;
	do
	{
	//Promputs user for number and saves input
	cout << "Please enter the number to be determined as even/odd or positive/negative: ";
	cin >> number;
	if (number < -10000 || number > 10000)
		cout << "\nInvalid input - Enter number from -10,000 to 10,000\n\n";
	} while (number < -10000 || number > 10000);

	return number;
}

string determineEvenOrOdd(int number)
{
	string evenOrOdd;
	//Determines if number entered is even or odd
	if (number % 2 == 0)
		evenOrOdd = "even";
	else
		evenOrOdd = "odd";
	
	return evenOrOdd;
}

string determinePositiveOrNegative(int number)
{
	string positiveOrNegative;
	//Determines if number entered is positive or negative
	if (number >= 0)
		positiveOrNegative = "positive";
	else
		positiveOrNegative = "negative";

	return positiveOrNegative;
}

void displayResults(int number, string evenOrOdd, string positiveOrNegative)
{
	//Displays the number entered, if it is even or odd, and if it is positive or negative
	cout << "\nThe number you entered, " << number << " is a " 
		<< positiveOrNegative << ", " << evenOrOdd << " value.";
}