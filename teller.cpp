#include<cstdlib>

teller::teller() {
	busy = false;
}

bool teller::isBusy() {
	return busy;
}

void teller::setCustomer(customer c)
{
	busy = true;
	currCust = c;
}

customer teller::getCustomer()
{
	return currCust;
}


