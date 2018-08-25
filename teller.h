#ifndef TELLER
#define TELLER 

#include "customer.h"

class teller {
private:
	bool busy;
	customer currCust;
public:
	teller();
	bool isBusy();
	void setCustomer(customer);
	customer getCustomer();
};

#include "teller.cpp"
#endif 