#include <database.h>

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
string Database::Last(const Date& date){
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
