//Samantha Lopez-Montano
//Displays and calculates a payroll report 

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Constant variable definitions
const double FED_TAX_RATE = 0.16,
	STATE_TAX_RATE = 0.065;

//Function Prototypes
void getData(int&, string&, double&, double&);
double computeGrossPay(double, double);
void computeDeductions(double, double&, double&);
double computeNetPay(double, double, double);
void displayResults(int, string, double, double, double, double, double, double);

int main()
{
	//Variables
	int idNum;
	string name;
	double hours,
		hourlyRate,
		grossPay,
		federalWitholdings,
		stateWitholdings,
		netPay;
	bool repeat;

	//Repeats program until user stops
	do
	{
		//Function Calls
		getData(idNum, name, hours, hourlyRate);
		grossPay = computeGrossPay(hours, hourlyRate);
		computeDeductions(grossPay, federalWitholdings, stateWitholdings);
		netPay = computeNetPay(grossPay, federalWitholdings, stateWitholdings);
		displayResults(idNum, name, hours, hourlyRate, grossPay, federalWitholdings, stateWitholdings,netPay);
		
		//Prompts user to repeat program
		cout << "Would you like to calculate the net pay of another employee? (1 for Yes, 0 for No) ";
		cin >> repeat;
		cout << endl;
	} while (repeat);
}

//Function Definitions
//Prompts user for ID #, name, hours worked, and hourly rate
void getData(int& idNum, string& name, double& hours, double& hourlyRate)
{
	//Prompts user for valid ID #
	do
	{
		cout << "Please enter the employee's 4-digit ID # and press <Enter>\n";
		cin >> idNum;
		cin.ignore();
		//Displays error message
		if (idNum < 5000 || idNum > 9999)
			cout << "\nERROR: INVALID ID #! MUST BE BETWEEN 5000 AND 9999\n\n";
	} while (idNum < 5000 || idNum > 9999);
	//Prompts user for employee name
	cout << "\nPlease enter the employee's name: \n";
	getline(cin, name);
	//Prompts user for hours worked
	do
	{
		cout << "\nPlease enter the amount of hours worked this week and press <Enter>\n";
		cin >> hours;
		if (hours < 0 || hours > 120)
			cout << "\nERROR: INVALID AMOUNT OF HOURS WORKED! MUST BE BETWEEN 0 AND 120\n";
	} while (hours < 0 || hours > 120);
	//Prompts user for hourly rate
	do
	{
		cout << "\nPlease enter the hourly pay rate for this employee and press <Enter>\n";
		cin >> hourlyRate;
		if (hourlyRate <= 0)
			cout << "\nERROR: INVALID PAY RATE! MUST BE GREATER THAN ZERO\n";
	} while (hourlyRate <= 0);
}

//Calculates the gross pay
double computeGrossPay(double hours, double hourlyRate)
{
	//if hours are over 40, overtime pay is added to normal rate
	if (hours <= 40)
		return hours * hourlyRate;
	else
		return (hours - 40) * (hourlyRate + hourlyRate * 0.5) + hourlyRate * 40;
}

//Calculates the federal and state witholdings
void computeDeductions(double grossPay, double& federalWitholdings, double& stateWitholdings)
{
	federalWitholdings = grossPay * FED_TAX_RATE;
	stateWitholdings = grossPay * STATE_TAX_RATE;
}

//Calculates the net pay
double computeNetPay(double grossPay, double federalWitholdings, double stateWitholdings)
{
	return grossPay - (federalWitholdings + stateWitholdings);
}

//Displays the ID #, hours worked, name, hourly rate, gross pay, federal and state witholdings, and net pay
void displayResults(int idNum, string name, double hours, double hourlyRate, double grossPay, double federalWitholdings, double stateWitholdings, double netPay)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "\nEmployee ID:            " << idNum;
	cout << "\nEmployee Name:          " << name;
	cout << "\nHours Worked:           " << hours << " hours";
	cout << "\nHourly Rate:            $" << hourlyRate;
	cout << "\nGross Pay:              $" << grossPay;
	cout << "\n\nDeductions:";
	cout << "\nFederal Witholding:     $" << federalWitholdings;
	cout << "\nState Witholding:       $" << stateWitholdings;
	cout << "\n\nNET PAY:                $" << netPay << endl << endl;
}