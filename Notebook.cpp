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

    delete[] list;

    return 0;
}

