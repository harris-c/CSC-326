// bankingSim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArrayQueue.h"
#include "customer.h"
#include "teller.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

bool customerArrival();
teller bindCustomer(ArrayQueue<customer>*, teller&);
customer freeCustomer(ArrayQueue<customer>*, teller&);
int availT(teller[]);
void passTime(teller[]);

int main()
{
	double customerCount = 0;
	double totalWaitTime = 0;
	double avgWait = 0;
	int timeNow = 1;
	int tIndex = 0;		//has value of index of open teller 

	teller busyT[5];			// array of busy tellers 
	ArrayQueue<customer>* custLine = new ArrayQueue<customer>;

	//popuate array with 5 empty tellers 
	for (int i = 0; i < 5; i++) {
		teller t;
		busyT[i] = t;
	}
	//get random sequence every time program run
	srand(time(NULL));

	for (timeNow; timeNow <= 100; timeNow++) {
		if (customerArrival() == true) {
			customerCount++;
			customer c;
			c.setArrivalTime(timeNow);
			custLine->enqueue(c);
		}
		int tIndex = availT(busyT);
		// if line is empty, clock ticks on  
		if (custLine->isEmpty()) {

		}
		//assuming line has at least 1 customer 
		//if teller available, bind next customer to them
		else if (tIndex >= 0) {
			teller t;
			bindCustomer(custLine, t);
			busyT[tIndex] = t;
		}
		//if service time over, release customer & get wait time
		for (int i = 0; i <= 5; i++) {
			if (busyT[i].isBusy()==true && busyT[i].getCustomer().getTimeLeft() <= 0) {
				customer x = freeCustomer(custLine, busyT[i]);
				busyT[i] = teller();
				x.setDepartureTime(timeNow);
				totalWaitTime += x.getWaitTime();
			}
		}

		//always decrement- clock ticking
		 passTime(busyT);
	}
	
	//resolves customers still on line after bank closes (timeNow > 100)
	while (custLine->isEmpty() == false) {
		int tIndex = availT(busyT);
		if (tIndex >= 0) {
			teller t;
			bindCustomer(custLine, t);
			busyT[tIndex] = t;
		}
		//if service time over, release customer & get wait time
		for (int i = 0; i <= 5; i++) {
			if (busyT[i].getCustomer().getTimeLeft() <= 0) {
				customer x = freeCustomer(custLine, busyT[i]);					
				x.setDepartureTime(timeNow);
				totalWaitTime += x.getWaitTime();
			}
		}

		//always decrement- clock ticking
		passTime(busyT);

		timeNow++;	
	}
	
	avgWait = totalWaitTime / customerCount;

	cout << "There were " << customerCount << " customers served. ";
	cout << "The total wait time was " << totalWaitTime <<" minutes." << endl;
	cout << "The average wait time was " << avgWait << " minutes." << endl << endl;

}

bool customerArrival() {
	float custArrivalChance = float((rand()) / float(RAND_MAX));
	// 20 % channce of arrival
	if (custArrivalChance <= .2) {
		return true;
	}
	else {
		return false;
	}
}

teller bindCustomer(ArrayQueue<customer>* Q, teller&  t) {
	customer c = Q->peekFront();
	Q->dequeue();
	t.setCustomer(c);
	return t;
}

customer freeCustomer(ArrayQueue<customer>* Q, teller& t) {
	customer free;
	free = t.getCustomer();
	return free;
}

int availT(teller t [] ) {
	int pos = -1;
	for (int i = 0; i < 5; i++) {
		if (t[i].isBusy() == false) {
			return i;
		}
	}
	return pos;
}

void passTime(teller t[]) {
	for (int i = 0; i < 5; i++) {
		if (t[i].isBusy() == true) {
			customer ct = t[i].getCustomer();
			ct.timePass();
			t[i].setCustomer(ct);
		}
	}
}