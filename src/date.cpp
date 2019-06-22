#include <date.h>


Date ParseDate(istream& date_stream) {
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  if (!ok) {
    throw logic_error("Wrong date format.");
  }
  return Date(year, month, day);
}

string Date::GetDate() const{
    string res;
    res +=year;
    res +='-';
    res +=month;
    res +='-';
    res +=day;
    return res;
}
