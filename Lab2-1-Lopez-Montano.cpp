//Samantha Lopez-Montano
//Calculates the volume of a pool

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Variables - name, dimensions, volume, chemicals
	string name;
	double length, width, depth, volume, chemicals;

	cout << "Please enter the customer name: ";
	getline(cin, name);
	cout << "Please enter the length of the pool: ";
	cin >> length;
	cout << "Please enter the width of the pool: ";
	cin >> width;
	cout << "Please enter the depth of the pool: ";
	cin >> depth;

	//Calculates the volume and chemicals needed
	volume = length * width * depth;
	chemicals = (1.0 / 8.0) * volume;

	//Displays the customer name, pool dimensions, volume, and chemicals needed
	cout << "\n\nCustomer Name: " << name << endl;
	cout << "Dimensions of the Pool: " << endl;
	cout << "Length\t" << length << " feet" << endl;
	cout << "Width \t" << width << " feet" << endl;
	cout << "Depth \t" << depth << " feet" << endl;
	cout << "Volume of the pool: " << volume << " cubic feet" << endl;
	cout << "Chemicals needed: " << chemicals << " lbs." << endl;
}