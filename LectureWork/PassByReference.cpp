//NAME: Samantha Lopez-Montano

//This program calculates the perimeter and area of a rectangle.
/*******************************************************
Input:
Length and width of rectangle

Process:
1. Calculate the area: length X width
2. Calculate perimeter: (2 X length) + (2 X width)
						OR length + length + width + width

Output:
Length, width, and calculated area and perimeter of a rectangle
*******************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void getLengthWidth(int&, int&);
void calculateAreaPerimeter(int length, int width, int& area, int &perimeter);
void displayRectangleInfo(int length, int width, int area, int perimeter);

int main()
{
	//Variables needed 
	int length = 0, width = 0, area = 0, perimeter = 0;

	//Function Call Statements
	getLengthWidth(length, width);
	calculateAreaPerimeter(length, width, area, perimeter);
	displayRectangleInfo(length, width, area, perimeter);

	return 0;
}

//Function Definitions 

//Prompts and gets the length and width of the rectangle 
void getLengthWidth(int& length, int& width)
{
	//function body
	cout << "Enter the Length of the rectangle: ";
	cin >> length;
	cout << "Enter the Width of the rectangle: ";
	cin >> width;
}


//Calculates the area of the rectangle 
void calculateAreaPerimeter(int length, int width, int& area, int& perimeter) 
{
	area = length * width;
	perimeter = length + length + width + width;
}


//Displays the dimensions and area of the rectangle  
void displayRectangleInfo(int length, int width, int area, int perimeter) //function header
{
	//function body
	cout << "\n\n\nThe dimensions of the rectangle are: " << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Area: " << area << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << endl << endl;
}