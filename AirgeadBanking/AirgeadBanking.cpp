#include "InterestCalculator.h"

int main()
{
	InterestCalculator calculator;
	char userInput;
	do
	{
		// get input for calculator
		calculator.getInput();
		// await user input
		userInput = _getch();
		// if user presses q, exit with code 0
		if (userInput == 'q')
		{
			exit(0);
		}
		// calculate without monthly deposit
		calculator.printWithoutMonthlyDeposit();
		// calculate with monthly deposit
		calculator.printWithMonthlyDeposit();
		// prompt user to press any key to retry different numbers, or q to quit
		cout << "Press any key to try different numbers or q to quit . . ." << endl;
		userInput = _getch();
	}
	while (userInput != 'q');

	return 0;
}