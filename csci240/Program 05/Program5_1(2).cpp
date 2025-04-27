/******************************************************************************
CSCI 240    Assignment 5    Spring 2016
Programmer:	Lucas Damler
Section:	1
TA:			?
Date Due:	04 MAR 2016 @ 23:59
Purpose:	This program takes input from user and caluclates a road trips mileage, cost, etc...			
******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

double const FLEET_AVG = 25.0;

// Your function Prototypes go here
double getGallons();
double getMiles();
double getPricePerGallon();
double calcTripMileage(double miles, double gallons);
double calcTripCost(double pricePerGallon, double gallons);
double calcTripCostPerMile(double tripCost, double miles);
double calcOverallMPG(double totalMiles, double totalGallons);
void showOneTrip(double tripMileage, double tripCost, double tripCostPerMile);
void showTotals(double totalMiles, double totalGallons, double totalCost, double overallMPG);
void showMileageComparison(double overallMPG);


int main() {
	double 	gallons	 	 	= 0,		//Place holder for user inputs
		   	miles	 	 	= 0,    	
		   	pricePerGallon 	= 0;		
	
	double 	tripMileage 	= 0,		//Place holder for one trip stats
		   	tripCost 	 	= 0,		
		   	tripCostPerMile = 0;		
	
	double 	totalGallons	= 0,		//Place holder for stats for all trips
		  	totalMiles	 	= 0,		
		  	totalCost	 	= 0;		
	
	double	overallMPG	 	= 0;		//Place holder for Overall Miles Per Gallon
	
	char	another;	             	//Holds user's answer
	
	//Print Title
	cout << "     Fuel Usage Analysis" << endl << endl;
	
	//Start do... while loop to process unknown number of trips
	do {
		//Get trip values
		gallons = getGallons();
		miles = getMiles();
		pricePerGallon = getPricePerGallon();
		
		cout << endl;
		
		//Calculate trip costs
		tripMileage = calcTripMileage(miles , gallons);
		tripCost = calcTripCost(pricePerGallon , gallons);
		tripCostPerMile = calcTripCostPerMile(tripCost , miles);
		
		//Accumulate totals
		totalGallons += gallons;
		totalMiles += miles;
		totalCost += tripCost;
		
		overallMPG = calcOverallMPG(totalMiles, totalGallons);

        //Display stats for one trip
		showOneTrip(tripMileage, tripCost, tripCostPerMile);
		
	
		cout << "Another? (y or n) ";
    	cin >> another;
		
	}
	while (another == 'y' || another =='Y');
	
	
	//Print totals of entered trips 
	showTotals(totalMiles, totalGallons, totalCost, overallMPG);
	
	//Compare overall mpg from entered trips and compare with fleet average
	showMileageComparison(overallMPG);
	
	
	return 0;
}

/***************************************************************
Function:  double getGallons() 
Use: This function gets the number of gallons from the user
Arguments:
Returns: a double value that represents the number of gallons
***************************************************************/
double getGallons(){
	cout << setiosflags(ios::fixed) << setprecision(2);
	double gallons;
	cout << "Enter number of gallons: ";
	cin >> gallons;
	while(gallons <= 0.0){
		cout << "0ut of range. Enter a number between 0 and 40";
		cin >> gallons;
	}
	return gallons;
}

/***************************************************************
Function:  double getMiles() 
Use: This function gets the number of miles from the user
Arguments:
Returns: a double value that represents the number of miles
***************************************************************/
double getMiles(){
	double miles;
	cout << "Enter number of miles: ";
	cin >> miles;
	while(miles <= 0.0){
		cout << "Out of range. Enter a number between 0 and 800";
		cin >> miles;
	}
	return miles;
}

/***************************************************************
Function:  double getPricePerGallon() 
Use: This function gets the price per gallons from the user
Arguments:
Returns: a double value that represents the price per gallon
***************************************************************/
double getPricePerGallon(){
	double pricePerGallon;
	cout << "Enter price of per gallon: ";
	cin >> pricePerGallon;
	while(pricePerGallon <= 0.0){
		cout << "Out of range. Enter a number between 2 and 7";
		cin >> pricePerGallon;
	}
	return pricePerGallon;
}

/***************************************************************
Function:  double calcTripMileage(double, double) 
Use: This function calcs the trip miles per gallon
Arguments: double: the number of miles traveled
           double: the number of gallons of fuel used for the trip
Returns: a double value that represents the trip mpg
***************************************************************/
double calcTripMileage(double miles, double gallons){
	double tripMileage;
	if(gallons <= 0){tripMileage = 0;}
	else{tripMileage = miles/gallons;}
	return tripMileage;
}

/***************************************************************
Function:  double calcTripCost(double, double) 
Use: This function calcs the trip cost
Arguments: double: the price per gallon
           double: the number of gallons
Returns: a double value that represents the trip cost
***************************************************************/
double calcTripCost(double pricePerGallon, double gallons){
	double tripCost;
	tripCost = pricePerGallon * gallons;
	return tripCost;
}

double calcTripCostPerMile(double tripCost, double miles){
	double tripCostPerMile;
	if(miles <= 0){tripCostPerMile = 0;}
	else{tripCostPerMile = tripCost/miles;}
	return tripCostPerMile;
}

double calcOverallMPG(double totalMiles, double totalGallons){
	double overallMPG;
	if(totalGallons <= 0){overallMPG = 0;}
	else{overallMPG = totalMiles/totalGallons;}
	return overallMPG;
}

void showOneTrip(double tripMileage, double tripCost, double tripCostPerMile){
	//std::cout.width(6); cout << setiosflags(ios::internal);
	cout << "Trip Mileage: " << tripMileage << " mpg" << endl;
	cout << "Trip Cost: " << "$" << tripCost << endl;
	cout << "Trip Cost per mile: " << "$" << tripCostPerMile << endl << endl;
}

void showTotals(double totalMiles, double totalGallons, double totalCost, double overallMPG){
	cout << endl << "Total Miles: " << totalMiles << endl;
	cout << "Total Gallons: " << totalGallons << endl;
	cout << "Total Cost: " << "$" << totalCost << endl;
	cout << "Overall MPG: " << overallMPG << endl;
}

void showMileageComparison(double overallMPG){
	double diff = overallMPG - FLEET_AVG;
	cout << endl;
	if(overallMPG > FLEET_AVG){
		cout << "Vehicle's mileage is greater than fleet average by " << diff;
	}
	else if(overallMPG = FLEET_AVG){
		cout << "Vehicle's mileage is equal to fleet average of " << FLEET_AVG;
	}
	else{
		cout << "Vehicle's mileage is less thant fleet average of " << diff;
	}
}

//Your function definitions go here


