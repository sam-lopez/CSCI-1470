//Samantha Lopez-Montano
//Computes the average score for a bowler after bowling multiple games

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void)
{
	//Variables
	string bowler_name;
	int number_of_games;
	double score,
		total_score = 0,
		average_score;
	char repeat;

	//do_while loop repeats program as many times as user wants 
	do
	{
		total_score = 0;
		//Prompts user to input bowler name
		cout << "Enter bowler name: ";
		getline(cin, bowler_name);

		//Prompts user for number of games bowled until valid number is entered
		do
		{
			cout << "Number of games bowled? ";
			cin >> number_of_games;
			//Input validation error message
			if (number_of_games < 0)
				cout << "\n***ERROR: Negative number for games.***"<< endl << endl;
		} while (number_of_games < 0);

		//Prompts user to enter scores
		cout << "\nEnter " << bowler_name << " score for each of the following games: " << endl;
		for (int counter = 1; counter <= number_of_games; counter++)
		{
			do
			{
				cout << "Game " << counter << ": ";
				cin >> score;
				//Input validation error message
				if (score < 1 || score > 300)
					cout << "\n***ERROR: Score must be from 1 to 300.***" << endl << endl;
			} while (score < 1 || score > 300);
			
			total_score += score;
		}

		//Calculates average score
		average_score = total_score / number_of_games;

		//Displays the bowler name, total score, and average
		cout << "\nBowler Results: " << endl;
		cout << "Name: " << bowler_name << endl;
		cout << "Total Score: " << total_score << endl;
		cout << setprecision(1) << fixed << showpoint;
		cout << "Average Score: " << average_score << endl;

		cout << "Would you like to calculate the average for another bowler (Y or N)? ";
		cin >> repeat;
		cin.get();
		cout << endl;

	} while (repeat == 'y' || repeat == 'Y');

}