/*******************************************************************************************
 Name: Samantha Lopez-Montano
 Purpose: This program accepts two numeric values from the user and displays the absolute 
          value, the square root, and the values raised to various powers. It also accepts
		  an angle measured in degrees and calculates the sine and cosine.

  Input: Two numeric values, an angle measured in degrees
  Process: Calculate:absolute value of number_1 and number_2
					 square root of number_1 and number_2
			         number_1^2, number_2^6
					 sine of angle
					 cosine of angle
  Output: absolute value of number_1 and number_2
           square root of number_1 and number_2
		   number_1^2, number_2^6
		   sine of angle
		   cosine of angle
*********************************************************************************************/

//This program requires three header files to run
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const double PI = 3.1416;

int main ( void )
{
    double number1 = 0.0, number2 = 0.0; //stores numbers entered by user
	double angle = 0.0;
    
    //Prompt user for input
    cout << "Please enter the first number for calculations:";
    cin >> number1;
    cout << "Please enter the second number for calculations:";
    cin >> number2;
    
    //Separate input from output
    cout << endl << endl;
    
    //format output values
	cout << setprecision(4) << fixed << showpoint;
       
    //Perform and display calculations on user-input numbers
	cout << "The absolute value of number one is: " << abs(number1) << endl;
	cout << "The absolute value of number two is: " << abs(number2) << endl;

	cout << "The square root of number one is: " << sqrt(number1) << endl;
	cout << "The square root of number two is: " << sqrt(number2) << endl;

    cout << "The first number raised to the second power: " << pow(number1, 2) << endl;
	cout << "The second number raised to the  sixth power: " << pow(number2, 6) << endl;

	//Prompt user for input
    cout << "\n\nPlease enter the an angle measured in degrees:";
    cin >> angle;
   
    //Convert degrees to radians for sine and cosine functions
	cout << "The sine of the angle: " << sin(angle * PI / 180) << endl;  
	cout << "The cosine of the angle: " << cos(angle * PI / 180) << endl;
	
	cout << endl << endl << endl;
	return 0;
}