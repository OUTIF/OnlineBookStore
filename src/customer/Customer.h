/*


STUDENT NAME: YOUSIF HUSSEIN JABBAR AL-GBURI
STUDENT NO  : 152120231144



*/



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

	Customer(long Id = 0, string Name = "", string Address = "", string Phone = "",
		double Bonus = 0, string Email = "", string UserName = "", string Password = "");;

	~Customer();

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

	bool checkAccount(string, string); 

	void addBonus(double);

	void useBonus();

	void getInfo();

	


};
