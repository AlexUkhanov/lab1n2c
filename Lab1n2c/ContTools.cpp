#include "ContTools.h"

//Заполнение файла случайными числами от M до -M в цикле
ofstream fill_file_random(string FileName, int M, int count)
{
	ofstream file(FileName);
	srand(time(0));
	for (int i = 1; i <= count; i++)
	{
		file << (rand() % (2 * M + 1) - M) << " ";
	}
	return file;
}

//Заполнение файла случайными числами от M до -M с помощью std::generate
ofstream fill_file_random_generate(string FileName, int M, int count)
{
	ofstream file(FileName, ios::out);
	srand(time(0));
	generate_n(ostream_iterator<double>(file, " "), count, [M]() {int i = rand() % (2 * M + 1) - M; return i; });
	return file;
}

//Проверяет индекс k на корректность
void ok_k(list<double>::iterator begin, list<double>::iterator end, int k)
{
	if ((distance(begin, end) < k) || (k < 0))
	{
		throw "Error. Invalid index is given.";
	}
}

//Загрузка чисел из файла в контейнер
list<double> load_from_file(ifstream &file)
{
	list<double> list_tmp;
	if (!file)
	{
		cout << "File is not found." << endl;
		return list_tmp;
	}

	double value;
	if (!(file>> value))
	{
		cout << "Incorrect format of data (or file is empty)" << endl;
		return list_tmp;
	}

	while (!file.eof())
	{
		list_tmp.emplace_back(value);
		if (!(file >> value) && !file.eof())
		{
			cout << "Incorrect format of data." << endl;
			list_tmp.clear();
			return list_tmp;
		}
	}
	list_tmp.emplace_back(value);
	return list_tmp;
}

//Возвращает первое отрицательное число
double get_first_neg_num(list<double>::iterator start, list<double>::iterator end)
{
	for (auto i = start; i != end; i++)
		if (*i < 0)
		{
			return *i;
		}
	//если отрицательных чисел нет
	throw "Negative numbers are absent.";
}

//Возвращает к-атое число
double get_k_num(list<double>::iterator start, list<double>::iterator end, int k)
{
	auto i = start;
	advance(i, k-1);
	return *i;
}

//Проверка чисел на корректность
double CheckNumber(double firstminus, double knum)
{
	if (0 == firstminus) 
	{
		throw "The list does not contain negative elements.";
	}
	double num = (double)((knum + firstminus) / 2);
	if (0 == num) 
	{
		throw "The resulting value is 0.";
	}
	return num;
}

//Возвращает полусумму первого отрицательного и к-атого числа
double get_halfsum(list<double>::iterator start, list<double>::iterator end, int k)
{
	double first_neg = get_first_neg_num(start, end);
	double k_num = get_k_num(start, end, k);

	return CheckNumber(first_neg,k_num);
}

//Преобразование контейнера (принимающую на вход итераторы начала и конца обрабатываемой части контейнер)
list<double> modify(list<double>::iterator start, list<double>::iterator end, int k)
{
	ok_k(start, end, k);
	//Полусумма первого отрицательного и к-атого числа
	double halfsum = get_halfsum(start, end, k);
	list<double> modified_list;
	copy(start, end, back_inserter(modified_list));
	for (auto i = modified_list.begin(); i != modified_list.end(); i++)
	{
		*i = *i / halfsum;
	}
	return modified_list;
}

//Преобразование контейнера (в качестве параметра исходный контейнер, возвращает измененный)
list<double> modify(list<double> &list_original, int k)
{
	return modify(list_original.begin(), list_original.end(), k);
}

//преобразование контейнера алгоритмом transform
list<double> transform_cnt(list<double> list_original, int k)
{
	ok_k(list_original.begin(), list_original.end(), k);
	list<double> listNew = list<double>(list_original.size());
	double halfsum = get_halfsum(list_original.begin(), list_original.end(), k);
	transform(list_original.begin(), list_original.end(), listNew.begin(), [halfsum](double value) { return value/halfsum; });
	return listNew;
}

//Преобразование контейнера (с помощью алгоритма std::for_each)
list<double> modify_foreach(list<double> list_original, int k)
{
	ok_k(list_original.begin(), list_original.end(), k);
	list<double> listNew;
	copy(list_original.begin(), list_original.end(), back_inserter(listNew));
	double halfsum = get_halfsum(list_original.begin(), list_original.end(), k);
	for_each(listNew.begin(), listNew.end(), [halfsum](double &value) {value /= halfsum; });
	return listNew;
}

//Сумма всех чисел в контейнере
double sum(list<double>::iterator start, list<double>::iterator end)
{
	double sum = 0;
	if (start == end)
	{
		throw "It is not possible to calculate the amount. The container is empty.";
	}
	for_each(start, end, [&sum](double value) {sum += value;});
	return sum;
}

//Среднее арифметическое всех чисел контейнера
double average(list<double>::iterator start, list<double>::iterator end)
{
	if (start == end)
	{
		throw "It is not possible to calculate the arithmetic mean. The container is empty.";
	}
	return sum(start, end) / distance(start,end);
}

//печать в файл
void  print(fstream &st, list<double> &lst) {
	for_each(lst.begin(), lst.end(), [&st](double i) {st << i << " "; });
}

//перегруженный метод, печать в консоль
void  print(ostream &st, list<double> lst) {
	for_each(lst.begin(), lst.end(), [&st](double i) {st << i << " "; });
	st << endl;
}




