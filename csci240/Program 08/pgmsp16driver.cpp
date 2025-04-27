/***************************************************************
CSCI 240         Program 8     Spring 2016

Programmer:		 

Section:		 

Date Due:		

Purpose: 		The purpose of this program is to implement
				and use the methods for a class called Employee.
				
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int ID_MAX = 9999999;
const int ID_MIN = 1000;

//Employee Class Definition
class Employee
{
public:
  Employee();
  Employee( const char [], int, double );
    
  void printEmp();
  void increaseSalary( double );

  void setIDnum( int );
  void setSalary( double );

  int getIDnum();
  double getSalary();

private:
  char name[25];
  int idNum;
  double salary;
};


int main()
{
cout << fixed << setprecision(2);
//Create 5 Employee objects.


//First Employee

//Create the object
Employee e1= Employee( "Marty Minogue", 1788493, 678367732.40);

//Display the first employee's information
cout<<"The first Employee object : "<<endl;
e1.printEmp();
cout<<endl;


//Increase the first employee's salary and display the updated results
e1.increaseSalary(115.15);
e1.printEmp();
cout<<endl<<endl<<endl;

//Second Employee

//Create the object
Employee e2;

//Display the second employee's information
cout<<"The second Employee object : "<<endl;
e2.printEmp();
cout<<endl;

//Try to increase the second employee's salary by a negative amount
e2.increaseSalary(-1000.00);
cout<<endl<<endl<<endl<< endl;


//Third Employee

//Create the object
Employee e3= Employee("Annie Walker", 24933, 820.12);

//Display the third employee's information
cout<<"The third Employee object : "<<endl;
e3.printEmp();
cout<<endl;

//Change the third employee's salary and id number
e3.setSalary(8.12);
e3.setIDnum(654321);

//Display the update information for the third employee
e3.printEmp();
cout<<endl<<endl<<endl;


//Fourth Employee

//Create the object
Employee e4= Employee("Eyal Lavin", 91781,2468.00);

//Display the fourth employee's information
cout<<"The fourth Employee object : "<<endl;
e4.printEmp();
cout<<endl;


//Try to change the id number for the fourth employee to an invalid value
e4.setIDnum(809);
cout<<endl;

//Change the fourth employee's salary and display just the updated salary
e4.setSalary(9517.53);

cout<<"Employee 4 has a salary of $"<<e4.getSalary()<<endl<<endl;


//Display the update information for the fourth employee
e4.printEmp();
cout<<endl<<endl<<endl;


//Fifth Employee Object

//Create the object
Employee e5= Employee("Auggie Anderson",2012,71940.76);

//Display the fifth employee's information
cout<<"The fifth Employee object : "<<endl<<endl;
e5.printEmp();
cout<<endl;


//Try to change the salary for the fifth employee to a negative amount
e5.setSalary(-1000);
cout<<endl;

//Display only the id number for the fifth employee
cout<<"Employee 5 has an identification number of "<<e5.getIDnum()<<endl<<endl;

//Display the update information for the fifth employee
e5.printEmp();
cout<<endl<<endl<<endl;

return 0;
}


//Code the constructors and methods for the Employee class after this line

Employee::Employee()
{
strcpy(name, "");
idNum = 0;
salary = 0.00;	
}

Employee::Employee(const char newArray[] , int newID, double newSal)
{
strcpy(name, newArray);
idNum = newID;
salary = newSal;
}

void Employee::printEmp()
{
cout << "Employee Name: "<< name << "\tID: " << idNum << "\tSalary: " << salary;
}

void Employee::increaseSalary(double incrementAmount)
{
if(incrementAmount <= 0)
	{
	cout << "ERROR: salary cannot be increased";
	}
else
	{
	salary += incrementAmount;
	}
}


void Employee::setIDnum(int newIDnum)
{
if(newIDnum < ID_MIN || newIDnum > ID_MAX)
	{
	cout << "ERROR: ID number is invalid. ID = 1000";
	idNum = 1000;
	}
else
	{
	idNum = newIDnum;
	}
}

void Employee::setSalary(double newSalary)
{
if(newSalary <= 0)
	{
	cout << "error salary is less than or equal to 0, Salary = 0";
	salary = 0;
	}
else
	{
	salary = newSalary;
	}
}

int Employee::getIDnum()
{
return idNum;
}

double Employee::getSalary()
{
return salary;
}
