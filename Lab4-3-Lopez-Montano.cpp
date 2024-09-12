//Samantha Lopez-Montano
//Calculates and displays an invoice for customers of a software company

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double const SALES_TAX = .085, 
			 PACKAGE_COST = 50.99;

int main()
{
	//Variables
	string customerName;
	int quantity;
	double softwareSales,
		   discountPercent, 
		   discountPrice, 
		   totalSales,
		   totalTax,
		   totalPurchase;

	cout << "Please enter the Customer's Name: ";
	getline(cin, customerName);
	cout << "Please enter the total number of software package(s) purchased: ";
	cin >> quantity;

	//Calculates which if any discount is applied
	if (quantity >= 1 && quantity <= 10)
	{
		discountPercent = 0.0;

	}
	else if (quantity > 10 && quantity <= 20)
	{
		discountPercent = 20.00;
	}
	else if (quantity > 20 && quantity <= 50)
	{
		discountPercent = 30.00;
	}
	else if (quantity > 50 && quantity <= 100)
	{
		discountPercent = 40.00;
	}
	else if (quantity > 100)
	{
		discountPercent = 50.00;
	}
	else
	{
		cout << "\nInvalid input. Number of packages must be over zero." << endl;
		system("pause");
	}

	//Calculates software sales, discount price, total sales, total tax, and total purchase
	softwareSales = quantity * PACKAGE_COST;
	discountPrice = (discountPercent / 100) * softwareSales;
	totalSales = softwareSales - discountPrice;
	totalTax = SALES_TAX * totalSales;
	totalPurchase = totalSales + totalTax;

	//Displays customer invoice
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n\nINVOICE for " << customerName << endl << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Discount: " << discountPercent << "%" << endl << endl;
	cout << "Software Cost (26 packages at $50.99 each)............$" << softwareSales << endl;
	cout << "Discount..............................................$" << discountPrice << endl;
	cout << "                                                      --------" << endl;
	cout << "Total Sales...........................................$" << totalSales << endl;
	cout << "Sales Tax.............................................$" << totalTax << endl;
	cout << "                                                      --------" << endl;
	cout << "Total Purchase........................................$" << totalPurchase << endl << endl;
}