#include <iostream>
#include "definitions.h"
#include "find.h"
#include <iomanip>
#include <cstring>

using std::cin; using std::cout; 
using std::endl;

void findContact(Person *list, int n) 
{
    char nameGiven[MAX];
    cout << "Введите фамилию: ";
    cin >> nameGiven;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(list[i].secondName, nameGiven) == 0) {
            if (k == 0) {
                cout << "Результаты поиска:\n";
            }
            cout<<list[i].secondName<<" "<<list[i].name<<" тел.: "<<list[i].telefon;
            cout << "\n\t" << std::setw(2) << std::setfill('0') << list[i].birthday.day
                << "." << std::setw(2) << std::setfill('0')<< list[i].birthday.month 
                << "." << list[i].birthday.year << "\n";
            k++;
            }
    }
    if (k == 0) {
        cout << "Контакты не найдены\n";
    }
}

void findBirthdays(Person *list, int n) 
{
	cout << "Поиск именинников\n";
}
