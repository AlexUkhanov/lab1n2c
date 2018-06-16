#pragma once
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

//Пункт 1

//Заполнение файла случайными числами от M до -M в цикле
ofstream fill_file_random(string FileName, int M, int count);
//Заполнение файла случайными числами от M до -M с помощью std::generate
ofstream fill_file_random_generate(string FileName, int M, int count);

//Пункт 2
//Загрузка чисел из файла в контейнер
list<double> load_from_file(ifstream &file);

//Пункт 3
//Преобразование контейнера (в качестве параметра исходный контейнер, возвращает измененный)
list<double> modify(list<double> &list_original, int k);

//Пункт 4
//Преобразование контейнера (принимающую на вход итераторы начала и конца обрабатываемой части контейнер)
list<double> modify(list<double>::iterator start, list<double>::iterator end, int k);

//Пункт 5
//Преобразование контейнера (с помощью алгоритма std::transform)
list<double> transform_cnt(list<double> list_original, int k);

//Пункт 6
//Преобразование контейнера (с помощью алгоритма std::for_each)
list<double> modify_foreach(list<double> list_original, int k);

//Пункт 7
//Вычисление суммы всех чисел, содержащихся в контейнере
double sum(list<double>::iterator start, list<double>::iterator end);
//Вычисление среднего арифметического чисел, содержащихся в контейнере	
double average(list<double>::iterator start, list<double>::iterator end);

//Пункт 8
//Печать в файл
void  print(fstream &st, list<double> &lst);
//Перегруженный метод, печать в консоль
void  print(ostream &st, list<double> lst);