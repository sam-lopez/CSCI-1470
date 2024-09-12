﻿//NAME: Samantha Lopez-Montano

//This program calculates the average of 3 exams and determines the Letter Grade earned

#include <iostream>
#include <string>
using namespace std;

const int NUMBER_OF_EXAMS = 3;

int main()
{
	//Variables to store exam scores, total of scores, calculated average, loop counter, and student name 
	double exam = 0;
	double total = 0;
	double average = 0;
	string student_name;
	int counter = 1;

	//Prompt and read the student's name
	cout << "Enter the student's name: ";
	getline(cin, student_name);

	//Prompt and read exam scores from user
	while (counter <= NUMBER_OF_EXAMS)
	{
		cout << "Please enter Exam " << counter << " score: ";
		cin >> exam;
		total = total + exam;		//total += exam;
		counter = counter + 1;		//counter += 1;
	}

	//Calculate Average of exams
	average = total / NUMBER_OF_EXAMS;

	//Display Student Name, Average and letter grade earned
	cout << "\n\nStudent Name: " << student_name << endl;
	cout << "Average: " << average << endl << endl << endl;


	if (average >= 89.5)
		cout << "You earned an A" << endl << endl;
	else if (average >= 79.5)
		cout << "You earned a B" << endl << endl;
	else if (average >= 69.5)
		cout << "You earned a C" << endl << endl;
	else if (average >= 59.5)
		cout << "You earned a D" << endl << endl;
	else
		cout << "You earned an F" << endl << endl;


}
