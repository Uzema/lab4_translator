#ifndef __TERM_H__
#define __TERM_H__

#include "stack.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class ArithmeticExperssion {
	string infix;
	string postfix;
	vector<string> lexems;
	map<char, int> priority;
	map<string, double> operands;

	void Parse();
	void ToPostFix() {
		Parse();
		Stack<string, vector> st;
		string stackItem;
		for (string item : lexems) {
			if (item == "(") {
				st.push(item);
			} else if (item == ")") {
				st.pop(stackItem);
				while (stackItem != "(") {
					postfix += stackItem;
					stackItem = st.pop();
				}
			}
		}
	}

public:
	
	ArithmeticExperssion(string infx) : infix(infx) {
		priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
	}

	string GetInfix() const {
		return infix; 
	}

	string GetPostFix() const {
		return postfix;
	}

	vector<string> GetOperands() const;
	double Calculate(const map<string, double>& values);
};

#endif