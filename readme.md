The program addresses the following question
---------------------------------------------

There is a village.

It has X number of families (e.g. 50).
Each family has X number of members (e.g. 5)
Every member of each family forms a friend relationship with one member of another family - randomly.
After every 5 seconds, these relationships are re-formed.
One member of a family can have only one friend.

The village chief needs to know all the friendships every 30 seconds.


Details of Implementation
---------------------------------------------

Language: C++11

The data structure used is Tree - it represents the village->families->members hierarchy logically.

Root: Village
Children of Village: Families
Children of Families: Members (leaf nodes)

VillageNode class provides with 3 methods:
1. generateTree(): This initiates the whole village with user-given number of families and members.
2. generateRelations(): This generates relations between all the members according to the given criteria in the question.
3. report(): This prints the current status of all the relationships in a readable form.

main.cpp creates 2 threads - one generates new relationships every 5 seconds; another calls the report method to display the status every 30 seconds. Both the threads are attached to main() method and dies if main() ends. This saves memory resources.
Mutex support is to prevent simultaneous access to the nodes ( read operation by report() & write operation by generateRelations() ).

The threading support and mutex support are from C++11 library class "thread" & "mutex". This class makes the implementation portable for both *nix & Windows platforms. (I haven't compiled it on Mac platform)

To compile on g++ compiler:
g++ main.cpp -o -pthread -o run.out -std=c++11


Refer to comments in the source code for detailed explanation.

----------------------------------------------------------------------------------------------------