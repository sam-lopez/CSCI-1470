//Samantha Lopez-Montano
//Displays and calculates the average score and letter grade earned by a student in any course

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function Prototypes
void getNumberExamsAndProjects(int&, int&, int&);
void getScoresAndCalculateTotal(int, int, int, double, double, double, double, double&);
char determineLetterGrade(double);
void displayAverageGrade(double, char);

int main()
{
	int number_of_exams = 0;
	int number_of_projects = 0;
	int daily = 0; //so far 10
	double examWeight = 0.15;
	double finalExamWeight = 0.20;
	double attendanceWeight = 0.20;
	double projectWeight = 0.30;
	double average = 0;
	char letterGrade;
	char repeat;

	do
	{
		//Function Calls
		getNumberExamsAndProjects(number_of_exams, number_of_projects, daily);
		getScoresAndCalculateTotal(number_of_exams, number_of_projects, daily, examWeight, finalExamWeight, attendanceWeight, projectWeight, average);
		letterGrade = determineLetterGrade(average);
		displayAverageGrade(average, letterGrade);

		//Prompts user to repeat program
		cout << "\n\nWould you like to calculate another student's grade (Y or N)? ";
		cin >> repeat;
		cin.ignore();
		cout << endl;
	} while (repeat == 'y' || repeat == 'Y');

}

//Function Definitions
void getNumberExamsAndProjects(int& number_of_exams, int& number_of_projects, int& daily)
{
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

	//Loops prompt until user enters valid input
	do
	{
		//Prompts user for the number of projects and saves input
		cout << "Please enter the number of projects taken by the student in the course: ";
		cin >> number_of_projects;
		//Error message
		if (number_of_projects < 1)
			cout << "\nInvalid input - Number of projects must be greater than zero\n\n";
	} while (number_of_projects < 1);

	//Loops prompt until user enters valid input
	do
	{
		//Prompts user for the number of daily assignments and saves input
		cout << "Please enter the number of daily assignments taken by the student in the course: ";
		cin >> daily;
		//Error message
		if (daily < 1)
			cout << "\nInvalid input - Number of daily assignments must be greater than zero\n\n";
	} while (daily < 1);
}

void getScoresAndCalculateTotal(int number_of_exams, int number_of_projects, int daily, double examWeight, double finalExamWeight, double attendanceWeight, double projectWeight, double& average)
{
	double score;
	int counter = 0;

	//Prompts user for exam scores
	cout << "\nEnter the Exam scores: \n";
	//Loops score prompts for the number of exams
	for (counter = 1; counter < number_of_exams; counter++)
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

		score = score / 100;
		average += score * examWeight * 100;

	}

	if (counter = number_of_exams)
	{
		//Loops prompt until user enters valid input
		do
		{
			cout << "Final Exam: ";
			cin >> score;
			//Error message
			if (score < 0 || score > 100)
				cout << "\nInvalid input - Score must be between 0 and 100\n\n";
		} while (score < 0 || score > 100);

		score = score / 100;
		average += score * finalExamWeight * 100;
	}

	//Prompts user for project scores
	cout << "\nEnter the Project scores: \n";
	//Loops score prompts for the number of projects
	double projectTotal = 0;
	for (counter = 1; counter <= number_of_projects; counter++)
	{
		//Loops prompt until user enters valid input
		do
		{
			cout << "Project " << counter << ": ";
			cin >> score;
			//Error message
			if (score < 0 || score > 100)
				cout << "\nInvalid input - Score must be between 0 and 100\n\n";
		} while (score < 0 || score > 100);

		projectTotal += score;
	}
	projectTotal = projectTotal / number_of_projects;
	average += projectTotal * projectWeight * 100;


	//Prompts user for daily assignment scores
	cout << "\nEnter the Daily Assignment scores: \n";
	//Loops score prompts for the number of daily assignments
	double total = 0;
	for (counter = 1; counter <= daily; counter++)
	{
		//Loops prompt until user enters valid input
		do
		{
			cout << "Daily Assignment " << counter << ": ";
			cin >> score;
			//Error message
			if (score < 0 || score > 100)
				cout << "\nInvalid input - Score must be between 0 and 100\n\n";
		} while (score < 0 || score > 100);
		total += score;
	}

	total = total / daily;
	average += total * attendanceWeight * 100;

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

void displayAverageGrade(double average, char letterGrade)
{
	//Displays the student's name, average, and letter grade
	cout << setprecision(1) << fixed << showpoint;
	cout << "\nAverage: " << average;
	cout << "\nLetter Grade Earned: " << letterGrade;
}