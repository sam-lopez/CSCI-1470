//Name: Samantha Lopez-Montano                                   
//Displays a person's first and last name

#include <iostream>
#include <string>
using namespace std;

int main()
{
	 // Strings with spaces - Must use getline for input
	 string name;

	 //Prompt user to enter name
	 cout << "Please enter your name: ";
	 getline(cin, name);

	 //Display name entered
	 cout << "Your name is " << name << endl << endl;

	 system("pause");
	 return 0;

}