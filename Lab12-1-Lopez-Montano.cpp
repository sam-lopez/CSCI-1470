//Samantha Lopez-Montano
//Stores the home and college addresses for students and displays the information

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Structures
struct Address
{
	string address;
	string cityState;
	string zip;
};

struct StudentAddress
{
	string name;
	Address homeAddress;
	Address collegeAddress;
};

//Function Prototypes
void getStudentInfo(StudentAddress [], int&);
void display(StudentAddress[], int);

int main()
{
	//Variables
	const int MAX_STUDENTS = 50;
	int numberOfStudents;

	//Structure Declaration
	StudentAddress studentRecords[MAX_STUDENTS];

	//Function Calls
	getStudentInfo(studentRecords, numberOfStudents);
	display(studentRecords, numberOfStudents);
}

//Function Definitions
//Gets the number of students, student names, and student addresses
void getStudentInfo(StudentAddress studentRecords[], int& numberOfStudents)
{
	//Prompts user for valid number of students
	do
	{
		cout << "Please enter the number of students (must be a positive number less than or equal to 50): ";
		cin >> numberOfStudents;
		cin.ignore();
	} while (numberOfStudents > 50 || numberOfStudents <= 0);
	
	for (int i = 0; i < numberOfStudents; i++)
	{
		//Stores student name
		cout << "\n\nEnter the information for Student " << i + 1 << ": ";
		cout << "\nName: ";
		getline(cin, studentRecords[i].name);

		//Stores student's home address
		cout << "\n\tHome Address: ";
		cout << "\n\t  Street Adress: ";
		getline(cin, studentRecords[i].homeAddress.address);
		cout << "\t  City, State: ";
		getline(cin, studentRecords[i].homeAddress.cityState);
		cout << "\t  Zip Code: ";
		getline(cin, studentRecords[i].homeAddress.zip);

		//Stores student's college address
		cout << "\n\tCollege Address: ";
		cout << "\n\t  Street Adress: ";
		getline(cin, studentRecords[i].collegeAddress.address);
		cout << "\t  City, State: ";
		getline(cin, studentRecords[i].collegeAddress.cityState);
		cout << "\t  Zip Code: ";
		getline(cin, studentRecords[i].collegeAddress.zip);
	}
}

//Displays each individual student's name, home address, college address
void display(StudentAddress studentRecords[], int numberOfStudents)
{
	cout << "\n\nThe Student Address report is: ";

	for (int i = 0; i < numberOfStudents; i++)
	{
		//Displays student name
		cout << endl << endl << studentRecords[i].name;

		//Stores student's home address
		cout << "\n\tHome Address:    " << studentRecords[i].homeAddress.address;
		cout << "\n\t                 " << studentRecords[i].homeAddress.cityState << "   " << studentRecords[i].homeAddress.zip;

		//Stores student's college address
		cout << "\n\tCollege Address: " << studentRecords[i].collegeAddress.address;
		cout << "\n\t                 " << studentRecords[i].collegeAddress.cityState << "   " << studentRecords[i].collegeAddress.zip;
		cout << endl << endl;
	}
}