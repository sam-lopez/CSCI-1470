//Samantha Lopez-Montano
//Calculates the charge of a long distance phone call

#include <iostream>
#include <iomanip>

using namespace std;

double const FIXED_COST = 1.15,
			 ADDITIONAL_COST_PER_MIN = .25;

int main()
{
	//Variables
	double minutes,
		   totalCharge;

	cout << "Please enter the length of the telephone call in minutes: ";
	cin >> minutes;

	//Calculates the charge of long distance phone call
	if (minutes > 0 && minutes <= 3)
	{
		totalCharge = FIXED_COST;
	}
	else if (minutes > 3)
	{
		totalCharge = FIXED_COST + ADDITIONAL_COST_PER_MIN * (minutes - 3);
	}
	else
	{
		cout << "\nInvalid number entered. Please enter number over zero." << endl;
		system("pause");
	}

	//Displays the total charge of a long distance phone call
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n\nThe amount of $" << totalCharge << " will be charged to your telephone account for the " << minutes << "-minute call." << endl;
}