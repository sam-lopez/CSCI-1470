//Samantha Lopez-Montano
//This program will calculate the lateral surface area of a cone

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.1416;

int main()
{
	//Variables
	double diameter,
		height,
		radius,
		area;

	cout << setprecision(2) << fixed << showpoint;

	cout << "Please enter the diameter of the base of the cone: ";
	cin >> diameter;
	cout << "Please enter the height of the cone: ";
	cin >> height;

	//Calculates the radius and lateral surface area of the cone
	radius = diameter / 2;
	area = PI * radius * sqrt(pow(radius, 2) + pow(height, 2));

	//Displays the dimensions and lateral suface area
	cout << "\n\nThe dimensions of the cone are:" << endl;
	cout << "Height " << height << endl;
	cout << "Diameter of the base " << diameter << endl;
	cout << "Radius of the base " << radius << endl;
	cout << "The lateral surface are is " << area << endl;
}