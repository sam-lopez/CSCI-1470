//Samantha Lopez-Montano
//Calculates the total sales for the home football games

#include <iostream>
using namespace std;

int main()
{
	//Variables
	int numberOfLevel1Tickets, 
		numberOfLevel2Tickets, 
		numberOfLevel3Tickets;
	const double priceOfLevel1Tickets = 25.50,
		priceOfLevel2Tickets = 20.50,
		priceOfLevel3Tickets = 15.50;

	cout << "Tickets sold in Level 1: ";
	cin >> numberOfLevel1Tickets;
	cout << "Tickets sold in Level 2: ";
	cin >> numberOfLevel2Tickets;
	cout << "Tickets sold in Level 3: ";
	cin >> numberOfLevel3Tickets;

	//Calculates the ticket sales
	double level1Sales = numberOfLevel1Tickets * priceOfLevel1Tickets,
		level2Sales = numberOfLevel2Tickets * priceOfLevel2Tickets,
		level3Sales = numberOfLevel3Tickets * priceOfLevel3Tickets,
		totalSales = level1Sales + level2Sales + level3Sales;

	//Displays each level's sales and the total sales
	cout << "\n\nLevel 1 ticket sales......$" <<level1Sales << endl;
	cout << "Level 2 ticket sales......$" << level2Sales << endl;
	cout << "Level 3 ticket sales......$" << level3Sales << endl << endl;
	cout << "Total ticket sales........$" <<totalSales << endl;
}