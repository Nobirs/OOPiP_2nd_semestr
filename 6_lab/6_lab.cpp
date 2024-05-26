#include <iostream>
#include <fstream>

#include "Athlete.h"
#include "Event.h"
#include "Competition.h"
#include "Team.h"
#include "Tournament.h"

using namespace std;


int main() {
	ofstream fout("SportsLog.txt", ios::app);
	if (!fout.is_open()) { cout << "Error! File not opened..." << endl; }

	Athlete a1;
	Athlete a2("Egor", 18, "Niger");

	cout << std::endl << "------------------Athletes--------------------" << std::endl;
	cout << a1;
	cout << a2;
	fout << a1;
	fout << a2;
	cout << std::endl << "--------------------------------------" << std::endl;

	Event e1;
	Event e2("Base Style", "Netherlands", "15.10.2025");
	e1.addAthlete(a1);
	e1.addAthlete(a2);
	e2.addAthlete(a1);
	e2.addAthlete(a2);

	cout << std::endl << "------------------Events--------------------" << std::endl;
	cout << e1;
	cout << e2;
	fout << e1;
	fout << e2;
	cout << std::endl << "--------------------------------------" << std::endl;

	Competition<int> c, c1;

	c.addParticipant({ a1, 1 });
	c.addParticipant({ a2, 2 });
	c1.addParticipant({ a1, 4 });
	c1.addParticipant({ a2, 5 });
	
	cout << std::endl << "------------------Competitions--------------------" << std::endl;
	cout << c;
	cout << c1;
	fout << c;
	fout << c1;
	cout << std::endl << "--------------------------------------" << std::endl;
	
	Team t;
	t.addPlayer(a1);
	t.addPlayer(a2);

	cout << std::endl << "------------------Teams--------------------" << std::endl;
	cout << t;
	fout << t;
	cout << std::endl << "--------------------------------------" << std::endl;

	Tournament tr;
	tr.addCompetition(&c);
	tr.addCompetition(&c1);

	cout << std::endl << "------------------Tournaments--------------------" << std::endl;
	cout << tr;
	fout << tr;
	cout << std::endl << "--------------------------------------" << std::endl;

	return 0;
}