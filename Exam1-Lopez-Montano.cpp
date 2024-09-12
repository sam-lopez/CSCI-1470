/*
	Samantha Lopez-Montano
	Calculates the volume of a shape to determine the handling fee,
	shipping charge, and total processing charges to create an invoice
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

const double PI = 3.1416;

int main()
{
	int menuChoice = 0;
	string customerName;
	string shapeName;
	double ellipsoidRadiusA = 0,
		ellipsoidRadiusB = 0,
		ellipsoidRadiusC = 0,
		torusMajorRadius = 0,
		torusMinorRadius = 0,
		cubeSide = 0,
		volume = 0,
		handlingFee = 0,
		shippingCharge = 0,
		totalProcessingCharge = 0;

	//Displays Menu choice
	cout << "Please enter your choice of shape from the following menu: \n";
	cout << "1. Cube\n";
	cout << "2. Torus\n";
	cout << "3. Ellipsoid\n";
	cout << "4. Quit\n";

	//Prompts user for menu selection and saves input
	cout << "\nEnter Menu Choice: ";
	cin >> menuChoice;
	cin.get();

	//Chooses
	switch (menuChoice)
	{
		case 1:
			shapeName = "Cube";
			//Prompts user for customer name and saves input
			cout << "Enter the Name of the Customer: ";
			getline(cin, customerName);

			//Validates input for cube dimensions
			do
			{
				cout << "\n\nEnter the side measurement of the " 
						<< shapeName << ": ";
				cin >> cubeSide;
				if (cubeSide < 0)
					cout << "\n\nInvalid input - Negative number";
			} while (cubeSide < 0);

			//Calculates the volume of the cube
			volume = pow(cubeSide, 3);

			//Calculates handling fee and shipping charge
			if (volume > 0 && volume <= 50)
			{
				handlingFee = 5.55;
				shippingCharge = .10 * volume;
			}
			else if (volume > 50 && volume <= 100)
			{
				handlingFee = 7.75;
				shippingCharge = .23 * (volume - 50);
			}
			else if (volume > 100 && volume <= 150)
			{
				handlingFee = 9.50;
				shippingCharge = .28 * (volume - 100);
			}
			else if (volume > 150)
			{
				handlingFee = 11.25;
				shippingCharge = .32 * (volume - 150);
			}

			//Calculates total processing charges
			totalProcessingCharge = handlingFee + shippingCharge;

			//Displays Output
			cout << "\n\nShipping Invoice for " << customerName << endl;
			cout << "\nDimensions of the " << shapeName << ": ";
			cout << "\nSide: " << cubeSide << " feet";
			cout << setprecision(1) << fixed << showpoint;
			cout << "\n\nVolume: " << volume << " cubic feet";
			cout << setprecision(2) << fixed << showpoint;
			cout << "\n\nHandling Fee.....................$" << handlingFee;
			cout << "\nShipping Charge..................$" << shippingCharge;
			cout << "\nTotal Processing Charge..........$" 
					<< totalProcessingCharge << endl;
			break;
		case 2:
			shapeName = "Torus";
			//Prompts user for customer name and saves input
			cout << "Enter the Name of the Customer: ";
			getline(cin, customerName);

			//Validates input for the torus dimensions
			do
			{
				cout << "\nEnter the Major Radius (R) measurement of the " 
						<< shapeName << ": ";
				cin >> torusMajorRadius;
				if (torusMajorRadius < 0)
					cout << "\n\nInvalid Input - Negative number";
			} while (torusMajorRadius < 0);
			do
			{
				cout << "Enter the Minor Radius (r) measurement of the " 
						<< shapeName << ": ";
				cin >> torusMinorRadius;
				if (torusMinorRadius < 0)
					cout << "\n\nInvalid Input - Negative number";
			} while (torusMinorRadius < 0);

			//Calculates the volume of the torus
			volume = (1.0 / 4.0) * pow(PI, 2) * 
				(torusMinorRadius + torusMajorRadius) * 
				pow(torusMajorRadius - torusMinorRadius, 2);
			
			//Calculates handling fee and shipping charge
			if (volume > 0 && volume <= 50)
			{
				handlingFee = 5.55;
				shippingCharge = .10 * volume;
			}
			else if (volume > 50 && volume <= 100)
			{
				handlingFee = 7.75;
				shippingCharge = .23 * (volume - 50);
			}
			else if (volume > 100 && volume <= 150)
			{
				handlingFee = 9.50;
				shippingCharge = .28 * (volume - 100);
			}
			else if (volume > 150)
			{
				handlingFee = 11.25;
				shippingCharge = .32 * (volume - 150);
			}

			//Calculates total processing charges
			totalProcessingCharge = handlingFee + shippingCharge;

			//Displays Output
			cout << "\n\nShipping Invoice for " << customerName << endl;
			cout << "\nDimensions of the " << shapeName << ": ";
			cout << "\nMajor Radius (R): " << torusMajorRadius;
			cout << "\nMinor Radius (r): " << torusMinorRadius;
			cout << setprecision(1) << fixed << showpoint;
			cout << "\n\nVolume: " << volume << " cubic feet";
			cout << setprecision(2) << fixed << showpoint;
			cout << "\n\nHandling Fee.....................$" << handlingFee;
			cout << "\nShipping Charge..................$" << shippingCharge;
			cout << "\nTotal Processing Charge..........$" 
					<< totalProcessingCharge << endl;
			break;
		case 3:
			shapeName = "Ellipsoid";
			//Prompts user for customer name and saves input
			cout << "Enter the Name of the Customer: ";
			getline(cin, customerName);

			//Validates input for the ellipsoid dimensions
			do
			{
				cout << "\nEnter the a-axis radius: ";
				cin >> ellipsoidRadiusA;
				if (ellipsoidRadiusA < 0)
					cout << "\n\nInvalid Input - Negative number\n";
			} while (ellipsoidRadiusA < 0);
			do
			{
				cout << "Enter the b-axis radius: ";
				cin >> ellipsoidRadiusB;
				if (ellipsoidRadiusB < 0)
					cout << "\n\nInvalid Input - Negative number\n\n";
			} while (ellipsoidRadiusB < 0);
			do
			{
				cout << "Enter the c-axis radius: ";
				cin >> ellipsoidRadiusC;
				if (ellipsoidRadiusC < 0)
					cout << "\n\nInvalid Input - Negative number\n\n";
			} while (ellipsoidRadiusC < 0);

			//Calculates the volume of the ellipsoid
			volume = (4.0 / 3.0) * PI * ellipsoidRadiusA * 
				ellipsoidRadiusB * ellipsoidRadiusC;
			
			//Calculates handling fee and shipping charge
			if (volume > 0 && volume <= 50)
			{
				handlingFee = 5.55;
				shippingCharge = .10 * volume;
			}
			else if (volume > 50 && volume <= 100)
			{
				handlingFee = 7.75;
				shippingCharge = .23 * (volume - 50);
			}
			else if (volume > 100 && volume <= 150)
			{
				handlingFee = 9.50;
				shippingCharge = .28 * (volume - 100);
			}
			else if (volume > 150)
			{
				handlingFee = 11.25;
				shippingCharge = .32 * (volume - 150);
			}

			//Calculates total processing charges
			totalProcessingCharge = handlingFee + shippingCharge;

			//Displays Output
			cout << "\n\nShipping Invoice for " << customerName << endl;
			cout << "\nDimensions of the " << shapeName << ": ";
			cout << "\nA-axis Radius: " << ellipsoidRadiusA << " feet";
			cout << "\nB-axis Radius: " << ellipsoidRadiusB << " feet";
			cout << "\nC-axis Radius: " << ellipsoidRadiusC << " feet";
			cout << setprecision(1) << fixed << showpoint;
			cout << "\n\nVolume: " << volume << " cubic feet";
			cout << setprecision(2) << fixed << showpoint;
			cout << "\n\nHandling Fee.....................$" << handlingFee;
			cout << "\nShipping Charge..................$" << shippingCharge;
			cout << "\nTotal Processing Charge..........$" 
					<< totalProcessingCharge << endl;
			break;
		case 4:
			cout << "\n\nThanks for using this program!!!\n\n";
			break;
		default:
			cout << "\n\nInvalid Menu Choice - Run Program Again\n\n";
	}	

}
