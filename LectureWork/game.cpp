//Samantha Lopez-Montano
//Guess the number game

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

const int NUMBER_POSSIBLE = 100;

//Function Prototypes
string getPlayerName();
void playTheGame(string, int, int, int);

int main()
{
	int userGuess = 0,
		rand_number = 0,
		numberOfAttempts = 0;
	string player_name;
	bool repeat;

	do
	{
		//function calls
		player_name = getPlayerName();
		playTheGame(player_name, userGuess, rand_number, numberOfAttempts);

		cout << "\nWould you like to play again? (1 for Yes, 0 for No): ";
		cin >> repeat;
		cin.get();
		cout << endl << endl;

	} while (repeat);
}

string getPlayerName()
{
	string player_name;

	cout << "Welcome to Guess the Number Game" << endl;

	cout << "\nPlease enter your name: ";
	getline(cin, player_name);

	return player_name;

}

//checks the user's guess and gives the user a hint
void playTheGame(string player_name, int userGuess, int rand_number, int numberOfAttempts)
{
	//Initialize srand function with seed
	srand(time(0));

	//Compute random number (normalized to desired # of possibilities)
	rand_number = rand() % NUMBER_POSSIBLE + 1;

	numberOfAttempts = 0;

	while (userGuess != rand_number && numberOfAttempts < 7)
	{
		do
		{
			cout << endl << player_name << ", Guess a Number Between 1 and 100: ";
			cin >> userGuess;
			if (userGuess < 1 || userGuess > NUMBER_POSSIBLE)
				cout << "Invalid number entered - Must be 1 - 100";
		} while (userGuess < 1 || userGuess > NUMBER_POSSIBLE);
		numberOfAttempts++;

		if (userGuess == rand_number)
		{
			cout << "\nCongratulations, you guessed the number " << rand_number << " in " << numberOfAttempts;
		}
		else if (numberOfAttempts == 7)
		{
			cout << "\nSorry you did not guesss the number " << rand_number << endl;
		}
		else if (userGuess < rand_number)
		{
			cout << "HINT: Guess HIGHER!" << endl;
		}
		else if (userGuess > rand_number)
		{
			cout << "HINT: Guess LOWER!" << endl;
		}
	}
}