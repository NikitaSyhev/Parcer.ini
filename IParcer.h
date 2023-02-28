#pragma once
#include <iostream>
#include <fstream>
class IParcer
{
public:

	virtual void ReadFile(const std::string& filename) = 0;
	virtual const void saveFile(const std::string &nameFile) = 0;
	virtual ~IParcer() {}
};

