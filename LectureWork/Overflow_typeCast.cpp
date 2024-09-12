//Samantha Lopez-Montano

#include <iostream>
#include <iomanip>

using namespace std; //introduces namespace std

int main(void)
{
	double num10 = 23.4567, num11 = 34.6789;

	cout << setprecision(3) << fixed << showpoint;
	cout << num10 << " " << num11 << endl << endl;

    //sizeof() function


	cout << "short int: " << sizeof(short int) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "long int: " << sizeof(long int) << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double);
	cout << endl << endl;   
	

	//OverFlow/Underflow

	
	int number = 2147483647;

	number = number + 2;

	cout << "\nNumber: " << number << endl;
	cout << endl << endl; 
	

	//Type cast and Order of Operations

	
	int num1 = 2, num2 = 3, num3 = 5;

	cout << "Average is " << (num1 + num2 + num3) / (double)num2;

	cout << endl << endl; 
	

	//Type Coercion

	
	double answer = 0;

	answer = 1.2 + 4;

	cout << "Answer is " << answer << endl << endl;
	

	return 0;
}


/*

short int: 2
int: 4
long int: 4
char: 1
float: 4
double: 8
long double: 8

*/