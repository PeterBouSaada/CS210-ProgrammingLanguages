#include "InterestCalculator.h"

// function to print the header used in data input
void InterestCalculator::printHeader()
{
	// clear screen
	system("CLS");
	// print data input header
	Utility::center("", '*', 40);
	cout << endl;
	Utility::center("  Data Input  ", '*', 40);
	cout << endl;
}

void InterestCalculator::getInput()
{
	printHeader();
	// get all user inputs
	Utility::input("Initial Investment Amount: ", m_initialInvestment);
	Utility::input("Monthly Deposit: ", m_monthlyDeposit);
	Utility::input("Annual Interest: ", m_annualInterest);
	Utility::input("Number of years: ", m_numberOfYears);
	// call printHeader to clear the screen then show the user all data with the correct metrics.
	printHeader();
	cout << "Initial Investment Amount: $" << m_initialInvestment;
	cout << endl << "Monthly Deposit: $" << m_monthlyDeposit;
	cout << endl << "Annual Interest: %" << m_annualInterest;
	cout << endl << "Number of years: " << m_numberOfYears;
	cout << endl << "Press any key to continue (q to quit) . . ." << endl;
}
// function to calculate balance and interest without a monthly deposit only using the initial investment
void InterestCalculator::printWithoutMonthlyDeposit()
{
	// Instantiate and initialize our variables
	float openingBalance = m_initialInvestment;
	float yearEndBalance = openingBalance, yearEarnedInterest;

	// clear the screen
	system("CLS");
	// format the output as a table using the util class.
	Utility::center("Balance and interest without additional monthly deposit", ' ', 80);
	cout << endl;
	cout << setfill('=') << setw(80) << "" << endl;
	Utility::center("Year", ' ', 15);
	Utility::center("Year End Balance", ' ', 30);
	Utility::center("Year End Earned Interest", ' ', 35);
	cout << endl;
	cout << setfill('-') << setw(80) << "" << endl;

	// simple for loop that calculates interest for each year, and prints it out and ends with a newline
	for (int i = 1; i <= m_numberOfYears; i++)
	{
		yearEndBalance = openingBalance + (openingBalance * (m_annualInterest / 100.0f));
		yearEarnedInterest = yearEndBalance - openingBalance;
		Utility::center(to_string(i), ' ', 15);
		Utility::center(yearEndBalance, ' ', 30);
		Utility::center(yearEarnedInterest, ' ', 30);
		openingBalance = yearEndBalance;
		cout << endl;
	}
	cout << endl;
}

// function that calculates balance and interest with monthly deposits.
void InterestCalculator::printWithMonthlyDeposit()
{
	// Instantiate and initialize our variables
	float openingBalance = m_initialInvestment;
	float yearEndBalance = 0, yearEarnedInterest = 0, total = 0, interest = 0;

	// format the output as a table using the center functions created earlier
	Utility::center("Balance and interest with additional monthly deposit", ' ', 80);
	cout << endl;
	cout << setfill('=') << setw(80) << "" << endl;
	Utility::center("Year", ' ', 15);
	Utility::center("Year End Balance", ' ', 30);
	Utility::center("Year End Earned Interest", ' ', 35);
	cout << endl;
	cout << setfill('-') << setw(80) << "" << endl;

	// for loop that calculates the interest on a month by month basis and prints it out
	for (int i = 1; i <= m_numberOfYears; i++)
	{
		// calculate interest on a monthly basis for each year
		for (int j = 0; j < 12; j++)
		{
			total = openingBalance + m_monthlyDeposit;
			interest = total * ((m_annualInterest / 100.0f) / 12.0f);
			yearEarnedInterest += interest;
			yearEndBalance = total + interest;
			openingBalance = yearEndBalance;
		}
		Utility::center(to_string(i), ' ', 15);
		Utility::center(yearEndBalance, ' ', 30);
		Utility::center(yearEarnedInterest, ' ', 30);
		cout << endl;
		yearEarnedInterest = 0;
	}
	cout << endl;
}