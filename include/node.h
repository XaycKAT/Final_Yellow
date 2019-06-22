#pragma once
#include <iostream>
#include <date.h>
#include <memory>
using namespace std;
enum LogicalOperation {
    Or,
    And
};
enum class Comparison
{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

struct Node{

    virtual bool Evaluate(const Date &d,const string &event) const = 0;

};

class EmptyNode: public Node {
public:
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode: public Node  {
public:
    DateComparisonNode(Comparison cmp, const Date& date): date_(date),cmp_(cmp) {}
    bool Evaluate(const Date& date, const string& event) const override;
private:
    Date date_;
    Comparison cmp_;
};
class EventComparisonNode: public Node {
public:
    EventComparisonNode(Comparison cmp, const string& value): cmp_(cmp), event_(value){}
    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison cmp_;
    string event_;


};
class LogicalOperationNode: public Node  {
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> &left, shared_ptr<Node> &pe): operation_(op),
        left_(left), right_(pe){}
    bool Evaluate(const Date& date, const string& event) const override;
private:
    LogicalOperation operation_;
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
};
