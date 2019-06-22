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

    template <typename Func>
    int RemoveIf(Func predicate){
        int count = 0;
        for(auto it = storage.begin();it!= storage.end();++it)
        {
            for(auto &a : it->second.second)
            {
                if(predicate(it->first,a))
                {
                    storage.erase(it);
                    ++count;
                }
            }
        }
        return count;
    }

    template <typename Func>
    vector<string> FindIf(Func &predicate){
        vector<string> result;
        for(auto it = storage.begin();it!= storage.end();++it)
        {
            for(auto &event : it->second.second)
            {
                if(predicate(it->first, event))
                {
                    result.push_back(it->first.GetDate() + ' ' + event);
                }
            }
        }
        return result;
    }

    void Print(ostream &os) const;

    string Last(const Date& date);


private:
    map<Date, pair<vector<string>,set<string>>> storage;

};

