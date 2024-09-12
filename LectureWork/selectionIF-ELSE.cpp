//NAME: Samantha Lopez-Montano

//This program calculates the average of 2 exams and determines whether the student passed the course

#include <iostream>
using namespace std;

int main()
{
	//Variables to store exam scores and calculated average
	int exam1 = 0, exam2 = 0;
	double average = 0;


	//Prompt and read exam scores from user
	cout << "Enter Exam 1 Score: ";
	cin >> exam1;
	cout << "Enter Exam 2 Score: ";
	cin >> exam2;

	//Calculate Average of exams
	average = (exam1 + exam2) / 2.0;

	//Display Exam scores and average
	cout << "\n\nExam 1 Score: " << exam1 << endl;
	cout << "Exam 2 Score: " << exam2 << endl << endl;
	cout << "Average: " << average << endl << endl << endl;

	if (average >= 70)
	{
		cout << "\n\nCongratualations, you PASSED!!!" << endl;
		cout << "\n\nYou can DRIVE!!!" << endl << endl;
	}
	else
	{
		cout << "\n\nYou did NOT pass." << endl;
		cout << "\n\nTake the exam again." << endl << endl;
	}
}