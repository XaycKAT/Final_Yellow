#pragma once
#include <iostream>
#include <date.h>
#include <condition_parser.h>
using namespace std;
enum LogicalOperation {
    Or,
    And
};

class Node{
public:
    virtual bool Evaluate(const Date &d,const string &event) const = 0;

};

class EmptyNode: public Node {
public:
    EmptyNode (const Date &d, const string &event): event_(event), d_(d) {}
private:
    const string event_;
    const Date d_;
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
    EventComparisonNode(Comparison cmp, const string& value): cmp_(cmp){}
    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison cmp_;

};
class LogicalOperationNode: public Node  {
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> &left, shared_ptr<Node> &pe){}

};
