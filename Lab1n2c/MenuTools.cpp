#include "MenuTools.h"

//Функция ввода диапазона
int get_range()
{
	int val;
	cout << "Enter M (the range will be the values (-M;M) ):" << endl;
	cin >> val;
	return val;
}

//Функция ввода количества чисел
int get_count()
{
	int val;
	cout << "Enter count of numbers:" << endl;
	cin >> val;
	while (val <= 0)
	{
		cout << "Invalid value. Please re-enter." << endl;
		cin >> val;
	}
	return val;
}

//проверка корректности символа
bool correct_ch(char ch)
{
	return ch != '?' && ch != '<' && ch != '>' && ch != '*' &&
		ch != '|' && ch != '/' && ch != ':';
}

//проверка корректности имени файла
bool correct_filename(string filename)
{
	for (int i = 0; i < filename.length(); ++i)
	{
		if (!correct_ch(filename[i]))
			return false;
	}
	return true;
}


//Функция ввода имени файла
bool get_filename(string &filename)
{
	cout << "Enter the filename:" << endl;
	cin >> filename;
	if (!correct_filename(filename))
	{
		cout << "Incorrect file name entered." << endl;
		return false;
	}
	return true;
}

//Функция вывода главного меню
int menu(bool ExtendedMenu)
{
	cout << "1 - Create file with random numbers using a loop" << endl;
	cout << "2 - Create file with random numbers using the generate" << endl;
	cout << "3 - Create list from file" << endl;
	if (ExtendedMenu)
	{
		cout << "4 - Change list" << endl;
		cout << "5 - Change list (iterators)" << endl;
		cout << "6 - Change list using transform" << endl;
		cout << "7 - Change list using for_each" << endl;
		cout << "8 - Get the sum" << endl;
		cout << "9 - Get the arithmetic mean." << endl;
		cout << "10 - Display" << endl;
		cout << "11 - Output to file" << endl;
		cout << "0 - Exit" << endl;
	}
	int answer;
	cout << "Enter the item number:"<<endl;
	cin >> answer;
	while ((answer < 0) || (answer > 11))
	{
		cout << "Incorrect number entered. Re-enter:" << endl;
		cin >> answer;
	}
	return answer;
}