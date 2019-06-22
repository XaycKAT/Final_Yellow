#include <database.h>

void Database::Add(const Date& date, const string& event) {
    storageSet[date].insert(event);
    storageVec[date].push_back(event);
}

void Database::Print(ostream &os) const {
    for (const auto& item : storageSet) {
        for (const string& event : item.second) {
            os << item.first << " " << event << endl;
        }
    }
}
string Database::Last(const Date& date){
    auto it = storageVec.lower_bound(date);
    if(it!=storageVec.begin())
    {
        it--;
        return it->second.back();
    }
    else
        return "No entries";
}
