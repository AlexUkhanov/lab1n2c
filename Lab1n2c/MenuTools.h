#pragma once
#include <iostream>
#include <string>

using namespace std;

//Функция ввода диапазона
int get_range();
//Функция ввода количества чисел
int get_count();
//проверка корректности символа
bool correct_ch(char ch);
//проверка корректности имени файла
bool correct_filename(std::string filename);
//Функция ввода имени файла
bool get_filename(string &filename);
//Функция вывода главного меню
int menu(bool ExtendedMenu = false);