#pragma once
#include "footballer.h"

class FootballClub
{
private:
	string clubName;
	double clubCoef;
	Footballer* footballers;
	int maxSize;
	int currSize;

public:
	FootballClub();
	FootballClub(string name, double coef);
	FootballClub(const FootballClub& FC);
	~FootballClub();

	string getName() const;
	void addFootballer(Footballer& F);
	void printFootballClub() const;
	void sortByDecreaseGoals();
	int getTotalGoals() const;
	double getTotalSalary() const;



};

