#pragma once
#include<iostream>
#include "Payment.h"
using namespace std;

class Cash:public Payment{
public:
	Cash(int);
	~Cash();
	bool performPayment(double) override;
	void getInfo() override;
};
