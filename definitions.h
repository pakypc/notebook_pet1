#pragma once

#define MAX  128

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
