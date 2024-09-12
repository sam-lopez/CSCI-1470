//Samantha Lopez-Montano
//Lottery Game using imported files

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int LOT_NUMS = 7;            //Max number of lottery numbers
const int MAX_STUDENTS = 50;       //Max number of students
const int MAX_MATCHES = 7;         //Max number of matched numbers
const int SECOND_MATCHES = 6;      //Second place number of matched numbers
const int THIRD_MATCHES = 5;       //Third place number of matched numbers
const double MAX_PRIZE = 20.00;    //Max prize
const double SECOND_PRIZE = 10.00; //Second place prize
const double THIRD_PRIZE = 5.00;   //Third place prize

//Stucture
struct LotteryRecord
{
	int ID;
	string name;
	int guessLottery[LOT_NUMS] = { 0 };
	int matches = 0;
	double prize = 0.0;
};

//Function Prototypes
void getLotteryNumbers(int []);
void fileInput(int [], LotteryRecord[], int&);
void calcWinners(int[], LotteryRecord[], int);
void displayResultsReport(LotteryRecord[], int);
void displayWinningsReport(LotteryRecord[], int);

int main()
{
	//Variables
	int lotteryNum[LOT_NUMS] = { 0 };
	LotteryRecord student_list[MAX_STUDENTS];
	int totalStudents;

	//Function Calls
	getLotteryNumbers(lotteryNum);
	fileInput(lotteryNum, student_list, totalStudents);
	calcWinners(lotteryNum, student_list, totalStudents);
	displayResultsReport(student_list, totalStudents);
	displayWinningsReport(student_list, totalStudents);
}

//Function Definitions
//Prompts and stores lottery numbers from user
void getLotteryNumbers(int lotteryNum[])
{
	cout << "Enter the 7 different, random numbers between 1 and 50 that were selected.\n";

	for (int i = 0; i < LOT_NUMS; i++)
	{
		//Validates number between 1 and 50 and repeats until valid
		do
		{
			cout << "\nNumber " << i + 1 << ": ";
			cin >> lotteryNum[i];

			if (lotteryNum[i] < 1 || lotteryNum[i] > 50)
				cout << "\n\nPlease Enter number between 1 and 50\n\n";
		} while (lotteryNum[i] < 1 || lotteryNum[i] > 50);
	}
}

//Saves the file input into the student_list structure
void fileInput(int lotteryNum[], LotteryRecord student_list[], int& totalStudents)
{
	ifstream inFile;

	inFile.open("guesses1.txt");

	if (!inFile)
		cout << "\n\n*****ERROR OPENING FILE*****\n\n";
	else
	{
		//File input is saved to student_list structure if file correctly opens
		while (!inFile.eof())
		{
			for (int index = 0; index < MAX_STUDENTS; index++)
			{
				inFile >> student_list[index].ID;
				getline(inFile, student_list[index].name);
				for (int lot = 0; lot < LOT_NUMS; lot++)
				{
					inFile >> student_list[index].guessLottery[lot];
				}
				totalStudents = index;
				if (inFile.eof())
					break;
			}
		}
	}
	inFile.close();
}

//Calculates the number of matches and the prize earned for each student
void calcWinners(int lotteryNum[], LotteryRecord student_list[], int totalStudents)
{
	//Calculates the total number of matches for each student
	for (int i = 0; i < totalStudents; i++)
	{
		for (int lot = 0; lot < LOT_NUMS; lot++)
		{
			for (int index = 0; index < LOT_NUMS; index++)
			{
				if (lotteryNum[index] == student_list[i].guessLottery[lot])
					student_list[i].matches++;
			}
		}		
	}

	//Calculates the prize earned for each student
	for (int i = 0; i < totalStudents; i++)
	{
		if (student_list[i].matches == MAX_MATCHES)			//7 Total number of matched numbers
			student_list[i].prize = MAX_PRIZE;				//Max prize
		else if (student_list[i].matches == SECOND_MATCHES) //6 Total number of matched numbers
			student_list[i].prize = SECOND_PRIZE;			//Second prize
		else if (student_list[i].matches == THIRD_MATCHES)  //5 Total number of matched numbers
			student_list[i].prize = THIRD_PRIZE;			//Third prize
	}	
}

