// Samantha Lopez-Montano

/* Example of an extended if statement(the if - else chain or if-else if):
	Calculate the monthly income of a salesperson by using the following commission schedule :

Monthly Sales and Income Earned
Greater than or equal to $50, 000 -> $375 plus 16 % of sales
Less than $50, 000 but greater than or equal to  $40, 000 -> $350 plus 14 % sales
Less than $40, 000 but greater than or equal to $30, 000 ->	$325 plus 12 % sales
Less than $30, 000 but greater than or equal to $20, 000 ->	$300 plus 9 % sales
Less than $20, 000 but greater than or equal to $10, 000 ->	$250 plus 5 % of sales
Less than $10, 000	$200 plus 3 % of sales
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(void)
{
	//stores salesperson’s name, monthly sales and calculated income
	double monthly_sales = 0.0, income = 0.0;
	string salesperson_name;

	//Prompts user for salesperson's name & sales
	cout << "Please enter the salesperson's name: ";
	getline(cin, salesperson_name);
	cout << "Enter the value of monthly sales: " << endl;
	cin >> monthly_sales;
	
	//Calculates salesperson's income using Logical AND &&
	if(monthly_sales >= 50000)
		   income = 375.00 + .16 * monthly_sales;
	else if(monthly_sales < 50000 && monthly_sales >= 40000)
		   income = 350.00 + .14 * monthly_sales;
	else if(monthly_sales < 40000 && monthly_sales >= 30000)
		   income = 325.00 + .12 * monthly_sales;
	else if(monthly_sales < 30000 && monthly_sales >= 20000)
			income = 300.00 + .09 * monthly_sales;
	else if(monthly_sales < 20000 && monthly_sales >= 10000)
			income = 250.00 + .05 * monthly_sales;
	else if(monthly_sales < 10000 && monthly_sales > 0)
			income = 200.00 + .03 * monthly_sales;
	else
			cout << "ERROR!!! A negative amount was entered." << endl;


//Displays salesperson's name & income 
	cout << setprecision(2) << fixed << showpoint;
	cout << salesperson_name << " has earned a total monthly income of $"
		<< income << endl << " based on monthly sales of $" << monthly_sales;

	return 0;
}

/*
1st I/O test:
Please enter the salesperson's name: Mary Hill
Enter the value of monthly sales :
36243.89

Mary Hill has earned a total monthly income of $4674.27
based on monthly sales of $36243.89

2nd I/O test:
Please enter the salesperson’s name : Karen Smith
Enter the value of monthly sales :
45000

Karen Smith has earned a total monthly income of $6650.00
based on monthly sales of $45000.00
*/


/* 
//Calculates salesperson's income
	if (monthly_sales >= 50000.00)
		income = 375.00 + .16 * monthly_sales;
	else if (monthly_sales >= 40000.00)
		income = 350.00 + .14 * monthly_sales;
	else if (monthly_sales >= 30000.00)
		income = 325.00 + .12 * monthly_sales;
	else if (monthly_sales >= 20000.00)
		income = 300.00 + .09 * monthly_sales;
	else if (monthly_sales >= 10000.00)
		income = 250.00 + .05 * monthly_sales;
	else income = 200.00 + .03 * monthly_sales;

	//Calculates salesperson's income using Logical AND &&
	if(monthly_sales >= 50000)
		   income = 375.00 + .16 * monthly_sales;
	else if(monthly_sales < 50000 && monthly_sales >= 40000)
		   income = 350.00 + .14 * monthly_sales;
	else if(monthly_sales < 40000 && monthly_sales >= 30000)
		   income = 325.00 + .12 * monthly_sales;
	else if(monthly_sales < 30000 && monthly_sales >= 20000)
			income = 300.00 + .09 * monthly_sales;
	else if(monthly_sales < 20000 && monthly_sales >= 10000)
			income = 250.00 + .05 * monthly_sales;
	else if(monthly_sales < 10000 && monthly_sales > 0)
			income = 200.00 + .03 * monthly_sales;
	else
			cout << "ERROR!!! A negative amount was entered." << endl;
*/
