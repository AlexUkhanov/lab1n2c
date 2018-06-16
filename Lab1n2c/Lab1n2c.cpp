/*
Автор: Алексей Уханов
Написать программу, содержащую следующие функции:
	1) Функцию заполнения текстового файла N целыми случайными числами в диапазоне от -M до M. Имя файла, N и M поступают на вход функции, 
	файл возвращается функцией как результат (использовать потоки ввода-вывода). Реализовать два варианта генерации чисел — в цикле и 
	с использованием алгоритма std::generate.
	2) Функцию, получающую файл на вход, и возвращающую последовательный контейнер, заполненный числами из файла.
	3) Функцию modify, выполняющую преобразование полученного контейнера. На вход функции должен поступать контейнер, 
	в качестве результата функция должна возвращать модифицированный контейнер.
	4) Перегруженную функцию modify, принимающую на вход итераторы начала и конца обрабатываемой части контейнера.
	5) Функцию, реализующую требуемое преобразование с использованием алгоритма std::transform вместо функции modify.
	6) Функцию, реализующую требуемое преобразование с использованием алгоритма std::for_each вместо функции modify.
	7) Функции, вычисляющие сумму и среднее арифметическое чисел, содержащихся в контейнере.
	8) Функцию вывода результата в файл и на экран (опционально).
через контейнер C) Список (std::list) с вариантом преобразования 2:
Разделить каждое число на полусумму первого отрицательного и K-го числа (K задается аргументом функции modify).
*/

#include "ContTools.h"
#include "MenuTools.h"
#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<double> lst;
	int answer = 1;
	string filename;
	ofstream ofs;
	ifstream ifs;
	
	int M, N, k;

	bool extended_menu = false;
	while (answer)
	{
		answer = menu(extended_menu);
		switch (answer)
		{
		case 1:
			if (!get_filename(filename))
				break;
			M = get_range();
			N = get_count();
			ofs=fill_file_random(filename, M, N);
			ofs.close();
			break;
		case 2:
			if (!get_filename(filename))
				break;
			M = get_range();
			N = get_count();
			ofs=fill_file_random_generate(filename, M, N);
			ofs.close();
			break;
		case 3:
			if (!get_filename(filename))
				break;
			ifs.open(filename);
			lst = load_from_file(ifs);
			ifs.close();
			if (lst.begin()!=lst.end())
				extended_menu = true;
			break;
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Enter k:" << endl;
			cin >> k;
			try {
				if (4 == answer) {
					lst = modify(lst, k);
				}
				else if (5 == answer) {
					lst = modify(lst.begin(), lst.end(), k);
				}
				else if (6 == answer) {
					lst=transform_cnt(lst, k);
				}
				else {
					lst= modify_foreach(lst, k);
				}
				cout << "List is changed successfully" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		case 8:
			cout << sum(lst.begin(), lst.end())<<endl;
			break;
		case 9:
			try {
				cout << average(lst.begin(), lst.end()) << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		case 10:
			print(cout, lst);
			break;
		case 11:
			if (!(get_filename(filename)))
				break;
			ofs.open(filename);
			print(ofs, lst);
			break;
		}
	}
    return 0;
}

