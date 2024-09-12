//Samantha Lopez-Montano
//Displays and calculates if ten integers are even, odd, or negative

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void getInt(int, int []);
void sortNegative(int, int [], int [], int&);
void sortEven(int, int [], int [], int&);
void sortOdd(int , int [], int [], int&);
void display(int, int [], int [], int [], int, int, int);

int main()
{
	const int SIZE = 10;
	int integers[SIZE] = { 0 };
	int negative[SIZE] = { 0 };
	int even[SIZE] = { 0 };
	int odd[SIZE] = { 0 };
	int nCount = 0;
	int eCount = 0;
	int oCount = 0;
	bool repeat = 1;

	cout << "This program inputs 10 integers and places them into even, odd, or negative categories.";

	do
	{
		//Function Calls
		getInt(SIZE, integers);
		sortNegative(SIZE, integers, negative, nCount);
		sortEven(SIZE, integers, even, eCount);
		sortOdd(SIZE, integers, odd, oCount);
		display(SIZE, negative, even, odd, nCount, eCount, oCount);

		cout << "\n\nWould you like to process another 10 integers? Please enter 1 for Yes and 0 for No ";
		cin >> repeat;
	} while (repeat);
}

//Functions Definitions
//Prompt for 10 integers and then stores input
void getInt(int SIZE, int integers[])
{
	cout << "\n\nPlease enter 10 integers.\n";

	for (int count = 0; count < SIZE; count++)
	{
		cout << "Integer = ";
		cin >> integers[count];
	}
}

//Sorts negative inputted integers into one array
void sortNegative(int SIZE, int integers[], int negative[], int& nCount)
{
	//Resets negative array
	nCount = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (integers[i] < 0)
		{
			negative[nCount] = integers[i];
			nCount++;
		}
	}
}

//Sorts even inputted integers into one array
void sortEven(int SIZE, int integers[], int even[], int& eCount)
{
	//Resets even array
	eCount = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (integers[i] % 2 == 0)
		{
			even[eCount] = integers[i];
			eCount++;
		}
	}
}

//Sorts odd inputted integers into one array
void sortOdd(int SIZE, int integers[], int odd[], int& oCount)
{
	//Resets odd array
	oCount = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (integers[i] % 2 != 0)
		{
			odd[oCount] = integers[i];
			oCount++;
		}
	}
}

void display(int SIZE, int negative[], int even[], int odd[], int nCount, int eCount, int oCount)
{
	cout << "\nThe negative integers are: \n";
	for (int i = 0; i < nCount; i++)
	{
		cout << setw(6) << negative[i];
	}
	cout << "\n\nThe even integers are: \n";
	for (int i = 0; i < eCount; i++)
	{
		cout << setw(6) << even[i];
	}
	cout << "\n\nThe odd integers are: \n";
	for (int i = 0; i < oCount; i++)
	{
		cout << setw(6) << odd[i];
	}
}