#include "ToMorse.h"

const std::unordered_map<char, std::string> dictOfMorse({ 
	{ 'A',". -" },
	{ 'B',"- . . ." },
	{ 'C',"- . -." },
	{ 'D',"- . ." },
	{ 'E',"." },
	{ 'F',". . - ." },
	{ 'G',"- - ." },
	{ 'H',". . . ." },
	{ 'I',". ." },
	{ 'J',". - - -" },
	{ 'K',"- . -" },
	{ 'L',". - . ." },
	{ 'M',"- -" },
	{ 'N',"- ." },
	{ 'O',"- - -" },
	{ 'P',". - - ." },
	{ 'Q',"- - . -" },
	{ 'R',". - ." },
	{ 'S',". . ." },
	{ 'T',"-" },
	{ 'U',". . -" },
	{ 'V',". . . -" },
	{ 'W',". - -" },
	{ 'X',"- . . -" },
	{ 'Y',"- . - -" },
	{ 'Z',"- - . ." },
	{ '0',"- - - - -" },
	{ '1',". - - - -" },
	{ '2',". . - - -" },
	{ '3',". . . - -" },
	{ '4',". . . . -" },
	{ '5',". . . . ." },
	{ '6',"- . . . ." },
	{ '7',"- - . . ." },
	{ '8',"- - - . ." },
	{ '9',"- - - - ." },
	{ '.',". - . - . -" },
	{ ',',"- - . . - -" },
	{ ':',"- - - . . ." },
	{ '?',". . - - . ." },
	{ '\'',". - - - - ." },
	{ '-',"- . . . . -" },
	{ '/',"- . . - ." },
	{ '"',". - . . - ." },
	{ '@',". - - . - ." },
	{ '=',"- . . . -" },
	{ ' '," "}
});


std::string textToMorseText(const std::string& text)
{
	std::unordered_map<char, std::string>::const_iterator dictIter;
	
	std::string output = "";

	for (std::string::const_iterator iter = text.cbegin(); iter != text.cend(); ++iter)
	{
			dictIter = dictOfMorse.find(toupper(*iter));
		
		if (dictIter != dictOfMorse.end())
			output += dictIter->second + "   ";
	}

	return output;
}