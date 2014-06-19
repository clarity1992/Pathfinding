#pragma once

#include <string>
#include <vector>
class WorldFileReader
{
public:
	static std::vector<std::vector<std::string>> readFile(std::string fileName, char delimiter);

private:
	static std::vector<std::string> split(const std::string &s, char delim);
	static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
};

