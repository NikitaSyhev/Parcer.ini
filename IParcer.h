#pragma once
#include <iostream>
#include <fstream>
class IParcer
{
public:

	virtual void ReadFile(const std::string& x) = 0;


	virtual std::string findKeyX(const std::string& keyX) = 0;
	virtual bool ifTitleXExist(const std::string& x) = 0;
	virtual bool ifKeyXExist(const std::string& x) = 0;
	virtual bool ifValueXExist(const std::string& x) = 0;
	

	virtual ~IParcer() {}
};

