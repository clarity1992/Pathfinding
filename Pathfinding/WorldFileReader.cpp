#include "WorldFileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

std::vector<std::vector<std::string>> WorldFileReader::readFile(std::string fileName, char delimiter)
{
	std::vector<std::vector<std::string>> rawWorldData;
	ifstream file(fileName);
	string line;
	if (file.is_open())
	{
		unsigned currentLine = 0;
		while ( getline (file,line) )
		{
			std::vector<std::string> splitLine = split(line, delimiter);
			rawWorldData.push_back(splitLine);
			currentLine++;
		}
		file.close();
	}
	else
	{
		cout << "Unable to open file"; 
	}
	return rawWorldData;
}

std::vector<std::string> WorldFileReader::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::vector<std::string>& WorldFileReader::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}