/*  
	Samantha Lopez-Montano
	Calculates the total and average points
	for each member of a bowling team and the 
	total and average for the team
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Variables
	string bowler_name;
	int number_of_games,
		number_of_bowlers;
	double score,
		total_score = 0,
		team_total = 0,
		average_score,
		team_average;
	char repeat;

	//Displays program description
	cout << "************************************************************";
	cout << "\n*     This program calculates the total and average        *";
	cout << "\n*       points for each member of a bowling team.          *";
	cout << "\n* The team's total and average points are also calculated. *";
	cout << "\n************************************************************";

	//do_while loop repeats program as many times as user wants 
	do
	{
		team_total = 0;
		//Prompts user to enter number of bowlers until valid number is entered
		do
		{
			cout << "\nPlease enter the number of bowlers on team: ";
			cin >> number_of_bowlers;
			if (number_of_bowlers < 0)
				cout << "\n***ERROR: Negative number for bowlers***\n\n";
		} while (number_of_bowlers < 0);

		//Prompts user for number of games bowled until valid number is entered
		do
		{
			cout << "Please enter the number of games the team competed in: ";
			cin >> number_of_games;
			//Input validation error message
			if (number_of_games < 0)
				cout << "\n***ERROR: Negative number for games.***\n\n";
		} while (number_of_games < 0);

		//Prompts user to input bowler information
		for (int bowlerCounter = 1; bowlerCounter <= number_of_bowlers; bowlerCounter++)
		{
			cout << "\nEnter bowler " << bowlerCounter << "'s name: ";
			cin.get();
			getline(cin, bowler_name);
			total_score = 0;

			//Prompts user to enter scores
			cout << "Enter the points earned by " << bowler_name << " for each game. " << endl;
			for (int counter = 1; counter <= number_of_games; counter++)
			{
				do
				{
					cout << "Game " << counter << ": ";
					cin >> score;
					//Input validation error message
					if (score < 0 || score > 300)
						cout << "\n***ERROR: Score must be from 0 to 300.***" << endl << endl;
				} while (score < 0 || score > 300);

				total_score += score;
				team_total += score;
			}

			//Calculates average score
			average_score = total_score / number_of_games;

			//Displays the bowler name, total score, and average
			cout << "\n" << bowler_name << ":" << endl;
			cout << "\tTotal Points: " << total_score << endl;
			cout << setprecision(1) << fixed << showpoint;
			cout << "\tAverage Points: " << average_score << endl;
		}
		
		//Calculates team average
		team_average = team_total / number_of_bowlers / number_of_games;

		//Displays the team score and average
		cout << "\nTeam Total Points: " << team_total;
		cout << "\nAverage Team Points per Game: " << team_average;

		cout << "\nWould you like to calculate the stats on another team (Y or N)? ";
		cin >> repeat;
		cin.get();
		cout << endl;

	} while (repeat == 'y' || repeat == 'Y');

}