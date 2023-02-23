#pragma once
#include "IParcer.h"
#include <map>
class Parcer : public IParcer
{
public:

	void ReadFile(const std::string& filename) override;
	std::string findKeyX(const std::string& keyX) override;
	bool ifTitleXExist(const std::string& title) override;
	bool ifKeyXExist(const std::string& keyX) override;
	bool ifValueXExist(const std::string& value) override;
	void valueXinY(const std::string& key, const std::string& sectionY) override;
	void convertValue(const std::string& sectionX, const std::string& key, const std::string &value) override;
	const void saveFile() override;
	
private:
	std::map < std::string, std::map<std::string, std::string>> _sections;
};

