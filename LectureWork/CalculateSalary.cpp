/******************************************************************************
Author        :  Samantha Lopez-Montano                   Course & Section :CSCI 1470

Description   :Prompts the user for the number of hours worked by
an employee, computes and displays the weekly salary.

Input:    hours worked
Process:  if hours worked <= 40 then
             pay = hours worked * 9.25
          else
              pay = (40 * 9.25) + (14.25 * (hours worked - 40))
Output: hours worked, Pay
********************************C**********************************************/

#include <iostream>
#include <iomanip>

using namespace std; //introduces namespace std

const double PAY_RATE = 9.25;               //regular pay rate
const double OVERTIME_RATE = 14.25;     //overtime pay rate
const int REGULAR_HOURS = 40;              //regular hours

//Prototypes (Function Declarations)
double getHours();
double calcSalary(double);
void display(double, double);

int main(void)
{
	//declare and initialize variables
	double hours = 0;
	double salary = 0;

	//Function Calls
	hours = getHours();
	salary = calcSalary(hours);
	display(hours, salary);

	return 0;
}

//Function Definitions
double getHours()
{
	double hours;
	//prompts the user for the employee's hours worked 
	cout << "Please enter the total hours worked and press <Enter>: ";
	cin >> hours;

	return hours;
}

double calcSalary(double hours)
{
	double salary;
	//calculates the weekly salary based on the hours worked
	if (hours <= REGULAR_HOURS)
		salary = PAY_RATE * hours;
	else
		salary = (PAY_RATE * REGULAR_HOURS) + (OVERTIME_RATE * (hours - REGULAR_HOURS));
	
	return salary;
}

void display(double hours, double salary)
{
	//formats the output
	cout << setprecision(2) << fixed << showpoint;
	cout << endl << endl;

	//displays the employee's hours worked and weekly salary earned
	cout << "Hours Worked:   " << hours << endl;
	cout << "Salary:         $" << salary << endl << endl;
}
