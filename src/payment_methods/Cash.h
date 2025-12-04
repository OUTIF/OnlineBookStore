#pragma once
#include<iostream>
#include "Payment.h"
using namespace std;

class Cash:public Payment{
public:
	void performPayment() override;
};
