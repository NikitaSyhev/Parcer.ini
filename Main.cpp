
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
		std::cout << "������� ��� ��������: \n";
		std::cout << "1. � ����� ��������� ����� ���� X?\n";
		std::cout << "2. ���������� �� ��������� X (������)? ( 0 - ���, 1 - ��)\n";
		std::cout << "3. ���������� �� ���� X � �����? ( 0 - ���, 1 - ��)\n";
		std::cout << "4. ���������� �� �������� X � �����? ( 0 - ���, 1 - ��)\n";
		std::cout << "5. ����� �������� � ����� X � ������ Y? (��������� ���������� ��������, ����� ����� ������ ���)\n";
		std::cout << "6. ���������� � ������ X � ��������� ����� Y �������� Z (���� ����� ��� ������ �� ���������� - �������)\n";
		std::cout << "7. ������� ����������������� (��� ����������� ��� ����) .ini ���� � �����	���� � ���������������� ���������.\n\n\n";


		std::cout << "�������� ����������� ������: \n";
		
		std::cin >> x;
		std::string path("filename.ini");
		Parcer P;
		P.ReadFile(path);
		switch (x)
		{
		case 1:std::cout << "������� ���� ��� ������: \n";std::cin >> key;std::cout << P.findKeyX(key) << std::endl;break;
		case 2:std::cout << "������� ��������� ��� ������: \n"; std::cin >> title;std::cout << P.ifTitleXExist(title) << std::endl;break;
		case 3:std::cout << "������� ���� ��� �������� ������������� \n";std::cin >> key;std::cout << P.ifKeyXExist(key) << std::endl;break;
		case 4:std::cout << "������� �������� ��� ��������: \n"; std::cin >> value;	std::cout << P.ifValueXExist(value) << std::endl;break;
		case 5:std::cout << "������� ��������� � ����: \n"; std::cin >> title; std::cin >> key; P.valueXinY(key, title);break;
		case 6:std::cout << "������� ���������, ���� � ����� ��������: \n"; std::cin >> title; std::cin >> key, std::cin >> value;P.convertValue(title, key, value);break;
		case 7:std::cout << "������� �������� ����� � ����: file.txt: \n"; std::cin >> nameFile;P.saveFile(nameFile);break;
			break;
		}
	} while (x < 8);
	


	
	





	return 0;
}