#include "City.h"
using namespace std;

void City::addNames()
{
	ifstream myFile;
	string line;
	myFile.open("PersonList.txt", ios::in);
	for (int i = 0; i < 2000; i++) {
		while (getline(myFile, line)) {
			listNames.push_back(line);
		}
	}
}

void City::createPeople()
{
	for (int i = 0; i < 1990; i++) {
		string name = listNames.at(i);
		int wRand = rand() % 6;		//Random work location for starting ignorants
		int hRand = rand() % 6;		//Random home location for starting ignorants
		Ignorant* ig = new Ignorant(name, hRand, wRand);
		if (hRand == 0)
			Docks.push_back(ig);
		else if (hRand == 1)
			MedicalHill.push_back(ig);
		else if (hRand == 2)
			Downtown.push_back(ig);
		else if (hRand == 3)
			University.push_back(ig);
		else if (hRand == 4)
			Soho.push_back(ig);
		else
			Uptown.push_back(ig);
	}
	for (int i = 0; i < 5; i++) {
		string name = listNames.at(1990 + i);
		int hStart = 1;		//Sets home start for the created zombies to one (Medical Hill)
		int wStart = 1;		//Sets workLoc for the created zombies to one (Medical Hill)
		Zombie* zom = new Zombie(name, hStart, wStart);
		MedicalHill.push_back(zom);
	}
	for (int i = 0; i < 5; i++) {
		string name = listNames.at(1995 + i);
		int hStart = 4;		
		int wStart = 1;		//Sets the start for these alarmed people to where the outbreak began (medical hill)
		Alarmed* alarm = new Alarmed(name, hStart, wStart);
		MedicalHill.push_back(alarm);
	}
}

void City::sortPeople()		//Fills the personMap with data from the locations
{
	for (unsigned int i = 0; i < Docks.size(); i++) {
		personMap.insert(make_pair(Docks.at(i)->getPersonState(), Docks.at(i)));
	}
	for (unsigned int i = 0; i < MedicalHill.size(); i++) {
		personMap.insert(make_pair(MedicalHill.at(i)->getPersonState(), MedicalHill.at(i)));
	}
	for (unsigned int i = 0; i < Downtown.size(); i++) {
		personMap.insert(make_pair(Downtown.at(i)->getPersonState(), Downtown.at(i)));
	}
	for (unsigned int i = 0; i < University.size(); i++) {
		personMap.insert(make_pair(University.at(i)->getPersonState(), University.at(i)));
	}
	for (unsigned int i = 0; i < Soho.size(); i++) {
		personMap.insert(make_pair(Soho.at(i)->getPersonState(), Soho.at(i)));
	}
	for (unsigned int i = 0; i < Uptown.size(); i++) {
		personMap.insert(make_pair(Uptown.at(i)->getPersonState(), Uptown.at(i)));
	}
}

void City::countPeople()
{
	int iCount = personMap.count(0);
	int aCount = personMap.count(1);
	int zCount = personMap.count(2);

	cout << "Number of Ignorant citizens: " << iCount << endl;
	cout << "Number of Alarmed citizens:" << aCount << endl;
	cout << "Number of Zombies: " << zCount << endl;
}

void City::fillDistrict()
{
	District.push_back(Docks);
	District.push_back(MedicalHill);
	District.push_back(Downtown);
	District.push_back(University);
	District.push_back(Soho);
	District.push_back(Uptown);
}


