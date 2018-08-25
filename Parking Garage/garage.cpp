#include "stdafx.h"
#include"ArrayStack.h"
#include <iostream>
#include  <string>
using namespace std;


garage::garage()
{
}

void garage::arrive(string plate)
{
	car c;
	c.plateNum = plate;
	c.moves = 0;
	//true if room in garage
	if (lane1->push(c)) {
		cout << "Car with plate number " << plate << " was parked in lane 1." << endl;
	}
	else if(lane2->push(c)){
		cout << "Car with plate number " << plate << " was parked in lane 2." << endl;
	}
	else {
		cout << "There is no room in the garage to park the car." << endl;
	}

}

void garage::depart(string plate) {
	car a;
	a.plateNum = plate;
	car c;
	// if in lane 1 
	if (lane1->search(a)) {
		//and not at top of stack
		while (lane1->peek().plateNum != a.plateNum) {
			c.plateNum = lane1->peek().plateNum;
			if (move(lane1, lane2)) {
			}
			else {
				move(lane1, street);
			}
		}

		c = lane1->peek();
		cout << "The car with plate number " << c.plateNum << " has departed from lane 1." << endl;
		cout << "It was moved " << c.moves << " times." << endl;
		//clear street
		while (!street->isEmpty()) {
			c.plateNum = street->peek().plateNum;
			if (move(street, lane1)) {
			}
			else {
				move(street, lane2);
			}

		}
	}
	//in lane 2 
	else if (lane2->search(a)) {
		//and not at top of stack
		while (lane2->peek().plateNum != a.plateNum) {
			c.plateNum = lane2->peek().plateNum;
			if (move(lane2, lane1)) {
			}
			else {
				move(lane2, street);
			}
		}
		c = lane2->peek();
		cout << "The car with plate number " << c.plateNum << " has departed from lane 2. " 
			 << "It was moved " << c.moves << " times." << endl;
		//clear street 
		while (!street->isEmpty()) {
			c.plateNum = street->peek().plateNum;
			if (move(street, lane2)) {
			}
			else {
				move(street, lane1);
			}
		}

	}
	// not in either lane 
	else {
		cout << "Your car has been stolen and it is not in our garage." << endl;
	}
}


bool garage::move(ArrayStack<car>* from, ArrayStack<car>* to) {
	car c;
	c.plateNum = from->peek().plateNum;
	c.moves = from->peek().moves + 1;
	if (to->push(c)) {
		from->pop();
		return true;
	}
	else {
		return false;
	}
}