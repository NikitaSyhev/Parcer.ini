#pragma once
#include "IParcer.h"
#include <map>
class Parcer : public IParcer
{
public:

	void ReadFile(const std::string& filename) override;

	std::string findKeyX(const std::string& keyX) override;
	bool ifTitleXExist(const std::string& x) override;
	bool ifKeyXExist(const std::string& x) override;
	bool ifValueXExist(const std::string& x) override;
	



private:
	std::map < std::string, std::map<std::string, std::string>> _sections;
};

