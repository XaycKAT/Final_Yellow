#include "database.h"

int Database::RemoveIf(std::function<bool(Date, string)> predicate){
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
vector<string> Database::FindIf(std::function<bool(Date, string)> predicate) const{
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
void Database::Add(const Date& date, const string& event) {
    storage[date].first.push_back(event);
    storage[date].second.insert(event);
}

void Database::Print(ostream &os) const {
    for (const auto& item : storage) {
        for (const string& event : item.second.second) {
            os << item.first << " " << event << endl;
        }
    }
}
string Database::Last(const Date& date) const {
    auto it = storage.find(date);
    if(it != storage.end())
    {
        return it->first.GetDate() +' '+ it->second.first.back();
    }
    it = storage.lower_bound(date);
    if(it!=storage.begin())
    {
        --it;
        return it->first.GetDate() +' '+ it->second.first.back();
    }
    else
        return "No entries";
}
