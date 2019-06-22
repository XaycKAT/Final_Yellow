#pragma once
#include <iostream>
#include "date.h"
#include <iomanip>
#include <map>
#include <string>
#include <set>
#include <functional>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);

    int RemoveIf(std::function<bool(Date, string)> predicate);
    vector<string> FindIf(std::function<bool(Date, string)>) const;


    void Print(ostream &os) const;

    string Last(const Date& date) const;


private:
    map<Date, pair<vector<string>,set<string>>> storage;

};

