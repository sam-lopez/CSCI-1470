//Samantha Lopez-Montano
//Calculates and displays the average of 5 students on a golf team after 3 rounds

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Named constants
const int NUM_OF_STUDENTS = 5;
const int NUM_OF_ROUNDS = 3;

//Function Prototypes
void getNames(string[]);
void getScores(string [], int [][NUM_OF_STUDENTS]);
void averageStudent(int [][NUM_OF_STUDENTS], double []);
void averageRound(int [][NUM_OF_STUDENTS], double []);
void bestAverage(string [], double [], double& , string&);
void display(string [], int score[][NUM_OF_STUDENTS], double [], double [], double , string);

int main()
{
	//Variables
	string name[NUM_OF_STUDENTS];
	int score[][NUM_OF_STUDENTS] = { 0 };
	double studentAverage[] = { 0 };
	double roundAverage[] = { 0 };
	double bestStudentAverage = 0;
	string bestAverageName;

	//Function Calls
	getNames(name);
	getScores(name,score);
	averageStudent(score, studentAverage);
	averageRound(score, roundAverage);
	bestAverage(name, studentAverage, bestStudentAverage, bestAverageName);
	display(name, score, studentAverage, roundAverage, bestStudentAverage, bestAverageName);
}

//Function Definitions
//Gets the names of the student's and stores in 1D array
void getNames(string name[])
{
	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		cout << "Please enter Player " << i + 1 << "'s name: ";
		getline(cin,name[i]);
		
	}
}

//Gets the scores for each player for each round and stores in 2D array
void getScores(string name[], int score[][NUM_OF_STUDENTS])
{
	for (int column = 0; column < NUM_OF_STUDENTS; column++)
	{
		cout << "\n\nPlease enter " << name[column] << "'s scores:\n";
		for (int row = 0; row < NUM_OF_ROUNDS; row++)
		{
			cout << "Please enter Round " << row + 1 << ": ";
			cin >> score[row][column];
		}
	}
}

//Calculates the average score for each student and stores in 1D array
void averageStudent(int score[][NUM_OF_STUDENTS], double studentAverage[])
{
	int total = 0;
	for (int column = 0; column < NUM_OF_STUDENTS; column++)
	{
		total = 0;								//Resets total
		for (int row = 0; row < NUM_OF_ROUNDS; row++)
		{
			total = total + score[row][column];
		}
		studentAverage[column] = total / double(NUM_OF_ROUNDS);
	}
}

//Calculates the average score for each round
void averageRound(int score[][NUM_OF_STUDENTS], double roundAverage[])
{
	int total = 0;
	for (int row = 0; row < NUM_OF_ROUNDS; row++)
	{
		total = 0;								//Resets total
		for (int column = 0; column < NUM_OF_STUDENTS; column++)
		{
			total = total + score[row][column];
		}
		roundAverage[row] = total / double(NUM_OF_ROUNDS);
	}
}

//Calculates the best student average from all rounds
void bestAverage(string name[], double studentAverage[], double& bestStudentAverage, string& bestAverageName)
{
	bestStudentAverage = studentAverage[0];

	for (int i = 0; i < NUM_OF_ROUNDS; i++)
	{
		if (studentAverage[i] < bestStudentAverage)
		{
			bestStudentAverage = studentAverage[i];
			bestAverageName = name[i];
		}
	}
}

//Displays each player's scores and average scores and the round average scores as well as the best average score
void display(string name[], int score[][NUM_OF_STUDENTS], double studentAverage[], double roundAverage[], double bestStudentAverage, string bestAverageName)
{
	cout << "\nPlayer" << "\t\tRound 1" << "\t\tRound 2" << "\t\tRound 3" << "\t\tAve./Student\n";
	for (int row = 0; row < NUM_OF_STUDENTS - 1; row++)
	{
		cout << endl << name[row];
		for (int column = 0; column < NUM_OF_ROUNDS; column++)
		{
			cout << setw(6) << score[row][column];
			cout << setprecision(1) << setw(6) << studentAverage[row];
		}
	}
	cout << "\n\nAve./Round";
	for (int i = 0; i < NUM_OF_ROUNDS; i++)
	{
		cout << setprecision(1) << setw(6) << roundAverage;
	}

	cout << endl << bestAverageName << " with a " << bestStudentAverage << " average had the best average student average from the rounds of golf.\n\n";
}