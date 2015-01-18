/*
 * Author: Dhavan Vaidya
 * 
 * This class represents a village.
 * This class is friends with FamilyNode and MemberNode classes.
 * It treats the village as the root node. Each family is the direct child of
 * the village. And Members are children of family.
 * 
 * Initiates given number of families in the village (max can be set by MAX_SIZE)
 *
 * Intiates generation of relationships among the family members.
 * Outputs noteworthy processes such as initiation of the Village etc
 * 
 * For details, check associated comments within the code.
 */

#ifndef VILLAGENODE_H
#define VILLAGENODE_H

#include <iostream>
#include <string>
#include "FamilyNode.h"
#include "MemberNode.h"

using namespace std;
const int MAX_SIZE_VILLAGE = 50;	// Max allowed number of families in the given village

class VillageNode
{
public:
	// Constructor
	VillageNode(int, int);
	void generateTree();
	void generateRelations();
	void report();

private:
	FamilyNode *family[MAX_SIZE_VILLAGE];	// Pointer to all the generated children families (nodes)
	int noOfFam;
	int noOfMem;

	int getRandomFamilyNumber();

};

VillageNode::VillageNode(int fam, int mem)
{
	noOfFam = fam;
	noOfMem = mem;
}

/*
 * Function generates a complete village filled with given number of families,
 * Each family having given number of members each.
 * Addition of members is handled by the constructor of respective FamilyNode object.
 * After all, what is a family without any members!!
 */
void VillageNode::generateTree()
{
	for (int i = 0; i < noOfFam; i++)
	{
		family[i] = new FamilyNode(noOfMem);
	}
	cout << noOfFam << " Familes generated" << endl;
}

/*
 * Function generates all the relationships among family members.
 *
 * This process is done at Village level because it makes easy to keep
 * track of families and members together.
 *
 * Iterates the following process for number_of_familes - 1 times:
 * -Starts with first family
 * -Fetches a random member of that family
 * -Fetches another random member of the next family
 * -Establishes a friendship between these two
 *
 * TODO: Manage/Revise friendship assignment to ensure reporting.
 */

void VillageNode::generateRelations()
{
	for(int i = 0; i < noOfFam; i++)
		family[i]->resetRelations();

	for (int i = 0; i < noOfMem; i++)
	{
		//cout << "------------Iteration " << i << "------------" << endl;

		MemberNode *member1 = family[0]->getMember(i);
		for (int j = 1; j < noOfFam; j++)
		{
			MemberNode *member2 = family[j]->getRandomMember();

			member1->setFriend(member2, j);

			member1 = member2;
		}
	}
}

void VillageNode::report()
{
	cout << "\n\n\n------------Reporting Status of Relationships------------" << endl;

	for( int i = 0; i < noOfMem; i++)
	{
		MemberNode *firstMember = family[0]->getMember(i);
		int familyTrack = 0;

		cout << endl << "\nF" << familyTrack << "M" << firstMember->index;

		for( int j = 0; j < noOfFam - 1; j++)
		{
			MemberNode *secondMember = family[familyTrack]->getNextRelation(firstMember);

			familyTrack = secondMember->getRelatedFamily();
			if(familyTrack == 0)
				break;
			
			cout  << "->";
			cout << "F" << familyTrack << "M" << secondMember->index;

			MemberNode *temp = family[familyTrack]->getNextRelation(secondMember);

			firstMember = secondMember;
		}
	}
}

int VillageNode::getRandomFamilyNumber()
{
	return rand() % 50;
}

#endif