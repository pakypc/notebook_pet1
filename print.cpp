#include "print.h"
#include <iostream>
#include <iomanip>
#include "definitions.h"
#include <cstring>

using std::cout; 
using std::endl;

void printList(Person *list, int n)
{
    cout << "Содержание записной книжки: \n";
    for (int i = 0; i < n; ++i) {
        cout<<list[i].secondName<<" "<<list[i].name<<" тел.: "<<list[i].telefon;
        cout << "\n\t" << std::setw(2) << std::setfill('0') << list[i].birthday.day
            << "." << std::setw(2) << std::setfill('0')<< list[i].birthday.month 
            << "." << list[i].birthday.year << "\n";
    }
    cout << endl;
}

void  printSort(Person *list, int n) 
{
	cout << "Сортировка по фамилии\n";
    //создание и инициализация массива указателей
    Person **ptr = new Person*[n];
    for (int i = 0; i < n; ++i) {
        ptr[i] = &list[i];
    }
    //сортировка массива указателей
    for (int k = n - 1; k > 0; --k) {
        for (int i = 0; i < k; ++i) {
            if (strcmp(ptr[i]->secondName, ptr[i + 1]->secondName) > 0) {
                Person *tmp = ptr[i];
                ptr[i] = ptr[i + 1];
                ptr[i + 1] = tmp;
            }
        }
    }
    //вывод на консоль
    for (int i = 0; i < n; ++i) {
        cout<<ptr[i]->secondName<<" "<<ptr[i]->name<<" тел.: "<<ptr[i]->telefon;
        cout << "\n\t" << std::setw(2) << std::setfill('0') << ptr[i]->birthday.day
            << "." << std::setw(2) << std::setfill('0')<< ptr[i]->birthday.month 
            << "." << ptr[i]->birthday.year << "\n";
    }
    cout << endl;

    //удаление массива указателей
    delete[] ptr;
}
