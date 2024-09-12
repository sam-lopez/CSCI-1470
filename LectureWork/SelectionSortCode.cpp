/******************************************************************************
  
  Name: Samantha Lopez-Montano
  
  Description   : Processes weekly pay records of employees and sorts records
                  by ID number
 
********************************C**********************************************/
#include <iostream>               
#include <iomanip>               
#include <string>

using namespace std;            //introduces namespace std

const int EMPLOYEES = 5;     // maximum number of employees
const double REG_RATE = 6.00;   // regular pay rate in $/per hour
const double OVERTIME_RATE = 9.00;   // overtime pay rate in $/per hour
const int REG_HOURS = 40;          //amount considered regular time

struct EmployeeRecord                //declare an Employee Record data type
{
  int    id_num;                           //employee identification number
  string employee_name;              //employee's name
  double hours;                          //hours worked
  double pay;                            //pay earned
};

// Prompts and gets from the user each Employee's information
void getEmployeeInfo( EmployeeRecord records[]);

// Calculates the pay of each employee
void computePay( EmployeeRecord records[]);

//Sorts records by employee ID number 
void sortRecordsByID(EmployeeRecord records[]); 

// Prints the heading of the output report
void displayHeading();

// Prints each employee's information stored in the employee's record
void displayRecords( EmployeeRecord records[]);

 int main ( void )
{
  // Declaration and Initialization Statements
  EmployeeRecord record_list[EMPLOYEES];
  
    // Function Calls
    getEmployeeInfo( record_list);
    computePay( record_list);
    sortRecordsByID(record_list);
    displayHeading();
    displayRecords(record_list);
    
     cout << "\n\nEnd of Program.";
    
  return 0;
}

//----------------------------------------------------------------------------
//Prompts user to enter each employee's information into a record
void getEmployeeInfo( EmployeeRecord records[])
{
  string dummy;                     
  for (int index = 0; index < EMPLOYEES; index++)
  {
    cout << "\nPlease enter the information for employee " << index + 1 << '.';
    cout << "\n\nEmployee ID number: ";
    cin >> records[index].id_num;
    getline( cin, dummy);
    cout << "\nEmployee name: ";
    getline( cin, records[index].employee_name);
    cout << "\nHours worked to the nearest tenth: ";
    cin >> records[index].hours;
  }
  
}


//----------------------------------------------------------------------------
//Calculates each employee's pay and stores it in the pay member in their record
void computePay( EmployeeRecord records[])
{
  for (int index = 0; index < EMPLOYEES; index++)
  {
    if (records[index].hours <= REG_HOURS)
    {
      records[index].pay = records[index].hours * REG_RATE;
    }
    else
    {
      records[index].pay = (REG_HOURS * REG_RATE) + 
                           ((records[index].hours - REG_HOURS) * OVERTIME_RATE);
    }
  }
}

                                      
//----------------------------------------------------------------------------
//Sorts the employee records by ID using the selection sort
void sortRecordsByID(EmployeeRecord records[])
{
    int i, j, minidx;
    EmployeeRecord min, temp;

    for (i = 0; i < (EMPLOYEES - 1); i++)
    {
        min.id_num = records[i].id_num;            //assume minimum is the first array element
        minidx = i;                         //index(position) of minimum element

        for (j = i + 1; j < EMPLOYEES; j++)
        {
            if (records[j].id_num < min.id_num)    //if we'be located a lower value, capture it
            {
                min = records[j];
                minidx = j;
            }
        }
        if (min.id_num < records[i].id_num)               //check if we have a new minimum and if we do, swap
        {
            temp = records[i];
            records[i] = min;
            records[minidx] = temp;
        }
    } //end outer for loop
} // end function


//----------------------------------------------------------------------------
//Displays the heading of the output report
void displayHeading()
{
  cout << endl;
  // print column titles
  cout << left << setw(12) << "ID NUMBER"
       << setw(25) << "EMPLOYEE NAME"
       << left << setw(17) << "HOURS WORKED" 
       << setw(12) << "PAY"  << endl;
  // underline titles     
  cout << left<< setw(12) << "---------"
       << setw(25) << "-------------"
       << resetiosflags(ios::left) << setw(12) << "------------" 
       << setw(8) << "---"  << endl;   
}

//----------------------------------------------------------------------------
//Displays all the information related to each employee processed
void displayRecords(EmployeeRecord records[])
{
  for (int index = 0; index < EMPLOYEES; index++)
  {
    cout << left << setw(12)
         << records[index].id_num
         << setw(25) << records[index].employee_name
         << resetiosflags(ios::left) << setprecision(1) << fixed << showpoint
         << setw(8) << records[index].hours 
         << setw(8) << "$" << setprecision(2) << fixed << showpoint
         << records[index].pay  << endl;
  }  
}

