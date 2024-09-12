//Samantha Lopez-Montano
//Calculates and displays the occupancy rate for a hotel

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Variables
	int counter = 1,
		num_of_floors = 0,
		num_of_rooms = 0,
		rooms_occupied = 0,
		empty_rooms = 0;
	double occupancy_rate = 0,
		total_rooms_occupied = 0,
		total_num_of_rooms = 0;

	//Prompts and stores the number of floors of a hotel
	do
	{
		cout << "How many floors does the hotel have? ";
		cin >> num_of_floors;
		if (num_of_floors < 1)
		{
			cout << "\nPlease enter a number greater than 0." << endl << endl;
		}
	} while (num_of_floors < 1);

	//Prompt and stores the number of rooms on floors and the amount occupied
	while (counter <= num_of_floors)
	{
		do
		{
			cout << "\n\nHow many rooms are on floor " << counter << "? ";
			cin >> num_of_rooms;
			if (num_of_rooms < 0)
			{
				cout << "\nError - Invalid - Re-enter Postiive Number" << endl;
			}
		} while (num_of_rooms < 0);
		
		do
		{
			cout << "How many of those rooms are occupied? ";
			cin >> rooms_occupied;
			if (rooms_occupied > num_of_rooms)
			{
				cout << "\nError - Invalid - Re-enter number greater than or equal to number of rooms" << endl;
			}
		} while (rooms_occupied > num_of_rooms);
		
		total_num_of_rooms += num_of_rooms;
		total_rooms_occupied += rooms_occupied;
		counter++;
	}

	//Calculates the hotels total empty rooms and occupancy rate
	empty_rooms = total_num_of_rooms - total_rooms_occupied;
	occupancy_rate = (total_rooms_occupied / total_num_of_rooms) * 100.00;

	//Displays the hotel's total rooms, total occupied rooms, 
	//total empty rooms, and the occupancy rate
	cout << "\n\nThe hotel has a total of " << total_num_of_rooms << " rooms." << endl;
	cout << total_rooms_occupied << " are occupied." << endl;
	cout << empty_rooms << " are empty." << endl;
	cout << setprecision(1) << fixed << showpoint;
	cout << "The occupancy rate is " << occupancy_rate << "%" << endl;
}