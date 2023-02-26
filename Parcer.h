#pragma once
#include "IParcer.h"
#include <map>
class Parcer : public IParcer
{
public:

	void ReadFile(const std::string& filename) override;
	std::string findKeyX(const std::string& keyX);
	bool ifTitleXExist(const std::string& title);
	bool ifKeyXExist(const std::string& keyX);
	bool ifValueXExist(const std::string& value);
	void valueXinY(const std::string& key, const std::string& sectionY);
	void convertValue(const std::string& sectionX, const std::string& key, const std::string &value);
	const void saveFile(const std::string& nameFile) override;
	
private:
	std::map < std::string, std::map<std::string, std::string>> _sections;
};

