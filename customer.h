#ifndef CUSTOMER
#define CUSTOMER 



class customer {
private:
	int arrivalTime;
	int departureTime;
	int waitTime;
	int timeLeft;
public:
	customer();
	int getTimeLeft();
	void timePass();
	void setArrivalTime(int);
	void setDepartureTime(int);
	int getWaitTime();
};

#include "customer.cpp"
#endif 
