#include "changeList.h"
#include "definitions.h"
#include <iostream>

using std::cin; using std::cout; 
using std::endl;

void addContact(Person *&list, int &n)
{
    //выделение новой памяти под массив размера n+1
    Person *newList = new Person[n + 1];
    //копируем все данные из исходного массива в новый
    for (int i = 0; i < n; ++i) {
        newList[i] = list[i];
    }
    //запрашиваем у пользователя данные нового контакта, добавляем в конец массива
    cout << "Введите фамилию: ";
    cin >> newList[n].secondName;
    cout << "Введите имя: ";
    cin >> newList[n].name;
    cout << "Введите телефон: ";
    cin >> newList[n].telefon;
    cout << "Введите день, месяц и год рождения через пробел: ";
    cin >> newList[n].birthday.day;
    cin >> newList[n].birthday.month;
    cin >> newList[n].birthday.year;
    //исходный массив из памяти удаляем
    delete[] list;
    //новый массив переименуем в list
    list = newList;
    n++;
}

void delContact(Person *list, int n)
{
    cout << "Удаление контакта\n";
}
