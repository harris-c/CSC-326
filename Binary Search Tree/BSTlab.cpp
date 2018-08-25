// BSTlab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include "userInfo.h"
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

int main()
{
	BST<userInfo> tree;
	ifstream inFile;
	bool cont = true;

	inFile.open("usernameList.txt");
	if (!inFile) {
		cout << "Error opening file!" << endl;
	}
	while (!inFile.eof()) {
		userInfo u;
		inFile >> u;
		tree.insert(u);
	}
	while (cont == true) {
		string user;
		string pass;
		userInfo test;
		string val;

		cout << "Please enter a username: ";
		cin >> user;
		cout << "Please enter a password: ";
		cin >> pass;
		test.setUsername(user);
		test.setPassword(pass);
		if (tree.search(test) == true) {
			cout << "This is a valid username/password combination" << endl;
		}else{
			cout << "This is not a valid username/password combination" << endl;
		}
		cout << "Would you like to enter another username?(Y/N)";
		cin >> val;
		cout << endl;
		if (val == "N") {
			cont = false;
		}
	}
	tree.inorder(cout);
}

