/************************************************************************************
Name: Samantha Lopez-Montano

This program gets the name and exams scores for students and calculates their average

********************************C****************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; //introduces namespace std

//declare the number of students and exams taken 
const int STUDENTS = 4;
const int EXAMS = 3;

//get the students' names and scores 
void getNameAndScores(string name[], int score[STUDENTS][EXAMS]);

//calculates the average score for each student 
void calculateAverage(int[][EXAMS], double []);

//displays the name, all scores entered, and average for each student 
void displayInformation(string name[], double average [], int[][EXAMS]);

int main(void)
{
	//1D array to store each student's name
	string name[STUDENTS];

	//2D array to store the scores for each student
	int score[STUDENTS][EXAMS] = { 0 };

	//1D array to store each student's average
	double average[STUDENTS] = { 0 };
	
	char repeat;
	string dummy;

	//Allow user to run program again
	do
	{
		getNameAndScores(name, score); //Pass array names only to functions
		calculateAverage(score, average); //Pass array names only to functions
		displayInformation(name, average, score); //Pass array names only to functions

		cout << "\n\n\nWould you like to calculate the average for another group of students? Y or N ";
		cin >> repeat;
		getline(cin, dummy);

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

//gets the name and exam scores for each student
void getNameAndScores(string name[], int score[][EXAMS])
{
	string dummy;

	cout << "\nPlease enter the name and exam scores for each student." << endl;

	for (int i = 0; i < STUDENTS; i++)
	{
		cout << "\nPlease enter the student name: ? ";
		getline(cin, name[i]);
		for (int j = 0; j < EXAMS; j++)
		{
			cout << "\nExam " << j + 1 << ": ? ";
			cin >> score[i][j];
		}
		getline(cin, dummy);
	}
}

//calculates the average score for each student and stores these values in a 1D arrray
void calculateAverage(int score[][EXAMS], double average[])
{
	int total = 0;

	//Calcualtes the average score for the student
	for (int i = 0; i < STUDENTS; i++)
	{
		total = 0;
		for (int j = 0; j < EXAMS; j++)
		{
			total = total + score[i][j];
		}
		average[i] = total / double(EXAMS);
	}
}

//displays the name, exam scores, and average for each student 
void displayInformation(string name[], double average[], int score[][EXAMS])
{
	//Format output
	cout << setprecision(1) << fixed << showpoint;

	cout << "\n\nName           Exam Scores         Average " << endl;

	for (int i = 0; i < STUDENTS; i++)
	{
		cout << setw(12) << left << name[i];
		for (int j = 0; j < EXAMS; j++)
		{
			cout << setw(7) << score[i][j];
		}
		cout << setw(8) << average[i] << endl;
	}
}