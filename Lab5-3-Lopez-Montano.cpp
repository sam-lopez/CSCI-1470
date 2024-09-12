//Samantha Lopez-Montano
//Calculates and displays a customer's monthly phone bill

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double PACKAGE_A_MONTH = 39.99,
	A_ADDITIONAL_MINUTE = 0.45,
	PACKAGE_B_MONTH = 59.99,
	B_ADDITIONAL_MINUTE = 0.40,
	PACKAGE_C_MONTH = 69.99;

int main()
{
	//Variables
	string customer_name,
		billing_month;
	int minutes_used,
		package,
		more_minutes;
	double amount_due;

	cout << "Please enter the customer's Name: ";
	getline(cin, customer_name);

	cout << "Please enter the current billing month: ";
	getline(cin, billing_month);

	do
	{
		cout << "How many minutes were used? ";
		cin >> minutes_used;
		if (minutes_used < 0)
		{
			cout << "\nError - minutes must be positive number" << endl << endl;
		}
	} while (minutes_used < 0);

	cout << "Select a subscription package: " << endl << endl;
	cout << "1. Package A" << endl;
	cout << "2. Package B" << endl;
	cout << "3. Package C" << endl;
	cout << "4. Quit" << endl;
	cout << "Menu Option: ";
	cin >> package;

	switch (package)
	{
		case 1:
			//Calculates the amount due for a month
			more_minutes = minutes_used - 450;
			if (more_minutes > 0)
			{
				amount_due = PACKAGE_A_MONTH + (A_ADDITIONAL_MINUTE * more_minutes);
			}
			else
			{
				amount_due = PACKAGE_A_MONTH;
			}
			
			//Displays the customer's phone bill information
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nThe Mobile Phone bill for " << billing_month << endl;
			cout << "Customer's Name: " << customer_name << endl;
			cout << "Minutes Used: " << minutes_used << endl;
			cout << "Amount Due: $" << amount_due << endl;
			break;
		case 2:
			//Calculates the amount due for a month
			more_minutes = minutes_used - 900;
			if (more_minutes > 0)
			{
				amount_due = PACKAGE_B_MONTH + (B_ADDITIONAL_MINUTE * more_minutes);
			}
			else
			{
				amount_due = PACKAGE_B_MONTH;
			}
			
			//Displays the customer's phone bill information
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nThe Mobile Phone bill for " << billing_month << endl;
			cout << "Customer's Name: " << customer_name << endl;
			cout << "Minutes Used: " << minutes_used << endl;
			cout << "Amount Due: $" << amount_due << endl;
			break;
		case 3:
			//Calculates the amount due for a month
			amount_due = PACKAGE_C_MONTH;

			//Displays the customer's phone bill information
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nThe Mobile Phone bill for " << billing_month << endl;
			cout << "Customer's Name: " << customer_name << endl;
			cout << "Minutes Used: " << minutes_used << endl;
			cout << "Amount Due: $" << amount_due << endl;
			break;
		case 4:
			cout << "\nProgram ending." << endl;
			break;
		default:
			cout << "\n\nThe valid choices are 1 through 4." << endl;
			cout << "Run the program again and select one of those." << endl << endl;
	}

}