//Samantha Lopez-Montano
//Calculates the kinetic energy of an object

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	//Variables
	double mass,
		speed,
		kEnergy;

	cout << setprecision(2) << fixed << showpoint;

	cout << "Please enter mass of the object: ";
	cin >> mass;
	cout << "Please enter speed of the object: ";
	cin >> speed;

	//Calculates the kinetic energy
	kEnergy = 0.5 * mass * pow(speed, 2);

	//Displays the attributes of the object and kinetic energy
	cout << "\n\nThe attributes of the object are: " << endl;
	cout << "Mass: " << mass << " kg" << endl;
	cout << "Velocity: " << speed << " meters per second" << endl << endl;
	cout << "The kinetic energy of the object is " << kEnergy << " joules." << endl;
}