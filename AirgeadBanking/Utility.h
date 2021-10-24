
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Utility
{
public:
	static void center(string text, char fill, int length);
	static void center(float text, char fill, int length);
	static void input(string prompt, int& val);
	static void input(string prompt, float& val);
};
#endif