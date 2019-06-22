#include "node.h"

bool EmptyNode::Evaluate(const Date& dates, const string& event)const {
    return true;
}
template <typename T>
bool CompareTo(const T& lhs, const T& rhs, Comparison cmp) {
    switch (cmp) {
    case Comparison::Less:
        return lhs < rhs;
    case Comparison::LessOrEqual:
        return lhs <= rhs;
    case Comparison::Equal:
        return lhs == rhs;
    case Comparison::NotEqual:
        return lhs != rhs;
    case Comparison::Greater:
        return lhs > rhs;
    case Comparison::GreaterOrEqual:
        return lhs >= rhs;
    }
    return false;
}
bool EventComparisonNode::Evaluate(const Date& date, const string& event) const{
    return CompareTo(event, event_, cmp_);
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return CompareTo(date, date_, cmp_);
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    switch (operation_) {
    case LogicalOperation::And:
        return left_->Evaluate(date,event)&& right_->Evaluate(date,event);
    case LogicalOperation::Or:
        return left_->Evaluate(date,event)|| right_->Evaluate(date,event);
    }
    return false;
}
