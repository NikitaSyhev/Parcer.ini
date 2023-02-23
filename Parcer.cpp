#include "Parcer.h"
#include <fstream>
#include <map>
#include <string>





std::string Parcer::findKeyX(const std::string& keyX)
{
	for (const auto& section : _sections) {
		for (const auto& element : section.second) {
			if (element.first == keyX) {
				return section.first;
			}
		}
		
	}
}

bool Parcer::ifTitleXExist(const std::string& x)
{

	return false;
}

bool Parcer::ifKeyXExist(const std::string& x)
{
	return false;
}

bool Parcer::ifValueXExist(const std::string& x)
{
	return false;
}

void Parcer::ReadFile(const std::string& filename)
{
	
	std::ifstream in; // вот здесь нужно реализовать поиск так, чтобы читать секции, и пушить в мапу мап, и потом 7 функций сделать
	std::string sectionName, key, value;
	std::string currentLine;
	in.open(filename);
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, currentLine);

			if (currentLine[0] == '[') {
				sectionName = currentLine.substr(1, currentLine.find(']') - 1);

			}
			if (currentLine[0] != ';' && currentLine[0] != '[' && currentLine[0] != '#') {
				key = currentLine.substr(0, currentLine.find('='));
				value = currentLine.substr(currentLine.find('=') + 1, currentLine.find(';'));
				}


			_sections[sectionName][key] = value;

			for (const auto& section : _sections) {
				std::cout << " [ " << section.first << " ] " <<  std::endl;
				
			}
			}
		}
	
	in.close();
}





// считать файл
// посмотрреть по секциям в ini файле
// считать в мапу
// реализовать 7 функции и запушить в новый ini файл ( решение задачи )



//for (const auto& sections : sections) {
//	std::cout << "[" << sections.first << "]" << std::endl;
//	for (const auto& element : sections.second) {
//		std::cout << "key: " << element.first << "value" << element.second << std::endl;
//	}
//}
