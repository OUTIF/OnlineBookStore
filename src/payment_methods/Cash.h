#pragma once
#include<iostream>
#include "Payment.h"
using namespace std;

class Cash:public Payment{
public:
	Cash(int);
	void performPayment() override;
	void getInfo() override;
};