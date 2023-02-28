#include "Parcer.h"
#include <fstream>
#include <map>
#include <string>





const std::string &Parcer::findKeyX(const std::string& keyX)
{
	for (const auto& section : _sections) {
		for (const auto& element : section.second) {
			if (element.first == keyX) {
				return section.first;
			}
			else return "";
		}
		
	}
}

bool Parcer::ifTitleXExist(const std::string& title)
{
	for (const auto& section : _sections) {
		if (section.first == title) {
			return true;
		}
	}
}

bool Parcer::ifKeyXExist(const std::string& keyX)
{
	for (const auto& section : _sections) {
		for (const auto& element : section.second) {
			if (element.first == keyX)
				return true;
		}
	}
}

bool Parcer::ifValueXExist(const std::string& value)
{
	for (const auto& section : _sections) {
		for (const auto& element : section.second) {
			if (element.second == value)
				return true;
		}
	}
}

void Parcer::valueXinY(const std::string& key, const std::string &sectionY)
{
	int num = 0;
	for (const auto& section : _sections) {
		for (const auto& element : section.second) {
			if (section.first == sectionY && element.first == key) {
				std::cout << "Value = " << element.second << std::endl;
				num++;			
			}
		}
	}
	if (num < 1) {
		std::cout << "There is not keys" << std::endl;
	}
}

void Parcer::convertValue(const std::string& sectionX, const std::string& key, const std::string& value)
{
	for (const auto& section : _sections) {
		for (const auto& element : section.second) {
			if (section.first == sectionX && element.first == key) {
				_sections[sectionX][key] = value;
				std::cout << "New value = " << value;

			}
		}
	}
}

const void Parcer::saveFile(const std::string& nameFile)
{
	std::ofstream out;
	out.open(nameFile);
	if (out.is_open()) {
		
		for (const auto& section : _sections) {
			out << "[" << section.first << "]" << std::endl;
			for (const auto& element : section.second) {
				if (element.first != "") {
					out << element.first << " = " << element.second << std::endl;
				} 
			}
		}
	}
}


void Parcer::ReadFile(const std::string& filename)
{

	std::ifstream in;
	std::string sectionName, key, value;
	std::string currentLine;
	in.open(filename);
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, currentLine);

			if (currentLine[0] == '[') {
				sectionName = currentLine.substr(1, currentLine.find(']') - 1);
				key = "";
				value = "";
				_sections[sectionName][key] = value;
			}

			else if (currentLine[0] != ';' && currentLine[0] != '#') {
				
				if (currentLine.rfind(";") > 0) {
					currentLine = currentLine.substr(0, currentLine.find(";"));
					key = currentLine.substr(0, currentLine.find('='));
					value = currentLine.substr(currentLine.find('=') + 1, currentLine.find(";"));
					_sections[sectionName][key] = value;
				}
				else {
					key = currentLine.substr(0, currentLine.find('='));
					value = currentLine.substr(currentLine.find('=') + 1, currentLine.find(' '));
					_sections[sectionName][key] = value;
				}
				
			}
		}
	}

	in.close();
}





