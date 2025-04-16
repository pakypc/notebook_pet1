#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iomanip>

#define MAX  128

using std::cin; using std::cout; 
using std::endl; using std::string;

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char secondName[MAX];
    char name[MAX];
    char telefon[MAX];
    Date birthday;
};

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

void addContact(Person *list, int n)
{
    cout << "Добавление контакта\n";
}

void delContact(Person *list, int n)
{
    cout << "Удаление контакта\n";
}

void  printSort(Person *list, int n) 
{
	cout << "Сортировка по фамилии\n";
}

void findContact(Person *list, int n) 
{
	cout << "Поиск по фамилии\n";
}

void findBirthdays(Person *list, int n) 
{
	cout << "Поиск именинников\n";
}

void finish(Person *list, int n) {
	cout << "Завершение работы\n";
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
