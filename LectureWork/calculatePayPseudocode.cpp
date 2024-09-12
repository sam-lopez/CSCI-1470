//Samantha Lopez-Montano
/* Calculates an employee's total pay for 2 weeks of work.
All employees make $10.25 per hour

Input: Employee Name, Week 1 hours, and Week 2 hours

Process: Calculate Week 1 pay = Week 1 hours worked X Pay Rate
Calculate Week 2 pay = Week 2 hours worked X Pay Rate
Calculate Total Pay = Week 1 Pay + Week 2 Pay

Output: Employee Name, Week 1 Pay, Week 2 Pay, and Total Pay */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Employee Pay rate per hour
const double PAY_RATE = 10.25;

int main()
{
	//Variables needed
	string name;
	double week1_hours, week2_hours;
	double week1_pay, week2_pay, total_pay;

	//Prompt for employee's name
	cout << "enter Employee's name: ";

	//Get employee's name from user
	getline(cin, name);

	//Prompt user for Week 1 hours worked
	cout << "Enter Week 1 hours: ";

	//Get Week 1 hours worked from user
	cin >> week1_hours;

	//Get Week 2 hours worked from user
	cout << "Enter Week 1 hours: ";
	cin >> week2_hours;

	//Calculate Week 1 pay
	week1_pay = week1_hours * PAY_RATE;

	//Calculate Week 2 pay
	week2_pay = week2_hours * PAY_RATE;

	//Calculate Total Pay
	total_pay = week1_pay + week2_pay;

	//Format output
	cout << setprecision(2) << fixed;

	//Display Employee's Pay Information
	cout << "\n\nEmployee's Name: " << name << endl;
	cout << "Week 1 Pay: " << week1_pay << endl;
	cout << "Week 2 Pay: " << week2_pay << endl;
	cout << "Total Pay: " << total_pay << endl << endl;

	system("pause");
}