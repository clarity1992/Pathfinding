#include "WorldFileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<vector<string>> WorldFileReader::readFile(string fileName, char delimiter)
{
	vector<vector<string>> rawWorldData;
	ifstream file(fileName);
	string line;
	if (file.is_open())
	{
		unsigned currentLine = 0;
		while ( getline (file,line) )
		{
			vector<string> splitLine = split(line, delimiter);
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

vector<string> WorldFileReader::split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

vector<string>& WorldFileReader::split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}