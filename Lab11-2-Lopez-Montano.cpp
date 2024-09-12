//Samantha Lopez-Montano
//Calculates and displays NFL quarterback passing averages

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Global Constants
const int TOP_Q_B = 7;

//Stuctures
struct PlayerRecord
{
	string name;
	int completions = 0;
	int attempts = 0;
	double average = 0;
};

//Function Prototypes
void getInfo(PlayerRecord[], int&, int&);
void calculateAve(PlayerRecord[], int, int, double&, string&);
void display(PlayerRecord[], int, int, double, string);

int main()
{
	//Variables
	int totalCompletions = 0;
	int totalAttempts = 0;
	double totalAverages = 0;
	string highest;

	//Declare an array of structures
	PlayerRecord quarterback[TOP_Q_B];

	//Function Calls
	getInfo(quarterback, totalCompletions, totalAttempts);
	calculateAve(quarterback, totalCompletions, totalAttempts, totalAverages, highest);
	display(quarterback, totalCompletions, totalAttempts, totalAverages, highest);
}

//Function Definitions
//Gets each quarterback name, completions, and attempts
void getInfo(PlayerRecord quarterback[], int& totalCompletions, int& totalAttempts)
{
	totalCompletions = 0;
	totalAttempts = 0;

	for (int i = 0; i < TOP_Q_B; i++)
	{
		cout << "Please enter Quarterback number " << i + 1 << "'s name: ";
		getline(cin, quarterback[i].name);

		cout << "Please enter Quarterback number " << i + 1 << "'s completions: ";
		cin >> quarterback[i].completions;
		totalCompletions += quarterback[i].completions;

		cout << "Please enter Quarterback number " << i + 1 << "'s attempts: ";
		cin >> quarterback[i].attempts;
		totalAttempts += quarterback[i].attempts;
		cout << endl;
		cin.ignore();
	}
}

//Calculates each player's average, total average, and the highest average
void calculateAve(PlayerRecord quarterback[], int totalCompletions, int totalAttempts, double& totalAverages, string& highest)
{
	highest = quarterback[0].name;

	for (int i = 0; i < TOP_Q_B; i++)
	{
		//Calculates each player's individual average
		quarterback[i].average = quarterback[i].completions / double(quarterback[i].attempts);

		//Finds the quarterback name with the highest average
		if (quarterback[i].average > quarterback[0].average)
			highest = quarterback[i].name;
	}
	//Calculates the total average
	totalAverages = totalCompletions / double(totalAttempts);
}

//Displays each player's completions, attempts, and averages, and the total completions, attempts, and averages, and the highest average player
void display(PlayerRecord quarterback[], int totalCompletions, int totalAttempts, double totalAverages, string highest)
{
	cout << setprecision(3) << fixed << showpoint;
	cout << "\nQuarterback" << "\t\tCompletions" << "\t\tAttempts" << "\t\tAVE\n\n";
	for (int i = 0; i < TOP_Q_B; i++)
	{
		cout << setw(29) << left << quarterback[i].name;
		cout << setw(22) << quarterback[i].completions;
		cout << setw(20) << quarterback[i].attempts;
		cout << setw(20) << quarterback[i].average;
		cout << endl;
	}

	cout << setw(31) << "\n\nTotals" << setw(22) << totalCompletions << setw(20) << totalAttempts << setw(20) << totalAverages;

	cout << "\n\n" << highest << " wins the EPSY award for highest average of completed passes.\n\n";
}