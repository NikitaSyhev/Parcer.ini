#include "Parcer.h"
#include <fstream>
#include <map>

const std::string Parcer::findKeyX(const std::string& x, std::string &filename)
{
	std::ifstream in;



	in.open(filename, std::ios::in);
	if (!in) {
		std::cerr << "File opening error" << std::endl;
	}


	in.close();
	return x;
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
	in.open(filename, std::ios::in);
	std::string sectionName, key, value;
	std::map<std::string, std::map<std::string, std::string>> sections;


	if (in.is_open()) {
		while (!in.eof()) {
			std::string str;
			in >> str;
			std::cout << str << std::endl;
		}
	}
	else
	{
		std::cout << "File opening error" << std::endl;
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
