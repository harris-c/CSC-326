#include <cstdlib>

customer::customer() {
arrivalTime = 0;
departureTime = 0;
timeLeft = rand() % 10 + 1;
}

void customer::setArrivalTime(int t) {
	arrivalTime = t;
}

void customer::setDepartureTime(int t) {
	departureTime = t;
}

int customer::getWaitTime() {
	return departureTime - arrivalTime;
	
}

int customer::getTimeLeft() {
	return timeLeft;
}

void customer::timePass()
{
	timeLeft--;
}

