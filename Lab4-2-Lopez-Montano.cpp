//Samantha Lopez-Montano
//Calculates the speeding ticket charge

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Variables
	string driverName;
	int clockedSpeed,
		areaSpeed,
		amountOverLimit;
	double ticketCharge;

	cout << "Enter Driver Name: ";
	getline(cin, driverName);
	cout << "Enter Clocked Speed(mph): ";
	cin >> clockedSpeed;
	cout <<	"Enter Area Speed limit(mph): ";
	cin >> areaSpeed;
	
	//Calculates the ticket charge
	amountOverLimit = clockedSpeed - areaSpeed;

	if (amountOverLimit >= 10 && amountOverLimit <= 20)
	{
		ticketCharge = 100.00;
	}
	else if (amountOverLimit > 20 && amountOverLimit <= 30)
	{
		ticketCharge = 200.00;
	}
	else if (amountOverLimit > 30 && amountOverLimit <= 40)
	{
		ticketCharge = 300.00;
	}
	else if (amountOverLimit > 40)
	{
		ticketCharge = 500.00;
	} 
	else
	{
		cout << "\nInvalid input for speeding charge" << endl;
		system("pause");
	}

	//Displays driver information and ticket charge
	cout << "\n\nSpeeding Ticket Charge for " << driverName << endl << endl;
	cout << "\tClocked Speed:     " << clockedSpeed << " mph" << endl;
	cout << "\tArea Speed Limit:  " << areaSpeed << " mph" << endl;
	cout << "\tAmount Over Limit: " << amountOverLimit << " mph" << endl << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Ticket Charge..............$" << ticketCharge << endl;
}