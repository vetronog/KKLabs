
#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <stdexcept>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
using namespace std;


double ValidateAndConvert(string str)
{
	bool firstDelimeter = true;
	bool delimeterDot = true;
	for (int i = 0; i <= str.size() - 1; i++)
	{
		if ((str[i] > '9') || (str[i] < '0'))
		{
			if (str[i] == '.' || str[i] == ',')
			{
				if (!firstDelimeter)
					return -1;
				else
				{
					firstDelimeter = false;
					if (str[i] == ',')
					{
						delimeterDot = false;
					}
				}
			}
			else
				return -1;
		}
	}
	double number = 0;
	double intPart;
	double floatPart;
	if (!delimeterDot)
		number = stod(str);
	else
	{
		auto dotPos = str.find('.');
		string intPart = str.substr(0, dotPos);
		string floatPart = str.substr(dotPos + 1, str.size() - 1);
		number += stod(intPart);
		if (dotPos != string::npos && dotPos != str.size() - 1)
			number += stod(floatPart) / (pow(10, floatPart.size()));
	}
	return number;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 4) {
		cout << "Invalid argument count/Неверное количество аргументов программы необходимо ввести: triangle.exe a b c" << endl;
		return 1;
	}
	string first = argv[1];
	string second = argv[2];
	string thirst = argv[3];
	try
	{
		double a = ValidateAndConvert(first);
		double b = ValidateAndConvert(second);
		double c = ValidateAndConvert(thirst);


		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "incorrect/Неверный ввод числа, необходимо ввести натуральное число";
			return 1;
		}
		if (((a + b) < c) || ((a + c) < b) || ((b + c) < a)) {
			cout << " not triangle/Не треугольник\n";
			return 0;
		}
		else if (a == b && a == c) {
			cout << "r/s/Треугольник равносторонний\n";
			return 0;
		}
		else if ((a == b) || (b == c) || (a == c)) {
			cout << "r/b/Треугольник равнобедренный\n";
			return 0;
		}
		else {
			cout << "s/Треугольник простой\n";
			return 0;
		}
	}
	catch (std::exception &err)
	{
		{
			cout << err.what() << endl;
			return 1;
		}
	}
	return 0;
}

