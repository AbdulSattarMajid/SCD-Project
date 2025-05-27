#include <iostream>
#include <iomanip>
using namespace std;

// Month and weekday names
string months[12] = { "January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December" };
string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

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

// Print a calendar like `cal`
void printMonthCalendar(int month, int year) {
    cout << "     " << months[month - 1] << " " << year << endl;
    cout << "Su Mo Tu We Th Fr Sa" << endl;

    int startDay = getWeekday(1, month, year);
    int numDays = getDaysInMonth(month, year);

    for (int i = 0; i < startDay; ++i)
        cout << "   ";

    for (int day = 1; day <= numDays; ++day) {
        cout << setw(2) << day << " ";
        if ((startDay + day) % 7 == 0)
            cout << endl;
    }
    cout << "\n" << endl;
}

// Print all 400 years' calendars
void printFull400YearCalendar() {
    for (int year = 1600; year < 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            printMonthCalendar(month, year);
        }
    }
}

// Validate if user date is valid
bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12)
        return false;
    int daysInMonth = getDaysInMonth(month, year);
    return day >= 1 && day <= daysInMonth;
}

// Show day of week for user-entered date
void querySpecificDate() {
    int day, month, year;
    cout << "\n🔍 Enter a date to find the weekday." << endl;
    cout << "Day (1-31): "; cin >> day;
    cout << "Month (1-12): "; cin >> month;
    cout << "Year: "; cin >> year;

    if (!isValidDate(day, month, year)) {
        cout << "❌ Invalid date entered.\n";
        return;
    }

    int weekday = getWeekday(day, month, year);
    cout << "📅 " << day << " " << months[month - 1] << " " << year
         << " falls on a " << days[weekday] << ".\n";
}

int main(){
    cout<<"Hello world";
}