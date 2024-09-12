//Name: Samantha Lopez-Montano

#include<iostream>
#include<string>
#include <iomanip>

using namespace std;  //introduces namespace std

const int STUDENTS = 3;
const int COURSES = 5;
const int CREDITS = 3;

struct StudentRecord
{
	int ID; //user entered member 
	string name; //user entered member 
	double GPA; //calculated member
};

//Function Prototypes
void getStudentInfo(StudentRecord[]);
void calcuateGPA(StudentRecord[]);
void displayStudentInfo(StudentRecord student[]);


int main()
{
	//Declare an Array of Structures
	StudentRecord student[STUDENTS];

	//Function Calls - get student information, calcualte GPA, display information
	getStudentInfo(student);
	calcuateGPA(student);
	displayStudentInfo(student);

	cout << endl << endl;
	system("pause");
	return 0;
}

//Gets student ID and name 
void getStudentInfo(StudentRecord student[])
{
	string dummy;
	for (int i = 0; i < STUDENTS; i++)
	{
		cout << "Enter Student " << i + 1 << " ID: ";
		cin >> student[i].ID;
		getline(cin, dummy);
		cout << "Enter Student " << i + 1 << " name: ";
		getline(cin, student[i].name);
		cout << endl << endl;
	}
}

//Gets Letter Grade earned for each course and calculates GPA
void calcuateGPA(StudentRecord student[])
{
	char letterGrade = 0;
	double totalPts = 0;
	int i = 0;


	for (int m = 0; m < STUDENTS; m++)
	{
		totalPts = 0;
		//Prompt for each students' letter grade by using student name
		cout << student[m].name;
		for (i = 0; i < COURSES; i++)
		{
			cout << "\nCourse # " << i + 1 << " : ";
			cin >> letterGrade;
			if (letterGrade == 'A' || letterGrade == 'a')
				totalPts = totalPts + 4;
			else if (letterGrade == 'B' || letterGrade == 'b')
				totalPts = totalPts + 3;
			else if (letterGrade == 'C' || letterGrade == 'c')
				totalPts = totalPts + 2;
			else if (letterGrade == 'D' || letterGrade == 'd')
				totalPts = totalPts + 1;
			else if (letterGrade == 'F' || letterGrade == 'f')
				totalPts = totalPts + 0;
		}
		//calculate GPA and store in GPA Structure member
		student[m].GPA = totalPts / COURSES;
	}
}

//Displays students' ID, name, and GPA
void displayStudentInfo(StudentRecord student[])
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n\nID     Name     GPA" << endl;
	for (int i = 0; i < STUDENTS; i++)
	{
		cout << setw(5) << left << student[i].ID;
		cout << setw(12) << student[i].name;
		cout << setw(7) << student[i].GPA;
		cout << endl;
	}
}