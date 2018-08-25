// garageDriver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"garage.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string status;
	string plate;
	garage G;
	ifstream inFile;

	inFile.open("carList.txt");
	if (!inFile) {
		cout << "Error not in file" << endl;
	}
	while (!inFile.eof()) {
		inFile >> status >> plate;
		if (status == "A") {
			G.arrive(plate);
		}
		else if (status == "D") {
			G.depart(plate);
		}
		else {
			cout << "Error invalid status " << endl;
		}
	}

	inFile.close();
	cout << endl;
    return 0;
}