//Sorts student_list by name in ascending order and displays Results Report
void displayResultsReport(LotteryRecord student_list[], int totalStudents)
{
	int i, j;
	LotteryRecord temp;

	//Sorts student_list by name in ascending order
	for (i = 0; i < (totalStudents - 1); i++)
	{
		for (j = 1; j < totalStudents; j++)
		{
			if (student_list[j].name < student_list[j - 1].name)
			{
				temp = student_list[j];
				student_list[j] = student_list[j - 1];
				student_list[j - 1] = temp;
			}
		}
	}

	//Displays Results Report
	cout << "\n\n* * * * * * * * * * * * * * * * * * * Results Report * * * * * * * * * * * * * * * * * * *\n\n";
	cout << "Student ID      Student Name                  Chosen Numbers          Matches      Prize $\n\n";
	for (int i = 0; i < totalStudents; i++)
	{
		cout << setw(15) << left << student_list[i].ID;
		cout << setw(22) << student_list[i].name;
		for (int lot = 0; lot < LOT_NUMS; lot++)
		{
			cout << setw(4) << right << student_list[i].guessLottery[lot];
		}
		cout << setw(9) << student_list[i].matches;
		cout << setw(16) << setprecision(2) << showpoint << fixed << student_list[i].prize;
		cout << endl;
	}
}

//Sorts student_list into the winning groups and then displays winning groups
void displayWinningsReport(LotteryRecord student_list[], int totalStudents)
{
	//Creates new sturctures to store each winning group
	LotteryRecord student_seven[MAX_STUDENTS], student_six[MAX_STUDENTS], student_five[MAX_STUDENTS];
	//Saves the total number of students for each winning group
	int totalSeven = 0, 
		totalSix = 0, 
		totalFive = 0;

	//Sorts winning groups in ascending order from the first alphabetized student list
	for (int i = 0; i < totalStudents; i++)
	{
		if (student_list[i].matches == 7)
		{
			student_seven[totalSeven] = student_list[i];
			totalSeven++;
		}
		else if (student_list[i].matches == 6)
		{
			student_six[totalSix] = student_list[i];
			totalSix++;
		}
		else if (student_list[i].matches == 5)
		{
			student_five[totalFive] = student_list[i];
			totalFive++;
		}
	}

	//Displays winning groups
	cout << "\n\n* * * * * * * * * * * Winnings Report * * * * * * * * * * *";
	//Displays winning group for 7 matches
	cout << "\n\n************Students Who Matched All 7 Numbers************\n\n";
	cout << "Student ID      Student Name          Matches      Prize $\n\n";
	for (int i = 0; i < totalSeven; i++)
	{
		cout << setw(15) << left << student_seven[i].ID;
		cout << setw(17) << student_seven[i].name;
		cout << setw(10) << right << student_seven[i].matches;
		cout << setw(15) << setprecision(2) << showpoint << fixed << student_seven[i].prize;
		cout << endl;
	}

	//Displays winning group for 6 matches
	cout << "\n\n************Students Who Matched All 6 Numbers************\n\n";
	cout << "Student ID      Student Name          Matches      Prize $\n\n";
	for (int i = 0; i < totalSix; i++)
	{
		cout << setw(15) << left << student_six[i].ID;
		cout << setw(17) << student_six[i].name;
		cout << setw(10) << right << student_six[i].matches;
		cout << setw(15) << setprecision(2) << showpoint << fixed << student_six[i].prize;
		cout << endl;
	}

	//Displays winning group for 5 matches
	cout << "\n\n************Students Who Matched All 5 Numbers************\n\n";
	cout << "Student ID      Student Name          Matches      Prize $\n\n";
	for (int i = 0; i < totalFive; i++)
	{
		cout << setw(15) << left << student_five[i].ID;
		cout << setw(17) << student_five[i].name;
		cout << setw(10) << right << student_five[i].matches;
		cout << setw(15) << setprecision(2) << showpoint << fixed << student_five[i].prize;
		cout << endl;
	}
	cout << endl;
}