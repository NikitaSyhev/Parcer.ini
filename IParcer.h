#pragma once
#include <iostream>
#include <fstream>
class IParcer
{
public:

	virtual void ReadFile(const std::string& x) = 0;
	virtual std::string findKeyX(const std::string& keyX) = 0;
	virtual bool ifTitleXExist(const std::string& title) = 0;
	virtual bool ifKeyXExist(const std::string& keyX) = 0;
	virtual bool ifValueXExist(const std::string& value) = 0;
	virtual void valueXinY(const std::string& key, const std::string& sectionY) = 0;
	virtual void convertValue(const std::string& sectionX, const std::string& key, const std::string &value) = 0;
	virtual ~IParcer() {}
};

