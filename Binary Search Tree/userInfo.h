#ifndef USERINFO
#define USERINFO
#include<string>
#include <iostream>
using namespace std;
class userInfo {
private:
	string username;
	string password;
public:
	friend istream & operator>>(istream & in, userInfo & ui) {  
		in >> ui.username >>ui.password;
		return in;
	}
	friend ostream & operator<<(ostream & out, const userInfo & u) {
		out << "The username " << u.username << " has password " << u.password << endl;
		return out;
	}
	bool operator==(const userInfo & u) const
	{
		return username == u.username && password==u.password;
	}
	bool operator < (const userInfo & u) const
	{
		return username < u.username;
	}
	void setUsername(string user) {
		username = user;
	}
	void setPassword(string pass) {
		password = pass;
	}
 };































#endif 
