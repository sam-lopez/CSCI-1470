//Samantha Lopez-Montano
//Displays the scores of a student's science fair project

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Variables
	string student_name;
	int number_of_judges = 0,
		counter = 1;
	double score = 0,
		total_score = 0,
		average_score = 0;
	char again;

	do 
	{
		//Reset Variables
		counter = 1;
		total_score = 0;

		//Prompt and store student's name
		cout << "Please enter the student's name: ";
		getline(cin, student_name);

		//Prompt how many judges scored 
		do
		{
			cout << "\nHow many judges scored " << student_name << "'s project? ";
			cin >> number_of_judges;
			if (number_of_judges < 1)
			{
				cout << "\nError - Invalid - Enter Positive Number" << endl;
			}
		} while (number_of_judges < 1);

		//Prompt and store scores from user
		cout << "\nEnter the score received from each judge." << endl;
		while (counter <= number_of_judges)
		{
			do
			{
				cout << "\tJudge " << counter << ": ";
				cin >> score;
				if (score < 0 || score > 20)
				{
					cout << "\n\tInvalid score entered: Must be between 0 and 20." << endl << endl;
				}
			} while (score < 0 || score > 20);
			total_score += score;
			counter++;
		}

		//Calculates average score
		average_score = total_score / number_of_judges;

		//Displays student's total and average scores
		cout << setprecision(1) << fixed << showpoint;
		cout << endl << student_name << "'s Science Fair Project Scores: " << endl << endl;
		cout << "Total Score............" << total_score << endl << endl;
		cout << "Average Score.........." << average_score << endl << endl;

		//Prompts if user wants to run program again
		cout << "Run program again (Y for Yes, N for No) ";
		cin >> again;
		cin.get();

	} while (again == 'y' || again == 'Y');
	
}