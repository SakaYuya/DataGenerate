#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Student;
class Students;
class Date;
class RandomIntegerGenerator;
class RandomStudentGenerator;
class Output;

class Student {
private:
	int MSSV = 0;
	string name;
	double GPA = 0;
	string tele;
	string email;
	string DOB;
	string address;
public:
	//Getter & Setter
	int getMSSV();
	string getName();
	double getGPA();
	string getTelephone();
	string getEmail();
	string getDOB();
	string getAddress();

	void setMSSV(int);
	void setName(string);
	void setGPA(double);
	void setTelephone(string);
	void setEmail(string);
	void setDOB(string);
	void setAddress(string);
public:
	Student(int, string, double, string, string, string, string);
	string toString();
 };

class Students {
private:
	vector<Student> students;
public:
	vector<Student> getStudents();
	Students();
	double getAverageGPA();
};

class Date {
private:
	int _day;
	int _month;
	int _year;

public:
	Date(int day, int month, int year) {
		this->_day = day;
		this->_month = month;
		this->_year = year;
	}

	string toString() {
		stringstream builder;

		builder << _day << "/"
			<< _month << "/"
			<< _year;

		string result = builder.str();
		return result;
	}
};


class RandomIntegerGenerator {
public:
	RandomIntegerGenerator();
public:
	int next();
	int next(int);
	int next(int, int);
};

class RandomDateGenerator {
private:
	int _day;
	int _month;
	int _year;
	RandomIntegerGenerator _rng;
public:
	//RandomDateGenerator();
	Date next();
};


class RandomStudentGenerator {
private:
	int MSSV = 0;
	vector<string> name;
	double GPA = 0;
	vector<string> tele;
	string email; //Dua theo ten
	string DOB;
	vector<string> address;
	RandomIntegerGenerator _rng;
public:
	RandomStudentGenerator();
	Student next();
};

class Output {
	void printAllGPA(Students s);
	void printGPA_Greater(Students s);
};


