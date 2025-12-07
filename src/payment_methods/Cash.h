#pragma once
#include<iostream>
#include "Payment.h"
using namespace std;

class Cash:public Payment{
public:
	Cash(int);
	~Cash();
	void performPayment() override;
	void getInfo() override;
};