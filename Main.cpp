
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
	std::cout << P.findKeyX("var6");









	return 0;
}