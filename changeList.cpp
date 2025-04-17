#include "changeList.h"
#include "definitions.h"
#include "print.h"
#include <iostream>
#include <cstring>

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

void delByNumber(Person *&list, int &n, int i)
{
    //выделить память под массив на 1 меньший
    Person *newList = new Person[n - 1];
    //переписать в новый массив все элементы до i-го
    for (int j = 0; j < i; ++j) {
        newList[j] = list[j];
    }
    //переписать все элементы после i-го
    for (int j = i + 1; j < n; ++j) {
        newList[j - 1] = list[j];
    }
    //удалить старый массив
    delete[] list;
    //переименовать новый массив
    list = newList;
    n--;
}

void delContact(Person *&list, int &n)
{
    cout << "Удаление контакта\n";
    //у пользователя запрашивается фамилия
    char nameGiven[MAX];
    cout << "Введите фамилию: ";
    cin >> nameGiven;
    //просмотр массива и удаление контактов с этой фамилией
    char ch;
    int kol;
    for (int i = 0; i < n; ++i) {
        if (strcmp(list[i].secondName, nameGiven) == 0) {
            print (&list[i]);
            cout << "Удалять? Y/N: ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                delByNumber(list, n, i);
                i--;
                kol++;
            }
        }
    }
    if (kol == 0) {
        cout << "Контакты не найдены!\n";
    }
    else {
        cout << "Контакты удалены!\n";
    }
}
