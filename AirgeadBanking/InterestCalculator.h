#ifndef INTEREST_CALCULATOR_H
#define INTEREST_CALCULATOR_H

#include <iostream>
#include <conio.h>
#include <limits>
#include "Utility.h"

using namespace std;

class InterestCalculator
{
public:
	void getInput();
	void printWithMonthlyDeposit();
	void printWithoutMonthlyDeposit();
private:
	void printHeader();
private:
	float m_initialInvestment, m_monthlyDeposit, m_annualInterest;
	int m_numberOfYears;
};
#endif

