#pragma once
#include <string>
#include <iostream>

using namespace std;

class Footballer
{
private:
	string name;
	string surname;
	int goalsPerYear;
	double coef;

public:
	Footballer();
	Footballer(string name, string surname, int goals);
	~Footballer();

	int getGoalsPerYear() const;
	void setCoef(double coefficient);
	double salaryPerYear() const;
	void printFootballer() const;
	void readFrom(istream& is);
};

istream& operator>>(std::istream& is, Footballer& F);