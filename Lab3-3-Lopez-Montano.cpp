/*Samantha Lopez-Montano
  Calculates a theater's gross and 
  net box office profit for a night and 
  the amount paid to the movie distributor
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double ADULT_TICKET_COST = 6.00,
			CHILD_TICKET_COST = 3.00;

int main()
{
	//Variables
	string movieName;
	int adultTicketsSold,
		childTicketsSold;
	double grossProfit,
		netProfit,
		distributorPay;

	cout << "Enter the name of the movie: ";
	getline(cin, movieName);
	cout << "Enter the number of Adult Tickets Sold: ";
	cin >> adultTicketsSold;
	cout << "Enter the number of Child Tickets Sold: ";
	cin >> childTicketsSold;

	//Calculates the gross and net profit as well as the distributor pay
	grossProfit = ADULT_TICKET_COST * adultTicketsSold + CHILD_TICKET_COST * childTicketsSold;
	netProfit = .20 * grossProfit;
	distributorPay = .80 * grossProfit;

	//Displays the movie name, tickets sold, profit, and the distributors pay
	cout << "\n\nMovie Name........................" << movieName << endl;
	cout << "Adult Tickets Sold ..............." << adultTicketsSold << endl;
	cout << "Child Tickets Sold ..............." << childTicketsSold << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Gross Box Office Profit...........$" << grossProfit << endl;
	cout << "Net Box Office Profit.............$" << netProfit << endl;
	cout << "Amount Paid To Distributors.......$" << distributorPay << endl;
}