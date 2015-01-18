/*
 * Author: Dhavan Vaidya
 * This class represents a member of a family.
 * Each member is a child of one family.
 * 
 * The constructor of the class takes an integer as the argument.
 * This argument specifies the member number within the family.
 * This is like saying, this is the first guy in this family, this is second one
 * and so on.
 * 
 * For details, check associated comments within the code.
 */
#ifndef MEMBERNODE_H
#define MEMBERNODE_H

#include <iostream>
#include <string>
#include "FamilyNode.h"
#include "VillageNode.h"

using namespace std;

class MemberNode
{
	friend class VillageNode;

public:
	int index;	// Number of the member in the family

	// Constructor
	MemberNode(int);

	void setFriend(MemberNode *,int);
	bool getStatus();
	int getRelatedFamily();
	MemberNode* getRelatedFriend();
	void reset();

private:
	bool status;	// Holds status as 0 or 1 as un-related or related, in that order.
	MemberNode *relatedFriend;	// Holds pointer to the related friend.
	int relatedFamily;	// Holds the _number_ of the related family. Shortcut to traverse.
};

/*
 * Constructor
 * 
 * Initiates every property to 0
 * Initiates index with the given argument
 */
MemberNode::MemberNode(int i)
{
	status = false;
	relatedFriend = 0;
	relatedFamily = 0;
	index = i;
}

/*
 * Estabilshes relationship between the calling member and
 * MemberNode passed via argument.
 *
 * Sets the status as 1 representing "in-relationship"
 */
void MemberNode::setFriend(MemberNode *memNode, int famNode)
{
	relatedFriend = memNode;
	relatedFamily = famNode;
	status = true;
}

/*
 * Returns relationship status of the given member
 * as 0 (un-related) or 1 (related)
 */
bool MemberNode::getStatus()
{
	return this->status;
}

/*
 * Returns the family number of the member's friend.
 */
int MemberNode::getRelatedFamily()
{
	return relatedFamily;
}

/*
 * Returns pointer to friend member.
 * This should be considered leaky. But it is only used for printing.
 * 
 * Makes printing simple.
 */
MemberNode* MemberNode::getRelatedFriend()
{
	return this->relatedFriend;
}

/*
 * Resets all properties to 0 except index.
 */
void MemberNode::reset()
{
	status = false;
	relatedFriend = 0;
	relatedFamily = 0;
}

#endif