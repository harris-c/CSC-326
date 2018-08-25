#include"ArrayStack.h"
#include <string>

using namespace std;

struct car {
	string plateNum;
	int moves = 0;
public:
	bool operator == (const car& x) {
		return (plateNum == x.plateNum);
	}
};
class garage {
private:
	
	 ArrayStack<car>* lane1 = new ArrayStack<car>;
	 ArrayStack<car>* lane2 = new ArrayStack<car>;
	 ArrayStack<car>* street= new ArrayStack<car>;
public:
	garage::garage();
	void arrive(string);
	void depart(string);
	bool move(ArrayStack<car>*, ArrayStack<car>*);

};
#include "garage.cpp"