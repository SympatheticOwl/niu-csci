/******************************************************************************
CSCI 240    Assignment 10    Spring 2016
Programmer:	Lucas Damler (worked with Marty Minogue)
Section:	1
TA:			?
Date Due:	05 MAY 2016 @ 11:59
Purpose: 	calculate a students grade
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

class Student{
	public:
		Student(const char[], int, int, int, double);
		
		void setPgmPts(int);
		void setQuizPts(int);
		void setSum2Low(int);
		void setExamPts(double);
		
		double calcPgmAverage();
		double calcExamAndQuizAverage();
		double calcCourseAverage();
		char letterGrade();
		
		void printStudent();
		
	private:
		char sName[50];
		int prgPnt;
		int quizPnt;
		int loQuizes;
		double examPnt;
		static const int PRG_MAX;
		static const int QIZ_MAX;
		static const int LOQIZ_MAX;
		static const double EXAM_MAX;
};

//Constant values to represent point maxes
const int Student::PRG_MAX = 905;
const int Student::QIZ_MAX = 120;
const int Student::LOQIZ_MAX = 20;
const double Student::EXAM_MAX = 300.00;

int main(){
	char userName[50];
	int userPrg, userQuiz, userLoQuiz;
	double userExam;
	
	cout << std::fixed << setprecision(2);
	
	//The following creates multiple student classes
	Student stu1 = Student("Lucas", 767, 106, 10, 286.50);
	stu1.printStudent();
	cout << endl << endl;
	
	Student stu2 = Student("Pat Jones", 474, 53, 0, 218.50);
	stu2.printStudent();
	cout << endl << endl;
	
	Student stu3 = Student("Chris Wilson", 905, 120, 20, 300);
	stu3.printStudent();
	cout << endl << endl;
	
	Student stu4 = Student("Arnswaldo", -900, -316, -82, -44);
	stu4.printStudent();
	cout << endl << endl;
	
	//Changes invalid values to valid ones
	stu4.setQuizPts(107);
	stu4.setSum2Low(8);
	stu4.setPgmPts(639);
	stu4.setExamPts(211.50);
	stu4.printStudent();
	cout << endl << endl;
	
	//Extra credit. Enter data values to pass into student object
	cout << "Enter name: "; cin >> userName;
	cout << "Enter program points: "; cin >> userPrg;
	cout << "Enter quiz points: "; cin >> userQuiz;
	cout << "Enter sum of two lowest quiz scores: "; cin >> userLoQuiz;
	cout << "Enter exam score: "; cin >> userExam;
	cout << endl << endl;
	
	Student stu5 = Student(userName, userPrg, userQuiz, userLoQuiz, userExam);
	stu5.printStudent();
	
	return 0;
}

//Class contructor
//takes 5 arguments
//implements each data memeber to a valid number
Student::Student(const char newSName[], int newPrgPnt, int newQuizPnt, int newLoQuizes, double newExamPnt){
	strcpy(sName, newSName);
	setPgmPts(newPrgPnt);
	setQuizPts(newQuizPnt);
	setSum2Low(newLoQuizes);
	setExamPts(newExamPnt);
}

//takes one argument, an int
//sets program points to a valid number
//returns nothing
void Student::setPgmPts(int newPgmPts){
	if(newPgmPts < 0 || newPgmPts > PRG_MAX){
		cout << "ERROR!!! NUMBER OF PROGRAM POINTS IS INVALID. Program points = 0" << endl;
		prgPnt = 0;
	}
	else{
		prgPnt = newPgmPts;
	}
}

//takes one argument, an int
//sets quiz points to a valid number
//returns nothing
void Student::setQuizPts(int newQuizPts){
	if(newQuizPts < 0 || newQuizPts > QIZ_MAX){
		cout << "ERROR!!! NUMBER OF QUIZ POINTS IS INVALID. Quiz points = 0" << endl;
		quizPnt = 0;
	}
	else{
		quizPnt = newQuizPts;
	}
}

//takes one argument, an int
//sets lowest 2 quiz points to a valid number
//returns nothing
void Student::setSum2Low(int newSum2Low){
	if(newSum2Low < 0 || newSum2Low > LOQIZ_MAX){
		cout << "ERROR!!! LOWEST QUIZ POINTS ARE INVALID. Lowest quiz points = 0" << endl;
		loQuizes = 0;
	}
	else{
		loQuizes = newSum2Low;
	}
}

//takes one argument, a double
//sets exam points to a valid number
//returns nothing
void Student::setExamPts(double newExamPts){
	if(newExamPts < 0 || newExamPts > EXAM_MAX){
		cout << "ERROR!!! EXAM POINTS ARE INVALID. Exam points = 0" << endl;
	}
	else{
		examPnt = newExamPts;
	}
}

//takes no arguments
//calculates program points percentage
//returns a double
double Student::calcPgmAverage(){
	double avg;
	avg = (prgPnt/(double)PRG_MAX)*100;
	return avg;
}

//takes no arguments
//calculates exam and quiz points minus lowest quizes percentage
//returns a double
double Student::calcExamAndQuizAverage(){
	double testAvg;
	testAvg = ((examPnt+quizPnt-loQuizes)/(EXAM_MAX+QIZ_MAX-LOQIZ_MAX))*100;
	return testAvg;
}

//takes no arguments
//calculates overall class grade percentage
//returns a double
double Student::calcCourseAverage(){
	double courseAvg, prgAvg, testAvg;
	prgAvg = calcPgmAverage()*0.3;
	testAvg = calcExamAndQuizAverage()*0.7;
	courseAvg = prgAvg + testAvg;
	return courseAvg;
	
}

//takes no arguments
//decides what the course average is represented in letter form
//returns a char
char Student::letterGrade(){
	char grade;
	double crsAvg = calcCourseAverage();
	
	if(crsAvg >= 90.00 && crsAvg <= 100.00){grade = 'A';}
	else if(crsAvg < 90.00 && crsAvg >= 80.00){grade = 'B';}
	else if(crsAvg < 80.00 && crsAvg >= 70.00){grade = 'C';}
	else if(crsAvg < 70.00 && crsAvg >= 60.00){grade = 'D';}
	else{grade = 'F';}
	
	return grade;
}

//takes no arguments
//displays student object percentages
//returns nothing
void Student::printStudent(){
	double prgAvg = calcPgmAverage();
	double eqAvg = calcExamAndQuizAverage();
	double crsAvg = calcCourseAverage();
	char grade = letterGrade();
	
	cout << "Student: " << sName << endl;
	cout << "   Program Average: " << std::right << std::setw(15) << prgAvg << endl;
	cout << "   Exam and Quiz Average: " << std::right << std::setw(9) << eqAvg << endl;
	cout << "   Course Average: " << std::right << std::setw(16) << crsAvg << endl;
	cout << "   Grade: " << std::right << std::setw(25) << grade;
}
