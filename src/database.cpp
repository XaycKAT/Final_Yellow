#include "database.h"

int Database::RemoveIf(std::function<bool(Date, string)> predicate){
    int count = 0;
    for(auto it = storage.begin();it!= storage.end();)
    {
        for(auto itvec = it->second.first.begin(); itvec!= it->second.first.end();)
        {
            if(predicate(it->first,*itvec))
            {
                it->second.second.erase(*itvec);
                itvec = it->second.first.erase(itvec);
                ++count;
            }
            else
                ++itvec;
        }
        if(it->second.second.size() == 0 && it->second.first.size() == 0)
            it = storage.erase(it);
        else
            ++it;

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
    auto it = storage.find(date);
    if(it!=storage.end())
    {
        auto its = it->second.second.find(event);
        if(its==it->second.second.end())
        {
            storage[date].first.push_back(event);
        }
    }
    else {
        storage[date].second.insert(event);
        storage[date].first.push_back(event);
    }
}

void Database::Print(ostream &os) const {
    for (const auto& item : storage) {
        for (const string& event : item.second.first) {
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
