#include<iostream>
using namespace std;
// Check leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get number of days in a month
int getDaysInMonth(int month, int year) {
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

// Zeller’s Congruence to get weekday (0 = Sunday, ..., 6 = Saturday)
int getWeekday(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100, J = year / 100;
    int h = (day + 13 * (month + 1) / 5 + K + K/4 + J/4 + 5 * J) % 7;
    return (h + 6) % 7;
}

int main(){
    cout<<"Hello world";
}