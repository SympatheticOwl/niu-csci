/***************************************************************
CSCI 240         Program 8     Spring 2016

Programmer:		 Lucas Damler

Section:		1 

Date Due:		22 APR @ 11:59

Purpose: 		The purpose of this program is to implement
				and use the methods for a class called Employee.
				
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int IDMAX = 9999999;
const int IDMIN = 1000;

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
Employee e1= Employee( "Lucas", 1761739, 678367732.40);

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
cout<<endl<<endl;

return 0;
}

//Empolyee constructor method for Employee
//Takes no arguments
//Initalizes values
Employee::Employee(){
	strcpy(name, "");
	idNum = 0;
	salary = 0.00;
	
}

//Employee method for Employee
//Takes three arguments char array, int, double
//Intializes values for employee object
Employee::Employee(const char newArray[] , int newID, double newSal){
	strcpy(name, newArray);
	idNum = newID;
	salary = newSal;
}

//printEmp method for Employee
//takes no arguments, returns nothing
//prints out employee name, id, and sallary
void Employee::printEmp(){
	cout << "Employee Name: "<< name << "\tID: " << idNum << "\tSalary: " << salary;
}

//increaseSalary method for Employee
//takes one double, returns nothing
//increases salary or sets salary to 0
void Employee::increaseSalary(double incrementAmount){
	if(incrementAmount <= 0){
		cout << "ERROR: salary cannot be increased";
	}
	else{
		salary += incrementAmount;
	}
}

//setIDnum method for Employee
//takes one int, returns nothing
//Sets idNum to 1000 or makes idNum = newIDnum
void Employee::setIDnum(int newIDnum){
	if(newIDnum < IDMIN || newIDnum > IDMAX){
		cout << "ERROR: ID number is invalid. ID = 1000";
		idNum = 1000;
	}
	else{
		idNum = newIDnum;
	}
}

//setSalary method for Employee
//takes a double, returns nothing
//sets salary = newSalary or = 0
void Employee::setSalary(double newSalary){
	if(newSalary <= 0){
		cout << "error salary is less than or equal to 0, Salary = 0";
		salary = 0;
	}
	else{
		salary = newSalary;
	}
}

//getIDnum method for Employee
//takes no arguments, returns an int
//returns idNum
int Employee::getIDnum(){
	return idNum;
}

//getSalary method for Employee
//takes no arguments, returns a double
//returns salary
double Employee::getSalary(){
	return salary;
}
