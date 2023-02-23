
#include <iostream>
#include <fstream>
#include "IParcer.h"
#include "Parcer.h"
#include <Windows.h>




int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string key, title, value, nameFile;
	int x;
	if (argc > 1) {
			std::string filename(argv[1]);
			std::cout << filename << std::endl;
			std::fstream fin(filename);
	}
	else {
		std::cout << "Only one argument was provided" << std::endl;
	}

	do {
		std::cout << "Задания для парсинга: \n";
		std::cout << "1. В каком заголовке лежит ключ X?\n";
		std::cout << "2. Существует ли заголовок X (секция)? ( 0 - нет, 1 - да)\n";
		std::cout << "3. Существует ли ключ X в файле? ( 0 - нет, 1 - да)\n";
		std::cout << "4. Существует ли значение X в файле? ( 0 - нет, 1 - да)\n";
		std::cout << "5. Какое значение у ключа X в секции Y? (нормально обработать варианты, когда ключа вообще нет)\n";
		std::cout << "6. Обратиться к секции X и присвоить ключу Y значение Z (если ключа или секции не существует - создать)\n";
		std::cout << "7. Вывести отредактированный (или оставленный как есть) .ini файл в новый	файл с пользовательским названием.\n\n\n";


		std::cout << "Выберете необходимый вопрос: \n";
		
		std::cin >> x;
		std::string path("filename.ini");
		Parcer P;
		P.ReadFile(path);
		switch (x)
		{
		case 1:std::cout << "Введите ключ для поиска: \n";std::cin >> key;std::cout << P.findKeyX(key) << std::endl;break;
		case 2:std::cout << "Введите заголовок для поиска: \n"; std::cin >> title;std::cout << P.ifTitleXExist(title) << std::endl;break;
		case 3:std::cout << "Введите ключ для проверки существования \n";std::cin >> key;std::cout << P.ifKeyXExist(key) << std::endl;break;
		case 4:std::cout << "Введите значение для проверки: \n"; std::cin >> value;	std::cout << P.ifValueXExist(value) << std::endl;break;
		case 5:std::cout << "Введите заголовок и ключ: \n"; std::cin >> title; std::cin >> key; P.valueXinY(key, title);break;
		case 6:std::cout << "Введите заголовок, ключ и новое значение: \n"; std::cin >> title; std::cin >> key, std::cin >> value;P.convertValue(title, key, value);break;
		case 7:std::cout << "Введите название файла в виде: file.txt: \n"; std::cin >> nameFile;P.saveFile(nameFile);break;
			break;
		}
	} while (x < 8);
	


	
	





	return 0;
}