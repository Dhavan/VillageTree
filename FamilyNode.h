/*
 * Author: Dhavan Vaidya
 * This class represents a family.
 * Each family is a child of the same village.
 * Each family can hold a maximum allowed number of members.
 * This number is specified by MAX_SIZE_FAMILY
 * 
 * The constructor of the class takes an integer as the argument.
 * This argument specifies how many members the family is going to have.
 * The reason for including amount of members in the family is: 
 * After all, what is a family without any members!!
 * 
 * For details, check associated comments within the code.
 */
#ifndef FAMILYNODE_H
#define FAMILYNODE_H

#include <iostream>
#include "MemberNode.h"
#include "VillageNode.h"

using namespace std;

const int MAX_SIZE_FAMILY = 5;	// Max allowed number of members in the given family

class FamilyNode
{
	friend class VillageNode;

public:
	FamilyNode(int);	// Constructor
	MemberNode* getRandomMember();
	MemberNode* getMember(int);
	MemberNode* getNextRelation(MemberNode *);
	void resetRelations();

private:
	MemberNode *members[MAX_SIZE_FAMILY];
	void insertMembers(int);
	int noOfMembers;
	
};

/*
 * Constructor
 * 
 * Takes number of members as integer argument
 * 
 * Instanciates given number of Members as MemberNode(s) by calling helper method
 *
 */
FamilyNode::FamilyNode(int noOfMem)
{
	noOfMembers = noOfMem;
	insertMembers(noOfMembers);
}

/*
 * Helper method to create new MemberNodes.
 * 
 * Calls consturcor of the MemberNode class.
 * 
 */
void FamilyNode::insertMembers(int noOfMem)
{
	for (int i = 0; i < noOfMem; i++)
	{
		members[i] = new MemberNode(i);
	}
}

/*
 * This method returns a random member of the calling family.
 * 
 * Checks for status of the member.
 * If the member is not in relation with another member of another family,
 * returns the member.
 * 
 */
MemberNode* FamilyNode::getRandomMember()
{
	int randomMember = rand() % 5;
	bool memberStatus = this->members[randomMember]->getStatus();

	while(memberStatus == true)
	{
		randomMember = rand() % 5;
		
		memberStatus = this->members[randomMember]->getStatus();
	}
	return members[randomMember];

}

/*
 * This method returns the desired member object.
 * One might consider this to be leaky in terms of memory.
 * But, this is intentional as we have to traverse at the parent level.
 * 
 */
MemberNode* FamilyNode::getMember(int mem)
{
	return members[mem];
}

/*
 * This method returns the related member as an object.
 * 
 * Takes a MemberNode as argument.
 * Returns the related MemberNode.
 * 
 */
MemberNode* FamilyNode::getNextRelation(MemberNode *m)
{
	MemberNode *temp = m->getRelatedFriend();
	return temp;
}

/*
 * This method resets all relations of all the members of the
 * calling family.
 */
void FamilyNode::resetRelations()
{
	for(int i = 0; i < noOfMembers; i++)
		members[i]->reset();
}

#endif