/*
 * Author: Dhavan Vaidya
 * Driver class for Village.
 *
 * Creates two separate threads.
 *
 * One thread generates new relationships every 5 seconds.
 *
 * Second thread reports the status of all friendships every 30 seconds.
 * Uses mutex to manage data race conditions.
 *
 * Uses C++11 thread class.
 */
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include "VillageNode.h"

using namespace std;

std::mutex accessMutex;

void threadGenRelations(VillageNode node)
{

	chrono::milliseconds relationResetDuration(5000);
	while(true)
	{
		cout << "Generating new relationships..." << endl;
		accessMutex.lock();
		node.generateRelations();
		accessMutex.unlock();
		this_thread::sleep_for(relationResetDuration);
	}
}

void threadReport(VillageNode node)
{
	chrono::milliseconds reportDuration(30000);

	while(true)
	{
		this_thread::sleep_for(reportDuration);
		accessMutex.lock();
		node.report();
		accessMutex.unlock();
	}
	
}

int main(int argc, char const *argv[])
{
	VillageNode myVillage = VillageNode(50, 5);

	thread myThreads[2];

	int reportFlag = 0;
	int secondsCount = 0;

	cout << "Generating Tree..." << endl << endl;

	myVillage.generateTree();

	myThreads[1] = thread(threadReport, myVillage);	
	myThreads[0] = thread(threadGenRelations, myVillage);
	

	myThreads[0].join();
	myThreads[1].join();

	return 0;
}
