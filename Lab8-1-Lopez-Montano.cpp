//Samantha Lopez-Montano
//Computes and displays a customer's bill at an All-You-Can-Eat Buffet Restaurant

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Constant variable definitions
const double ADULT_CHARGE = 6.00,
	CHILD_CHARGE = 3.00,
	DESSERT_CHARGE = 1.00,
	GRATUITY_CHARGE = 0.15,
	TAX_RATE = 0.065;

//Funtion Prototypes
void customerInfo(string&, string&, int&, int&, int&);
void calcBill(int, int, int, double&, double&, double&, double&, double&, double&, double&);
void displayBill(string, string, int, int, int, double, double, double, double, double, double, double);

int main()
{
	//Variables
	string date,
		name;
	int adultNum,
		kidNum,
		dessertNum;
	double adultCost,
		childCost,
		dessertCost,
		taxCost,
		subtotal,
		gratuityCost,
		total;
	bool repeat;

	//Repeats program until user stops
	do
	{
		//Function Calls
		customerInfo(date, name, adultNum, kidNum, dessertNum);
		calcBill(adultNum, kidNum, dessertNum, adultCost, childCost, dessertCost, taxCost, subtotal, gratuityCost, total);
		displayBill(date, name, adultNum, kidNum, dessertNum, adultCost, childCost, dessertCost, taxCost, subtotal, gratuityCost, total);

		//Prompts user to repeat program
		cout << "Would you like to process another customer's bill (1 for YES, 0 for NO)? ";
		cin >> repeat;
		cin.ignore();
		cout << endl;
	} while (repeat);
}

//Prompts and stores customer information
void customerInfo(string& date, string& name, int& adultNum, int& kidNum, int& dessertNum)
{
	cout << "Please enter the following Customer's Information. ";
	//Prompts user for date of the bill and stores input
	cout << "\nDate: ";
	getline(cin, date);
	//Prompts user for customer's name and stores input
	cout << "Customer's Name: ";
	getline(cin, name);
	//Prompts user for number of adult meals
	do
	{
		cout << "Number of Adult Meals: ";
		cin >> adultNum;
		//Displays error message if meals are outside of range
		if (adultNum < 0)
			cout << "\nAdult meals must not be negative.\n\n";
	} while (adultNum < 0);
	//Prompts user for number of child meals
	do
	{
		cout << "Number of Child Meals: ";
		cin >> kidNum;
		//Displays error message if meals are outside of range
		if (kidNum < 0)
			cout << "\nChild meals must not be negative.\n\n";
	} while (kidNum < 0);
	//Prompts user for number of desserts
	do
	{
		cout << "Number of Desserts: ";
		cin >> dessertNum;
		//Displays error message if meals are outside of range
		if (dessertNum < 0)
			cout << "\nDessert meals must not be negative.\n";
	} while (dessertNum < 0);
}

//Calculates a customer's bill
void calcBill(int adultNum, int kidNum, int dessertNum, double& adultCost, double& childCost, double& dessertCost, double& taxCost, double& subtotal, double& gratuityCost, double& total)
{
	//Calculates the adult cost of a meal
	adultCost = ADULT_CHARGE * adultNum;
	//Calculates the child cost of a meal
	childCost = CHILD_CHARGE * kidNum;
	//Calculates the dessert cost
	dessertCost = DESSERT_CHARGE * dessertNum;
	//Calculates the tax cost
	taxCost = TAX_RATE * (adultCost + childCost + dessertCost);
	//Calculates the subtotal
	subtotal = adultCost + childCost + dessertCost + taxCost;
	//Calculates the gratuity
	gratuityCost = GRATUITY_CHARGE * subtotal;
	//Calculates the total
	total = subtotal + gratuityCost;
}

//Displays a customer's info and bill
void displayBill(string date, string name, int adultNum, int kidNum, int dessertNum, double adultCost, double childCost, double dessertCost, double taxCost, double subtotal, double gratuityCost, double total)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "\nThe All-You-Can-Eat Buffet Restaurant";
	cout << "\n\nDate: " << date;
	cout << "\nCustomer's Name: " << name;
	cout << "\n\nAdult Meal Charge: " << adultNum << " @ " << ADULT_CHARGE << " each    $" << adultCost;
	cout << "\nChild Meal Charge: " << kidNum << " @ " << CHILD_CHARGE << " each    $" << childCost;
	cout << "\nDessert Charge:    " << dessertNum << " @ " << DESSERT_CHARGE << " each    $" << dessertCost;
	cout << "\nTaxes:                              $" << taxCost;
	cout << "\n\tSubtotal:                          $" << subtotal;
	cout << "\n\nGratuity Charge: (15.00%)                  $" << gratuityCost;
	cout << "\n\nTOTAL DUE:                                 $" << total;
	cout << "\n\nThank you for eating at the All-You-Can-Eat Buffet Restaurant.";
	cout << "\nPlease come again!" << endl <<endl;
}