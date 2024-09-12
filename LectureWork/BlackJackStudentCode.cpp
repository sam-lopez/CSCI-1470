

//Name: Samantha Lopez-Montano

/******************************************************************************************************
	2 of Hearts card is worth 2 points - display if the random # is 2
	3 of Hearts card is worth 3 points - display if the random # is 3
	4 of Hearts card is worth 4 points - display if the random # is 4
	5 of Hearts card is worth 5 points - display if the random # is 5
	6 of Hearts card is worth 6 points - display if the random # is 6
	7 of Hearts card is worth 7 points - display if the random # is 7
	8 of Hearts card is worth 8 points - display if the random # is 8
	9 of Hearts card is worth 9 points - display if the random # is 9
	10 of Hearts card is worth 10 points - display if the random # is 10
	Jack of Hearts card is worth 10 points - display if the random # is 11
	Queen of Hearts card is worth 10 points - display if the random # is 12
	King of Hearts card is worth 10 points - display if the random # is 13
	Ace of Hearts card is worth 11 points - display if the random # is 14

*********************************************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Prototypes
void deal(int&, int&); //randomly pick 2 cards from the deck - must Pass by Reference 
void displayCard(int); //displays each card that was dealt
int computeScore(int, int); //Add the 2 card values together
void displayResults(int); //display the total of the 2 cards and if the total is 21, displays BLACKJACK

int main()
{
	int repeat = 1;
	do 
	{
		int card1 = 0; //stores a random-generate number between 2 and 14
		int card2 = 0; //stores a random-generate number between 2 and 14
		int total = 0; //total of both random-generate numbers representing card1 and card2
		
		deal(card1, card2);	  //Deal the cards randomly 
		displayCard(card1);	  //Displays 1st card
		displayCard(card2);	  //Displays 2nd card next to 1st card
		total = computeScore(card1, card2);	//Compute the score
		displayResults(total); //displays the total of the 2 cards and if the total is 21, display BLACKJACK
		
		cout << "\n\nWould you like to play again (1 for Yes, 0 for No) ";
		cin >> repeat;
	} while (repeat);
	return 0;
}


void deal(int& card1, int& card2)
{
	//Set the seed using the time function- srand(time(0));
	srand(time(0));
	
	//Generate two unique ranodm numbers - need 13 numbers stating with 2
	card1 = rand() % 13 + 2;	//Generates 1st random number between 2 and 14 for card1

	do
	{
		card2 = rand() % 13 + 2;  //Generate 2nd random number for card2 - - need 13 numbers stating with 2
	} while (card2 == card1); // card1 and card2 must be different  
}

void displayCard(int card)
{
	cout << "_______" << endl;
	if (card == 10)
		cout << "|" << card << "   |" << endl;
	else if (card == 14)
		cout << "|" << 'A' << "    |" << endl;
	else if (card == 13)
		cout << "|" << 'K' << "    |" << endl;
	else if (card == 12)
		cout << "|" << 'Q' << "    |" << endl;
	else if (card == 11)
		cout << "|" << 'J' << "    |" << endl;
	else
		cout << "|" << card << "    |" << endl;
	cout << "|     |" << endl;
	cout << "|     |" << endl;
	cout << "|_____|" << endl;
}

int computeScore(int card1, int card2)
{
	int total = 0;

	if (card1 == 2)
		total += 2;
	else if (card1 == 3)
		total += 3;
	else if (card1 == 4)
		total += 4;
	else if (card1 == 5)
		total += 5;
	else if (card1 == 6)
		total += 6;
	else if (card1 == 7)
		total += 7;
	else if (card1 == 8)
		total += 8;
	else if (card1 == 9)
		total += 9;
	else if (card1 == 10)
		total += 10;
	else if (card1 == 11)
		total += 10;
	else if (card1 == 12)
		total += 10;
	else if (card1 == 13)
		total += 10;
	else if (card1 == 14)
		total += 11;


	if (card2 == 2)
		total += 2;
	else if (card2 == 3)
		total += 3;
	else if (card2 == 4)
		total += 4;
	else if (card2 == 5)
		total += 5;
	else if (card2 == 6)
		total += 6;
	else if (card2 == 7)
		total += 7;
	else if (card2 == 8)
		total += 8;
	else if (card2 == 9)
		total += 9;
	else if (card2 == 10)
		total += 10;
	else if (card2 == 11)
		total += 10;
	else if (card2 == 12)
		total += 10;
	else if (card2 == 13)
		total += 10;
	else if (card2 == 14)
		total += 11;

	return(total);
}

void displayResults(int score)
{
	//Display "Total Score is: " with the calcualted score at position x, y + 125
	cout << "\nTotal Score is: " << score << endl;

	//if score is equal to 21, display "Blackjack!!!!" at position x, y + 125
	if (score == 21)
		cout << endl << endl << "****Blackjack!!!****" << endl;
}
