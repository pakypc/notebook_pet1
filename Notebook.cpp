#
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#include "definitions.h"
#include "print.h"
#include "changeList.h"
#include "find.h"

using std::cin; using std::cout; 
using std::endl; using std::string;

void razbor(char *str, Person &kontakt)
{
    char *part;
    part = strtok(str, ";");
    strncpy(kontakt.secondName, part, sizeof(kontakt.secondName) - 1);
    part = strtok(NULL, ";");
    strncpy(kontakt.name, part, sizeof(kontakt.name) - 1);
    part = strtok(NULL, ";");
    strncpy(kontakt.telefon, part, sizeof(kontakt.telefon) - 1);
    part = strtok(NULL, "/");
    kontakt.birthday.day = atoi(part);
    part = strtok(NULL, "/");
    kontakt.birthday.month = atoi(part);
    part = strtok(NULL, "\n");
    kontakt.birthday.year = atoi(part);
}

int menu ()
{
    cout << "\n1 - добавить запись\n";
	cout << "2 - удалить запись\n";
	cout << "3 - вывести без сортировки\n";
	cout << "4 - вывести список, отсортированный по фамилии\n";
	cout << "5 - поиск по фамилии\n";
	cout << "6 - список именниников в определенном месяце\n";
	cout << "7 - выход из программы\n";
    int k;
    cout << "Ваш выбор: ";
    cin >> k;
    while (k < 1 || k > 7) {
        cout << "Неверный выбор! Повторите ввод: ";
        cin >> k;
    }
    cout << endl;
    return k;
}

void finish(Person *list, int n) {
	cout << "Завершение работы\n";
    cout << "Сохранить в файл текущие контакты? (Y/N) ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y') {
        FILE* output = fopen("data.txt", "w");
        if (output == NULL) {
            cout << "Ошибка открытия файла для чтения\n";
            return;
        }
        fprintf(output, "%d\n", n);
        for (int i = 0; i < n; ++i) {
            fprintf(output, "%s;%s;%s;%d/%d/%d\n", list[i].secondName, list[i].name,
                    list[i].telefon, list[i].birthday.day, list[i].birthday.month,
                    list[i].birthday.year);
        }
         if (fclose(output) != 0) {
             cout << "Ошибка Закрытия файла для записи\n";
        }
    }
}

int main ()
{
    FILE* input = fopen("data.txt", "r");
    if (input == NULL) {
        cout << "Ошибка открытия файла для чтения\n";
        return 0;
    }
    int n;
    fscanf(input, "%d\n", &n);
     // cout << n << endl;
     Person *list = new Person[n];

     char str[MAX];
     for (int i = 0; i < n; ++i) {
         fgets(str, MAX, input);
         // cout << str;
        razbor(str, list[i]);
     }

     printList(list, n);
     cout << endl;

     if (fclose(input) != 0) {
         cout << "Ошибка Закрытия файла для чтения\n";
    }

     int vyb;
     while (true) {
         vyb = menu ();
        switch (vyb) {
		    case 1: addContact(list, n); 
                    break;
		    case 2: delContact(list, n); 
                    break;
	    	case 3: printList(list, n); 
                    break;
		    case 4: printSort(list, n); 
                    break;
		    case 5: findContact(list, n); 
                    break;
		    case 6: findBirthdays(list, n); 
                    break;
		    case 7: finish(list, n);
                    delete[] list;
                    return 0;
		}
     }
}
