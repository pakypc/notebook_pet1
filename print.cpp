#include "print.h"
#include <iostream>
#include <iomanip>
#include "definitions.h"

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
}
