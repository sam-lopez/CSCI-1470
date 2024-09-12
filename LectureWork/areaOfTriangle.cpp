//Name:
//Calculates the Area of a Triangle - Area = 1/2 b h

#include <iostream>
using namespace std;

int main()
{
	//Input:
	double base = 8.5, height = 12.4, area;

	//Process: Calculate area of a triangle - BEWARE!!! - INTEGER DIVISION - 
	area = 0.5 * (base * height);

	//Output: Displays the area and dimensions of triangle 
	cout << "\nThe area of a triangle with base of " << base << " and a height of "
		<< height << " is " << area << endl << endl;
}