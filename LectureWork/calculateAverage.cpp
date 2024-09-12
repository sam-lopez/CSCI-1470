
//Samantha Lopez-Montano
//Calculate the average of two exams

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Variables to store student name, exam scores, and average
	string name;
	int exam1 = 0;
	int exam2 = 0;
	double average = 0;

	cout << "Enter student name: ";
	getline(cin, name);
	cout << "Enter Exam 1: ";
	cin >> exam1;
	cout << "Enter Exam 2: ";
	cin >> exam2;
	cout << "Average: ";

	//Calculates the average of the exams
	average = (exam1 + exam2) / 2.0;


	//Displays the student name, exam scores, and average
	cout << "\n\nName: " << name << endl;
	cout << "Exam 1: " << exam1 << endl;
	cout << "Exam 2: " << exam2 << endl;
	cout << "Average: " << average << endl;

}