//Samantha Lopez-Montano
//Displays how far away a sound is given how long it travelled through a gas

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double AIR_SPEED = 331.5,
			CO2_SPEED = 258.0,
			HELIUM_SPEED = 972.0,
			HYDROGEN_SPEED = 1270.0;

int main( void )
{
	//Variables
	char gas_type;
	string gas_choice;
	double number_of_seconds = 0,
			distance = 0;
	int correct = 1;

	//Prompts the user to enter the number of seconds
	cout << "Enter the number of seconds: ";
	cin >> number_of_seconds;

	if (number_of_seconds < 0 || number_of_seconds > 30)
	{
		cout << "\nSeconds must be a number between 0 and 30. " << endl;
		cout << "Please run again and select valid number." << endl << endl;
	}
	else
	{
		//Displays the choices for the user then prompts and stores input
		cout << "Select one of the following gases:" << endl;
		cout << "A. Air" << endl;
		cout << "B. Carbon Dioxide" << endl;
		cout << "C. Helium" << endl;
		cout << "D. Hydrogen" << endl;
		cout << "E. Quit" << endl << endl;

		cout << "Enter your choice: ";
		cin >> gas_type;

		cout << setprecision(1) << fixed << showpoint;

		//Calculates the distance a sound travels through the selected gas
		switch (gas_type)
		{
		case 'A':
		case 'a':
			distance = number_of_seconds * AIR_SPEED;
			gas_choice = "air";
			break;
		case 'B':
		case 'b':
			distance = number_of_seconds * CO2_SPEED;
			gas_choice = "carbon dioxide";
			break;
		case 'C':
		case 'c':
			distance = number_of_seconds * HELIUM_SPEED;
			gas_choice = "helium";
			break;
		case 'D':
		case 'd':
			distance = number_of_seconds * HYDROGEN_SPEED;
			gas_choice = "hydrogen";
			break;
		case 'E':
		case 'e':
			correct = 0;					//Does not display the distance a sound travels
			cout << "\nProgram Ending." << endl;
			break;
		default:
			correct = 0;					//Does not display the distance a sound travels
			cout << "\n\nThe valid choices are A, B, C, D and E." << endl;
			cout << "Run the program again and select one of those." << endl;
		}

		if (correct)
		{
			//Displays the distance a sound travels through the selected gas sound
			cout << "\nA sound wave travels " << distance << " meters in " << number_of_seconds
				<< " seconds through " << gas_choice << "." << endl;
		}

	}
	
}