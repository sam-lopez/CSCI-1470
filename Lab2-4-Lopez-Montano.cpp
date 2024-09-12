//Samantha Lopez-Montano
//Calculates the average exam scores

#include <iostream>
using namespace std;

int main()
{
	//Variables
	char firstInitial,
		middleInitial,
		lastInitial;
	double firstExamScore,
		secondExamScore,
		thirdExamScore,
		fourthExamScore,
		total,
		average;

	cout << "Please enter the student's three initials when asked and press the enter key after each letter." << endl;
	cout << "First initial: ";
	cin >> firstInitial;
	cout << "Second intial: ";
	cin >> middleInitial;
	cout << "Third initial: ";
	cin >> lastInitial;
	cout << "\nNext you will be asked to enter four exam scores." << endl;
	cout << "Please enter the first exam score and press the enter key: ";
	cin >> firstExamScore;
	cout << "Please enter the second exam score and press the enter key: ";
	cin >> secondExamScore;
	cout << "Please enter the third exam score and press the enter key: ";
	cin >> thirdExamScore;
	cout << "Please enter the fourth exam score and press the enter key: ";
	cin >> fourthExamScore;

	//Calculates the total exam scores and average exam score.
	total = firstExamScore + secondExamScore + thirdExamScore + fourthExamScore;
	average = total / 4;

	//Displays the student's initials, exam scores, total scores, and average
	cout << "\n\nStudent's Initials: " << firstInitial << " " << middleInitial << " " << lastInitial << endl;
	cout << "Exam 1...." << firstExamScore << endl;
	cout << "Exam 2...." << secondExamScore << endl;
	cout << "Exam 3...." << thirdExamScore << endl;
	cout << "Exam 4...." << fourthExamScore << endl;
	cout << "Total....." << total << endl;
	cout << "Average..." << average << endl;
}