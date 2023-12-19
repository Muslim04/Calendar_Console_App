#ifndef UTILS_H
#define UTILS_H
#include <iostream>

using namespace std;

int dayNumber(int day, int month, int year);
string getMonthName(int monthNumber);
int numberOfDays(int monthNumber, int year);
void print_calendar(int& year);
#endif // UTILS_H