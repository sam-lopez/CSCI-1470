//Samantha Lopez-Montano
//Displays and calculates the average score and letter grade earned by a student in any course

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function Prototypes
string getStudentName();
int getNumberExams();
int getScoresAndCalculateTotal(int);
double calculateAverage(int, double);
char determineLetterGrade(double);
void displayAverageGrade(string, double, char);

int main()
{
	string name;
	int number_of_exams;
	double total;
	double average;
	char letterGrade;
	char repeat;

	do
	{
		//Function Calls
		name = getStudentName();
		number_of_exams = getNumberExams();
		total = getScoresAndCalculateTotal(number_of_exams);
		average = calculateAverage(number_of_exams, total);
		letterGrade = determineLetterGrade(average);
		displayAverageGrade(name, average, letterGrade);

		//Prompts user to repeat program
		cout << "\n\nWould you like to calculate another student's grade (Y or N)? ";
		cin >> repeat;
		cin.ignore();
		cout << endl;
	} while (repeat == 'y' || repeat == 'Y');
	
}

//Function Definitions
string getStudentName()
{
	string name;
	//Prompts user for student name and saves input
	cout << "Please enter the student's name: ";
	getline(cin, name);

	return name;
}

int getNumberExams()
{
	int number_of_exams;
	//Loops prompt until user enters valid input
	do
	{
		//Prompts user for the number of exams and saves input
		cout << "Please enter the number of exams taken by the student in the course: ";
		cin >> number_of_exams;
		//Error message
		if (number_of_exams < 1)
			cout << "\nInvalid input - Number of exams must be greater than zero\n\n";
	} while (number_of_exams < 1);

	return number_of_exams;
}

int getScoresAndCalculateTotal(int number_of_exams)
{
	double score;
	double total = 0;
	//Prompts user for exam scores
	cout << "\nEnter the Exam scores: \n";
	//Loops score prompts for the number of exams
	for (int counter = 1; counter <= number_of_exams; counter++)
	{
		//Loops prompt until user enters valid input
		do
		{
			cout << "Exam " << counter << ": ";
			cin >> score;
			//Error message
			if (score < 0 || score > 100)
				cout << "\nInvalid input - Score must be between 0 and 100\n\n";
		} while (score < 0 || score > 100);

		total += score;
	}

	return total;
}

double calculateAverage(int number_of_exams, double total)
{
	//Calculates and returns the average of the exams
	return total / number_of_exams;
}

char determineLetterGrade(double average)
{
	//Determines a student's letter grade
	char letterGrade;
	if (average >= 90 && average <= 100)
		letterGrade = 'A';
	else if (average >= 80 && average < 90)
		letterGrade = 'B';
	else if (average >= 70 && average < 80)
		letterGrade = 'C';
	else if (average >= 60 && average < 70)
		letterGrade = 'D';
	else if (average >= 0 && average < 60)
		letterGrade = 'F';

	return letterGrade;
}

void displayAverageGrade(string name, double average, char letterGrade)
{
	//Displays the student's name, average, and letter grade
	cout << "\nStudent Name: " << name;
	cout << setprecision(1) << fixed << showpoint;
	cout << "\nAverage: " << average;
	cout << "\nLetter Grade Earned: " << letterGrade;
}