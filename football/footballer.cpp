#include "footballer.h"

Footballer::Footballer()
	:name(""), surname(""), goalsPerYear(0), coef(1.0)
{
}

Footballer::Footballer(string name, string surname, int goals)
	:name(name), surname(surname), goalsPerYear(goals), coef(1.0)

{
}

Footballer::~Footballer()
{
}

int Footballer::getGoalsPerYear() const
{
	return goalsPerYear;
}


void Footballer::setCoef(double coefficient)
{
	coef = coefficient;
}

double Footballer::salaryPerYear() const
{
	return goalsPerYear * coef;
}

void Footballer::printFootballer() const
{
	cout << "Footballer: " << name << " " << surname << endl;
	cout << "Goals per year: " << goalsPerYear << endl;
	cout << "Salary coefficient: " << coef << endl;
	cout << "Salary per year: " << salaryPerYear() << "$" << endl;
}

void Footballer::readFrom(istream& is)
{
	is >> name >> surname >> goalsPerYear;
}

istream& operator>>(std::istream& is, Footballer& F)
{
	F.readFrom(is);
	return is;
}
