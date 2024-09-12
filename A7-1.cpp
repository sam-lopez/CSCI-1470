//Samantha Lopez-Montano
//Displays and calculates the gross pay of an assembly line employee

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Function Prototypes
string getName();
double getTime();
double computePay(double);
void displayPay(string, double, double);

const double HOURLY_WAGE = 7.50;

int main()
{
	string name;
	double time;
	double grossPay;
	char repeat;

	do
	{
	//Function Calls
	name = getName();
	time = getTime();
	grossPay = computePay(time);
	displayPay(name, time, grossPay);

	cout << "\n\nWould you like to calculate another employee's pay (Y or N)? ";
	cin >> repeat;
	cin.ignore();
	cout << endl;
	} while (repeat == 'Y' || repeat ==  'y');
}

//Function Definitions
string getName()
{
	string name;
	//Prompts user for name and saves input
	cout << "Enter the employee's name: ";
	getline(cin, name);

	return name;
}

double getTime()
{
	double time = 0;
	do
	{
	//Prompts user for time worked and saves input
	cout << "Please enter the time worked for this pay period: ";
	cin >> time;
	if (time < 0)
		cout << "\nInvalid Input - Enter Positive Number\n\n";
	} while (time < 0);
	
	return time;
}

double computePay(double time)
{
	double grossPay;
	//Calculates gross pay
	if (time <= 40)
		grossPay = HOURLY_WAGE * time;
	else
		grossPay = HOURLY_WAGE * 40 + (HOURLY_WAGE + HOURLY_WAGE * .5) * (time - 40);

	return grossPay;
}

void displayPay(string name, double time, double grossPay)
{
	//Displays employee name, hours worked, and gross pay
	cout << setprecision(2) << fixed << showpoint;
	cout << "\nEmployee's Name: " << name;
	cout << "\nThe time worked in this pay period is: " << time << " hours";
	cout << "\nThe gross pay earned for this pay period is: $" << grossPay;
}