//Name: Samantha Lopez-Montano                    
//Calculates the Area of a Circle - Area = πr2

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Declare PI as a named constant
const double PI = 3.1416;

int main()
{
	//Variables for area and radius values
	double area = 0;
	double radius = 3.255;

	//Process: Calculate area of a circle
	area = PI * pow(radius, 2);

	//Output: Displays the area and radius of the circle 
	cout << "\nThe area of a circle with a radius of " << radius
		 << " is " << area << endl << endl;


}