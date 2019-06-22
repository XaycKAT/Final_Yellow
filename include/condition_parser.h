#pragma once

#include "node.h"

#include <memory>
#include <iostream>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);
enum class Comparison
{
Less,
LessOrEqual,
Greater,
GreaterOrEqual,
Equal,
NotEqual
};
void TestParseCondition();
