#include "footballClub.h"

FootballClub::FootballClub()
	: clubName(""), clubCoef(1.0), footballers(nullptr), maxSize(30), currSize(0)
{
	footballers = new Footballer[maxSize];
}

FootballClub::FootballClub(string name, double coef)
	: clubName(name), clubCoef(coef), footballers(nullptr), maxSize(30), currSize(0)
{
	footballers = new Footballer[maxSize];
}

FootballClub::FootballClub(const FootballClub& FC)
	: clubName(FC.clubName), clubCoef(FC.clubCoef), footballers(FC.footballers), maxSize(FC.maxSize), currSize(FC.currSize)
{
}

FootballClub::~FootballClub()
{
	delete footballers;
}

string FootballClub::getName() const
{
	return clubName;
}

void FootballClub::addFootballer(Footballer& F)
{
	if (currSize < maxSize)
	{
		F.setCoef(clubCoef);
		footballers[currSize] = F;
		++currSize;
	}
	else {
		cout << "Club is full!\n";
	}
}

void FootballClub::printFootballClub() const
{
	cout << "Club name: " << clubName << endl;
	cout << "Club coef: " << clubCoef << endl;
	cout << "Number of players: " << currSize << endl;
	cout << "Footballers of this club: \n\n";

	for (int i = 0; i < currSize; i++)
	{
		cout << "Footballer #" << i + 1 << endl;
		footballers[i].printFootballer();
		cout << endl;
	}
}

void FootballClub::sortByDecreaseGoals() {
	bool swapped;
	for (int i = 0; i < currSize - 1; ++i) {
		swapped = false;
		for (int j = 0; j < currSize - i - 1; ++j) {
			if (footballers[j].getGoalsPerYear() < footballers[j + 1].getGoalsPerYear()) {
				std::swap(footballers[j], footballers[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

int FootballClub::getTotalGoals() const
{
	int total = 0;

	for (int i = 0; i < currSize; i++)
	{
		total += footballers[i].getGoalsPerYear();
	}

	return total;
}

double FootballClub::getTotalSalary() const
{
	double total = 0;

	for (int i = 0; i < currSize; i++)
	{
		total += footballers[i].salaryPerYear();
	}

	return total;
}







