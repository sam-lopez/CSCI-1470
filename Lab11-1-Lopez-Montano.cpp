//Samantha Lopez-Montano
//Calculates and displays the students' average grades as well and the highest and lowest averages

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Structure
struct StudentRecord
{
	string name;
	double examPoints = 0;
	double labPoints = 0;
	double average = 0;
	char grade = 'F';
};

//Function Prototypes
void getStudentInfo(int&, int&, int&, StudentRecord[]);
void calculateAverages(int, int, int, StudentRecord[], double&, double&);
void display(int, StudentRecord[], double, double);

int main()
{	
	const int MAX_STUDENTS = 50;
	//Declare an array of stuctures
	StudentRecord student[MAX_STUDENTS];

	//Variables
	int numberOfStudents;
	int examPointsPossible;
	int labPointsPossible;
	double highest;
	double lowest;

	//Function Calls
	getStudentInfo(numberOfStudents, examPointsPossible, labPointsPossible, student);
	calculateAverages(numberOfStudents, examPointsPossible, labPointsPossible, student, highest, lowest);
	display(numberOfStudents, student, highest, lowest);
}

//Function Definitions
//Gets number of students, points possible, student name, and points earned
void getStudentInfo(int& numberOfStudents, int& examPointsPossible, int& labPointsPossible, StudentRecord student[])
{
		cout << "Enter the number of students in the course: ";
		cin >> numberOfStudents;

		cout << "Enter the total EXAM points that are possible in the course: ";
		cin >> examPointsPossible;

		cout << "Enter the total LAB points possible in the course: ";
		cin >> labPointsPossible;

		for (int i = 0; i < numberOfStudents; i++)
		{
			cout << "\n\nEnter the information for Student " << i + 1 << ": \n";
			cin.ignore();
			cout << "\tName: ";
			getline(cin, student[i].name);

			cout << "\tExam Points Earned: ";
			cin >> student[i].examPoints;

			cout << "\tLab Points Earned: ";
			cin >> student[i].labPoints;
		}
}

//Calculates the students' averages, letter grades of each average, the highest and lowest averages
void calculateAverages(int numberOfStudents, int examPointsPossible, int labPointsPossible, StudentRecord student[], double& highest, double& lowest)
{
	const double PERCENT_OF_LABS = 40;
	const double PERCENT_OF_EXAMS = 60;

	//Calculates the students' averages and letter grades
	for (int i = 0; i < numberOfStudents; i++)
	{
		student[i].average = (PERCENT_OF_EXAMS * (student[i].examPoints / double(examPointsPossible) )) + (PERCENT_OF_LABS * (student[i].labPoints / double(labPointsPossible) ));
		
		if(student[i].average >= 90)
			student[i].grade = 'A';
		else if(student[i].average >= 80)
			student[i].grade = 'B';
		else if(student[i].average >= 70)
			student[i].grade = 'C';
		else if (student[i].average >= 60)
			student[i].grade = 'D';
		else if (student[i].average < 60)
			student[i].grade = 'F';
	}

	highest = student[0].average;
	lowest = student[0].average;

	//Calculates the highest average
	for (int i = 1; i < numberOfStudents; i++)
	{
		if (student[i].average > highest)
			highest = student[i].average;
	}

	//Calculates the lowest average
	for (int i = 1; i < numberOfStudents; i++)
	{
		if (student[i].average < lowest)
			lowest = student[i].average;
	}
}

//Displays student name, points earned, averages, letter grades, and the highest and lowest averages
void display(int numberOfStudents, StudentRecord student[], double highest, double lowest)
{
	cout << setprecision(1) << fixed << showpoint;

	cout << "\n\nStudent Name   " << "\t\tExam Pts      " << "\t\t Lab Pts   " << "\t\tAverage       " << "\t\tLetter Grade\n";
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << setw(26) << left << student[i].name;
		cout << setw(24) << student[i].examPoints;
		cout << setw(24) << student[i].labPoints;
		cout << setw(28) << student[i].average;
		cout << setw(24) << student[i].grade << endl;
	}

	cout << "\n\nHighest Average: " << highest;
	cout << "\nLowest Average: " << lowest << endl << endl;
}