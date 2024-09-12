//Samantha Lopez-Montano
//Displays and calculates the average score made on exams

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function Prototypes
void getData(string&, int, int [], int&);
double calcAvg(int, int);
void highLowScores(int, int [], int&, int&);
void passOrFail(int, int [], int&, int&);
void scoresPerLetter(int, int[], int&, int&, int&, int&, int&);
void display(string, int, int [], double, int, int, int, int, int, int, int, int, int);

int main()
{
	string name;
	const int NUMBER_OF_SCORES = 12;
	int score[NUMBER_OF_SCORES] = { 0 };
	int total = 0;
	double average;
	int highest;
	int lowest;
	int numberPassed = 0;
	int numberFailed = 0;
	int scoreA = 0;
	int scoreB = 0;
	int scoreC = 0;
	int scoreD = 0;
	int scoreF = 0;
	bool repeat;

	//Allows user to run program again
	do
	{
		//Function Calls
		getData(name, NUMBER_OF_SCORES, score, total);
		average = calcAvg(total, NUMBER_OF_SCORES);
		highLowScores(NUMBER_OF_SCORES, score, highest, lowest);
		passOrFail(NUMBER_OF_SCORES, score, numberPassed, numberFailed);
		scoresPerLetter(NUMBER_OF_SCORES, score, scoreA, scoreB, scoreC, scoreD, scoreF);
		display(name, NUMBER_OF_SCORES, score, average, highest, lowest, numberPassed, numberFailed, scoreA, scoreB, scoreC, scoreD, scoreF);

		cout << "\n\nWould you like to calculate the average for another exam? (1 for Yes, 0 for No) ";
		cin >> repeat;
		cin.ignore();
		cout << endl;
	} while (repeat);
	
}

//Function Definitions
//Collects the exam name and scores by students
void getData(string& name, int NUMBER_OF_SCORES, int score[], int& total)
{
	//Prompts for exam name and saves input
	cout << "Please enter the name of the exam: ";
	getline(cin, name);

	total = 0;
	//Prompts for scores and saves input
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		//Validates input
		do
		{
			cout << "Enter Score " << i + 1 << ": ";
			cin >> score[i];
			//Displays error message
			if (score[i] < 0 || score[i] > 100)
				cout << "\nError: Must enter number between 0 and 100\n\n";
		} while (score[i] < 0 || score[i] > 100);
		total = total + score[i];
	}
}

//Calculates the average score
double calcAvg(int total, int NUMBER_OF_SCORES)
{
	double average = 0;
	average = total / double(NUMBER_OF_SCORES);
	return average;
}

//Calculates the highest and lowest scores
void highLowScores(int NUMBER_OF_SCORES, int score[], int& highest, int& lowest)
{
	highest = score[0];
	lowest = score[0];
	//Calculates the highest score
	for (int i = 1; i < NUMBER_OF_SCORES; i++)
	{
		if (score[i] > highest)
			highest = score[i];
	}

	//Calculates the lowest score
	for (int i = 1; i < NUMBER_OF_SCORES; i++)
	{
		if (score[i] < lowest)
			lowest = score[i];
	}
}

//Calculates how many students pass or fail
void passOrFail(int NUMBER_OF_SCORES, int score[], int& numberPassed, int& numberFailed)
{
	numberPassed = 0;
	numberFailed = 0;
	//Calculates how many students passed and failed
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		if (score[i] >= 60)
			numberPassed++;
		else
			numberFailed++;
	}
}

//Calculates the number of scores per letter grade
void scoresPerLetter(int NUMBER_OF_SCORES, int score[], int& scoreA, int& scoreB, int& scoreC, int& scoreD, int& scoreF)
{
	scoreA = 0;
	scoreB = 0;
	scoreC = 0;
	scoreD = 0;
	scoreF = 0;
	//Calculates how many students got A, B, C, D, or F scores
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		if (score[i] >= 90)
			scoreA++;
		else if (score[i] >= 80)
			scoreB++;
		else if (score[i] >= 70)
			scoreC++;
		else if (score[i] >= 60)
			scoreD++;
		else if (score[i] < 60)
			scoreF++;
	}
}

//Displays each score, the average score, the highest and lowest scores, the
//number of passing and failing students, and the number of scores per letter grade
void display(string name, int NUMBER_OF_SCORES, int score[], double average, int highest, int lowest, int numberPassed, int numberFailed, int scoreA, int scoreB, int scoreC, int scoreD, int scoreF)
{
	cout << "\nThe scores for " << name << " are:\n";
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		cout << score[i] << " ";
	}
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n\nThe average score is: " << average;
	cout << "\n\nThe highest score is: " << highest;
	cout << "\nThe lowest score is: " << lowest;
	cout << "\n\nNumber of students who passed: " << numberPassed;
	cout << "\nNumber of students who failed: " << numberFailed;
	cout << "\n\nThe number of exams represented by each letter grade is as follows:";
	cout << "\nA's: " << scoreA;
	cout << "\nB's: " << scoreB;
	cout << "\nC's: " << scoreC;
	cout << "\nD's: " << scoreD;
	cout << "\nF's: " << scoreF;
}