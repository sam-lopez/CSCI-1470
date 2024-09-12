//Samanntha Lopez-Montano
//Calculates and displays the grades of students in a 5 question quiz

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Constant variables
const int QUESTIONS = 5;

//Function Prototypes
void answerKey(char[]);
void studentsQuiz(int&, string[]);
void studentAnswers(int, string[], char[][QUESTIONS]);
void calculateGrades(int, char[][QUESTIONS], char[], int[]);
void display(int, string[], char[][QUESTIONS], char[], int[]);

int main()
{
	char key[QUESTIONS];
	int numStudents = 0;
	string names[100];
	char answers[100][QUESTIONS];
	int grades[QUESTIONS];

	//Function Calls
	answerKey(key);
	studentsQuiz(numStudents, names);
	studentAnswers(numStudents, names, answers);
	calculateGrades(numStudents, answers, key, grades);
	display(numStudents, names, answers, key, grades);
}

//Function Definitions
//Prompts and save the correct answer key in a 1D array
void answerKey(char key[])
{
	cout << "This program calculates the grade for students taking a true-false quiz.";
	
	cout << "\n\nPlease enter the answer key.\n";
	
	for (int i = 0; i < QUESTIONS; i++)
	{
		cout << "Answer #" << i + 1 << ": ";
		cin >> key[i];
	}
}

//Prompts for number of students and their names
void studentsQuiz(int& numStudents, string names[])
{
	cout << "\nPlease enter the number of students: ";
	cin >> numStudents;
	cin.ignore();
	
	cout << "\nPlease enter names for " << numStudents << " students:\n";
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Student Name " << i+1 << ": ";
		getline(cin, names[i]);
	}
}

//Saves student answer input in 2D array
void studentAnswers(int numStudents, string names[], char answers[][QUESTIONS])
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "\n\nPlease enter " << names[i] << "'s quiz answers:\n";

		for (int j = 0; j < QUESTIONS; j++)
		{
			cout << "Answer #" << j+1 << ": ";
			cin >> answers[i][j];
		}
	}

}

//Calculates student grades and saves in grade array
void calculateGrades(int numStudents, char answers[][QUESTIONS], char key[], int grades[])
{
	for (int i = 0; i < numStudents; i++)
	{
		grades[i] = 0;
		for (int j = 0; j < QUESTIONS; j++)
		{
			if (answers[i][j] == key[j])
				grades[i] += 3;
		}
	}
}

//Displays key and student information and grades
void display(int numStudents, string names[], char answers[][QUESTIONS], char key[], int grades[])
{
	cout << left << setw(20) << "\nName" << setw(20) << "Answers" << right << setw(5) << "Grade\n";

	//displays answer row
	cout << setw(20) << left << "Answer Key";
	for (int i = 0; i < QUESTIONS; i++)
	{
		cout << left << setw(4) << key[i];
	}
	cout << right << setw(5) << "15\n";

	//displays student rows
	for (int i = 0; i < numStudents; i++)
	{
		cout << left << setw(20) << endl << names[i];

		for (int j = 0; j < QUESTIONS; j++)
		{
			cout << left << setw(4) << answers[i][j];
		}
		cout << right << setw(4) << grades[i];
	}

	cout << endl << endl;
}