#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "City.h"
#include "Zombie.h"
using namespace std;

void findInteract(Person &p, City &c)
{
	int myLoc = p.getCurrentLoc();
	int population = c.District.at(myLoc).size();
	int random = rand() % population;
	//cout << random << endl;
	vector<Person*>::iterator it = c.District.at(myLoc).begin() + random;
	Person* newAlarmed = p.interact(*c.District.at(myLoc).at(random));
	c.District.at(myLoc).erase(it);
	c.District.at(myLoc).push_back(newAlarmed);
	/*c.sortPeople();
	c.countPeople();*/
}

int main()
{
	srand(time(NULL));
	City Spokane;
	Spokane.addNames();
	Spokane.createPeople();
	Spokane.fillDistrict();

	int runtimeDays;
	cout << "How many days do you want to simulate?" << endl;
	cin >> runtimeDays;

	int totalClicks = runtimeDays * 4;
	for (int i = 0; i < totalClicks; i++) {
		Spokane.sortPeople();
		multimap<int, Person*>::iterator it = Spokane.personMap.begin();
		while (it != Spokane.personMap.end()) {
			if (it->first == 0) {
				if (i % 2 == 1) {
					it->second->move();
					++it;
				}
				else {
					++it;
					continue;
				}
			}
			else if (it->first == 1) {
				findInteract(*it->second, Spokane);
				it->second->move();
				++it;
			}
			else if (it->first == 2) {
				findInteract(*it->second, Spokane);
				it->second->move();
				++it;
			}
		}
		Spokane.countPeople();
		Spokane.personMap.clear();
	}

	return 0;
}