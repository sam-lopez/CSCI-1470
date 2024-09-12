//NAME: Samantha Lopez-Montano

//This program calculates the average of 3 exams and 
//determines the Letter Grade earned

#include <iostream>
#include <string>
using namespace std;

//const int NUMBER_OF_EXAMS = 3;

int main()
{
	//Variables to store exam scores, total of scores, 
	//calculated average, loop counter, and student name 
	double exam = 0;
	double total = 0;
	double average = 0;
	string student_name;
	int counter = 1;
	int num_exams = 0;
	char again;

	do
	{ 
	
		//Prompt and read the student's name
		cout << "Enter the student's name: ";
		getline(cin, student_name);
		do
		{
			cout << "\nEnter number of exams: ";
			cin >> num_exams;
			if (num_exams < 1)
				cout << "ERROR - INVALID - RE-ENTER" << endl;
		} while (num_exams < 1);

		//Prompt and read exam scores from user
		while (counter <= num_exams)
		{
			do
			{
				cout << "Enter Exam " << counter << " score ";
				cin >> exam;
				if (exam < 0 || exam > 100)
					cout << "ERROR - Exam must be between 0 and 100." << endl;

			} while (exam < 0 || exam > 100);
			total += exam; //total = total + exam;
			counter++; //counter = counter + 1;  counter += 1;
		}

		//Calculate Average of exams
		average = total / num_exams;

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

		cout << "Run program again (Y for Yes, N for No) ";
		cin >> again;
		cin.get();

	} while (again == 'Y' || again == 'y');

	return 0;

}
