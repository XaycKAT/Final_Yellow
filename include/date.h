#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Date {
public:
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    string GetDate() const;

private:
    int year;
    int month;
    int day;
};
Date ParseDate(istream &);

ostream& operator<<(ostream& stream, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
