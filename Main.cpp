
#include <iostream>
#include <fstream>
#include "IParcer.h"
#include "Parcer.h"
#include <Windows.h>




int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	if (argc > 1) {
			std::string filename(argv[1]);
			std::cout << filename << std::endl;
			std::fstream fin(filename);
	}
	else {
		std::cout << "Only one argument was provided" << std::endl;
	}



	std::string path("filename.ini");
	Parcer P;
	P.ReadFile(path);
	std::cout << "В каком заголовке лежит ключ X?" << std::endl;
	std::cout << P.findKeyX("var1")<< std::endl;
	std::cout << "Существует ли заголовок?" << std::endl;
	std::cout << P.ifTitleXExist("Section5") << std::endl;
	std::cout << "Существует ли ключ Х в файле?" << std::endl;
	std::cout << P.ifKeyXExist("var1") << std::endl;
	std::cout << "Существует ли значение Х в файле?" << std::endl;
	std::cout << P.ifValueXExist("value_1") << std::endl;
	std::cout << "Какое значение у ключа X в секции Y?" << std::endl;
	P.valueXinY("var5", "Section3");
	std::cout << " Обратиться к секции X и присвоить ключу Y значение Z (если ключа илисекции не существует - создать" << std::endl;
	P.convertValue("Section1", "var1", "value_33");
	P.saveFile();
	








	return 0;
}