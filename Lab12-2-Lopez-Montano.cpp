//Samantha Lopez-Montano
//User inputted string is displayed, displayed backwards, the length of the string is displayed, and the number of words in message is displayed

#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
void messageDisplay(string&, int&);
void messageLength(string, int);
void messageWords(string);
void messageBackwards(string, int);

int main()
{
	//Variables
	string message;
	int i = 0;
	bool repeat;

	//Repeats program
	do
	{
		//Function Calls
		messageDisplay(message, i);
		messageLength(message, i);
		messageWords(message);
		messageBackwards(message, i);

		//Prompts user to repeat program
		cout << "\nRun program again (Yes = 1, No = 0)? ";
		cin >> repeat;
		cin.ignore();
		cout << endl << endl;
	} while (repeat == 1);
}

//Function Definitions
//Gets and stores message
void messageDisplay(string& message, int& i)
{
	//Resets length of string
	i = 0;

	//Stores message
	cout << "Enter the message: ";
	getline(cin, message);

	//Displays message
	cout << "\nThe message you entered was: " << endl;
	while (message[i] != NULL)
	{
		cout << message[i];
		i++;
	}
}

//Gets the message length
void messageLength(string message, int i)
{
	cout << "\n\nThe length of the string entered is: " << i;
}

//Gets the number of words in the message
void messageWords(string message)
{
	int numberWords = 0;
	for (int counter = 0; message[counter] != NULL; counter++)
	{
		//When there is a space in the message the number of words goes up
		if (message[counter] == ' ')
			numberWords++;
	}
	cout << "\n\nNumber of words in message: " << numberWords + 1;
}

//Displays the message backwards
void messageBackwards(string message, int i)
{
	cout << "\n\nThe message displayed backward is: " << endl;

	for (int counter = i - 1; counter >= 0; counter--)
	{
		cout << message[counter];
	}
	cout << endl << endl;
}