#pragma once
#include <string>
using namespace std;

class Customer {

private:

	long customerID;
	string name;
	string address;
	string phone;
	double bonus;
	string email;
	string username;
	string password;

public:

	void sendBill(); // Not figured

	long getCustomerID();
	void setCustomerID(long);

	string getName();
	void setName(string);

	string getAddress();
	void setAddress(string);

	string getPhone();
	void setPhone(string);

	double getBonus();
	void setBonus(double);

	string getEmail();
	void setEmail(string);

	string getUsername();
	void setUsername(string);

	string getPassword();
	void setPassword(string);

	bool checkAccount(string, string);  // Not figured

	void addBonus(double);

	void useBonus();



};
