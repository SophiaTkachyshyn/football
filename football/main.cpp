#include <iostream>
#include "footballClub.h"
#include "footballer.h"
#include <fstream>

int main()
{
	const size_t clubSize = 3;
	FootballClub** clubs = new FootballClub*[clubSize];
    clubs[0] = new FootballClub("Barcelona", 5500.5);
	clubs[1] = new FootballClub("RealMadrid", 3700.7);
	clubs[2] = new FootballClub("AtleticoMadrid", 3500.0);

	size_t footballersSize;
	string clubName, name, surname;
	fstream fin("footballers.txt");
	fin >> footballersSize;
	for (size_t i = 0; i < footballersSize; i++)
	{
		fin >> clubName;
		if (clubName == "Barcelona")
		{
			Footballer footballPlayer;
			fin >> footballPlayer;
			clubs[0]->addFootballer(footballPlayer);
		}
		else if (clubName == "RealMadrid")
		{
			Footballer footballPlayer;
			fin >> footballPlayer;
			clubs[1]->addFootballer(footballPlayer);
		}
		else if (clubName == "AtleticoMadrid")
		{
			Footballer footballPlayer;
			fin >> footballPlayer;
			clubs[2]->addFootballer(footballPlayer);
		}
		else {
			cout << "We do not have club: " << clubName << endl;
		}
	}

	FootballClub* mostSuccesfull = clubs[0];
	FootballClub* mostExpensive = clubs[0];

	for (size_t i = 0; i < clubSize; i++)
	{
		cout << "Club #" << i + 1 << " {\n";
		clubs[i]->sortByDecreaseGoals();
		clubs[i]->printFootballClub();
		cout << "Total goals: " << clubs[i]->getTotalGoals() << "\n";
		cout << "Total salary: " << clubs[i]->getTotalSalary() << "$\n";
		cout << "}\n\n";
		if (mostSuccesfull->getTotalGoals() < clubs[i]->getTotalGoals()) {
			mostSuccesfull = clubs[i];
		}
		if (mostExpensive->getTotalSalary() < clubs[i]->getTotalSalary()) {
			mostExpensive = clubs[i];
		}
	}

	cout << "\n\n\nThe most succesfull club = " << mostSuccesfull->getName() << " : " << mostSuccesfull->getTotalGoals() << " goals" << endl;
	cout << "The most expensive club = " << mostExpensive->getName() << " : " << mostExpensive->getTotalSalary() << "$" << endl;



	return 0;
}