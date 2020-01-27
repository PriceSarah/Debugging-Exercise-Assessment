// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;


// Is there a zergling Alive
bool zerglingAlive(vector<Zergling> swarm)
{
	return swarm.size() > 0;
}

// Is there a Marine Alive?
bool marineAlive(vector<Marine> squad)
{
	return squad.size() > 0;
}

int main()
{
	vector<Marine> squad;
	vector<Zergling> swarm;

	int squadSize = 10;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	Marine m;
	for (size_t i = 0; i < squadSize; i++)
	{
		squad.push_back(m);
	}

	for (size_t i = 0; i < squadSize; i++)
	{
		Zergling z;
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad) && zerglingAlive(swarm)) // If anyone is left alive to fight . . .
	{
		// if there's at least one marine alive
		if (marineAlive(squad)) 
		{
			// go through the squad
			for (size_t i = 0; i < squadSize; i++) 
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				int damage = squad[i].attack();
				swarm[0].takeDamage(damage);
				// if the zergling dies, it is removed from the swarm
				if (!swarm[0].isAlive()) 
				{
					cout << "The zergling target dies" << endl;
					swarm.erase(swarm.begin());
				}
			}
		}

		// if there's at least one zergling alive
		if (zerglingAlive(swarm)) 
		{
			// loop through zerglings
			for (vector<Zergling>::iterator i = swarm.begin(); i != swarm.end(); ++i) 
			{
				cout << "A zergling attacks for " << i->attack() << " damage." << endl;
				squad.begin()->takeDamage(i->attack());
				if (squad.begin()->isAlive())
				{

				}
				else
					squad.erase(squad.begin());
					cout << "The marine succumbs to his wounds." << endl;
					
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad))
	{
		cout << "The Marines win." << endl;

	} else 
	{
		cout << "The Zerg win." << endl;
	}
}




