#include <iostream>
#include <Windows.h>
#include <chrono>
#include <string>
#include "ToMorse.h"


//time in microseconds
void pause(int numOfBeepTimes);
const int BEEP_TIME = 250;
const int DASH_MULTIPLIER = 3;
const int BEEP_FREQUENCY = 850;

//std::string& textToMorseText(const std::string& text);
void morseToBeeps(const std::string& morseString);

int main()
{
	std::string text;
	std::string morseString;
	std::cout << "Enter a message and I will respond in morse code." << std::endl << "Enter * to exit." << std::endl;
	std::cout << "Message: ";
	getline(std::cin, text);
	while (text != "*")
	{
		morseString = textToMorseText(text);
		morseToBeeps(morseString);
		std::cout << "Enter next message: ";
		getline(std::cin, text);
	}
	return 0;
}

void morseToBeeps(const std::string& morseString)
{
	for (std::string::const_iterator it = morseString.begin(); it != morseString.end(); it++)
	{
		std::cout << *it;

		if ((*it) == '.')
			Beep(BEEP_FREQUENCY, BEEP_TIME);

		else if ((*it) == '-')
			Beep(BEEP_FREQUENCY, BEEP_TIME * DASH_MULTIPLIER);

		else if ((*it) == ' ')
			pause(1);
		
	}

	std::cout << std::endl;
}

void pause(int numOfBeepTimes)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();

	while (std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() < numOfBeepTimes*BEEP_TIME)
	{
		finish = std::chrono::high_resolution_clock::now();
	}
}