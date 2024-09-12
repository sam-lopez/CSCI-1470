// Samantha Lopez-Montano

/* 
To illustrate the extended if statement, the following program displays a 
person’s marital status corresponding to a letter input.  The following 
letter codes are used:

Marital Status   Input Code
    Married         M
    Single          S
    Divorce         D
    Widowed         W
*/

#include <iostream>

using namespace std; //introduces namespace std

int main ( void )
{
   char marital_status;		
   
   cout << "Enter a marital code: " << endl;
   cin >> marital_status;
   
   //Displays marital status message
   switch (marital_status)
   {
       case 'M':                                        //if(marital_status == 'M' || marital_status == 'm')
       case 'm':
           cout << "Individual is married." << endl;
            break;
       case 'S':                                        //if(marital_status == 'S' || marital_status == 's')
       case 's':
           cout << "Individual is single." << endl;
           break;
       case 'D': 
       case 'd':
           cout << "Individual is divorced." << endl;
           break;
       case 'W': 
       case 'w':
           cout << "Individual is widowed." << endl;
           break;
       default:
           cout << "An invalid code was entered." << endl;
   }
	  
   return 0;
}


 
  
 

    

