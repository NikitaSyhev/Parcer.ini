
#include <iostream>
#include <fstream>
#include "IParcer.h"
#include "Parcer.h"
#include <Windows.h>




int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	/*if (argc > 1) {
		for (size_t i = 0; i < argc; i++) {

		}

		std::string filename(argv[1]);
		std::cout << filename << std::endl;
		std::ifstream fin(filename);
	}
	else {
		std::cout << "Only ine argument was provided" << std::endl;
	}


*/
	std::string filename;
	std::cout << "Enter a filename: " << std::endl; // enter a filename.ini
	std::cin >> filename;
	Parcer P;
	
	P.ReadFile(filename);

	std::cout << "В каком заголовке лежит ключ X?" << std::endl;
	std::cout << P.findKeyX("var1")<< std::endl;
	std::cout << "Существует ли заголовок?" << std::endl;
	std::cout << P.ifTitleXExist("Section5") << std::endl;
	std::cout << "Существует ли ключ Х в файле?" << std::endl;
	std::cout << P.ifKeyXExist("var1") << std::endl;
	std::cout << "Существует ли значение Х в файле?" << std::endl;
	std::cout << P.ifValueXExist("value_1") << std::endl;
	std::cout << "Какое значение у ключа X в секции Y?" << std::endl;
	P.valueXinY("var7", "Section3");
	std::cout << " Обратиться к секции X и присвоить ключу Y значение Z (если ключа илисекции не существует - создать" << std::endl;
	P.convertValue("Section1", "var1", "value_33");








	return 0;
}