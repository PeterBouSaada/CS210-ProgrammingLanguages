#include "Utility.h"

// function to center text given a fill character, and length of characters to center by
// If length is 80, and text length is 20 characters, there will be 30 fill characters on either side of the text
void Utility::center(string text, char fill, int length)
{
	cout << setfill(fill) << setw((length / 2) + ((text.size() / 2))) << text << setw((length / 2) - ((text.size() / 2))) << "";
}

// function to center floats given a fill character, and length of characters to center by (this function overloads the text center function)
// If length is 80, and text length is 20 characters, there will be 30 fill characters on either side of the text
// floats are printed with a fixed precision 2
void Utility::center(float num, char fill, int length)
{
	int numWidth = to_string(num).size();
	cout << fixed << setprecision(2) << setfill(fill) << setw((length / 2) + ((numWidth / 2))) << num << setw((length / 2) - ((numWidth / 2))) << "";
}

// Input function to validate integer input
void Utility::input(string prompt, int& val)
{
	cout << prompt;
	cin >> val;
	while (cin.fail() || val < 1)
	{
		cout << "Error, Please enter an integer bigger than 0: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> val;
	}
}

// Input function to validate float input
void Utility::input(string prompt, float& val)
{
	cout << prompt;
	cin >> val;
	while (cin.fail() || val < 1)
	{
		cout << "Error, Please enter a float bigger than 0: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> val;
	}
}