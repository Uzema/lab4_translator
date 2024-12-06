#ifndef __TERM_H__
#define __TERM_H__

#include "stack.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum class State {
	S0,
	Q1,
	Q2,
	Q3,
	Q4,
	Q5,
	ERROR
};

class Term {

public:
	virtual ~Term() {}
	virtual string GetType() {
		return "Term";
	}
};

class Operand : public Term {

public:
	string GetType() {
		return "Operand";
	}
};

class Number : public Operand {

public:
	string GetType() {
		return "Number";
	}

	virtual double GetValue() {
		return 0;
	}
};

class Integer : public Number {
	double value;
public:
	string GetType() {
		return "Integer";
	}

	double GetValue() {
		return this->value;
	}
};

class Floating : public Number {
	double value;
public:
	string GetType() {
		return "Floating";
	}

	double GetValue() {
		return this->value;
	}

	Floating() {
		this->value = 0;
	}

	Floating(double number) {
		this->value = number;
	}
};

class Operators : public Term {

public:
	string GetType() {
		return "Operators";
	}
	virtual int GetPriority() {
		return 0;
	}
};

class Add : public Operators {
	int priority = 1;
public:
	Add() {}

	string GetType() {
		return "Add";
	}
	int GetPriority() {
		return this->priority;
	}
};

class Sub : public Operators {
	int priority = 1;
public:
	string GetType() {
		return "Sub";
	}
	int GetPriority() {
		return this->priority;
	}
};

class Mul : public Operators {
	int priority = 2;
public:
	Mul() {}

	string GetType() {
		return "Mul";
	}
	int GetPriority() {
		return this->priority;
	}
};

class Div : public Operators {
	int priority = 2;
public:
	Div() {}

	string GetType() {
		return "Div";
	}
	int GetPriority() {
		return this->priority;
	}
};

class Brackets : public Term {

public:
	string GetType() {
		return "Brackets";
	}
};

class OpeningBracket : public Brackets {
	
public:
	OpeningBracket() {}

	string GetType() {
		return "OpeningBracket";
	}
};

class ClosingBracket : public Brackets {

public:
	ClosingBracket() {}

	string GetType() {
		return "ClosingBracket";
	}
};


class Translator {
	string infix;
	vector<Term*> postfix;
	vector<Term*> lexems;

public:
	Translator(string infix_string) {
		this->infix = infix_string;
	}

	void everything() {
		if (StringAnalyze() == true) {
			ToPostFix();
			double answer;
			answer = Calculate();
			cout << "and the answer is :" << answer;
		}
		else {
			cout << "string analyze says you're a bad person";
		}
	}

	bool StringAnalyze() {
		if (infix.size() == 0) {
			throw "empty string";
		}

		State ka = State::S0;
		string strNum = "";
		int k = 0;

		for (int i = 0; i < infix.size(); i++) {

			//cout << strNum << endl;

			switch (ka) {

			case State::S0: if (infix[i] >= '0' && infix[i] <= '9') {
				ka = State::Q1;
				strNum = "";
				strNum += infix[i];
				if (i == infix.size() - 1) {
					double number = stod(strNum);
					lexems.push_back(new Floating(number));
					strNum = "";
				}
			}
						  else if (infix[i] == '(') {
				ka = State::Q3;
				k += 1;
				if (k < 0) {
					ka = State::ERROR;
					break;
				}
				lexems.push_back(new OpeningBracket());
			}
						  else {
				ka = State::ERROR;
			}
						  break;

			case State::Q1: if (infix[i] >= '0' && infix[i] <= '9') {
				ka = State::Q1;
				strNum += infix[i];
				if (i == infix.size() - 1) {
					double number = stod(strNum);
					lexems.push_back(new Floating(number));
					strNum = "";
				}
			}
						  else if (infix[i] == '.') {
				ka = State::Q2;
				strNum += infix[i];
			}
						  else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
				ka = State::Q4;
				double number = stod(strNum);
				lexems.push_back(new Floating(number));
				strNum = "";
				switch (infix[i]) {
				case ('+'): lexems.push_back(new Add());
					break;
				case ('-'): lexems.push_back(new Sub());
					break;
				case ('*'): lexems.push_back(new Mul());
					break;
				case ('/'): lexems.push_back(new Div());
					break;
				}
			}
						  else if (infix[i] == ')') {
				ka = State::Q5;
				k -= 1;
				if (k < 0) {
					ka = State::ERROR;
					break;
				}
				double number = stod(strNum);
				lexems.push_back(new Floating(number));
				strNum = "";
				lexems.push_back(new ClosingBracket());
			}
						  else {
				ka = State::ERROR;
			}
						  break;

			case State::Q2: if (infix[i] >= '0' && infix[i] <= '9') {
				ka = State::Q2;
				strNum += infix[i];
				if (i == infix.size() - 1) {
					double number = stod(strNum);
					lexems.push_back(new Floating(number));
					strNum = "";
				}
			}
						  else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
				ka = State::Q4;
				double number = stod(strNum);
				lexems.push_back(new Floating(number));
				strNum = "";
				switch (infix[i]) {
				case ('+'): lexems.push_back(new Add());
					break;
				case ('-'): lexems.push_back(new Sub());
					break;
				case ('*'): lexems.push_back(new Mul());
					break;
				case ('/'): lexems.push_back(new Div());
					break;
				}
			}
						  else if (infix[i] == ')') {
				ka = State::Q5;
				k -= 1;
				if (k < 0) {
					ka = State::ERROR;
					break;
				}
				double number = stod(strNum);
				lexems.push_back(new Floating(number));
				strNum = "";
				lexems.push_back(new ClosingBracket());
			}
						  else {
				ka = State::ERROR;
			}
						  break;

			case State::Q3: if (infix[i] >= '0' && infix[i] <= '9') {
				ka = State::Q1;
				strNum += infix[i];
				if (i == infix.size() - 1) {
					double number = stod(strNum);
					lexems.push_back(new Floating(number));
					strNum = "";
				}
			}
						  else if (infix[i] == '(') {
				ka = State::Q3;
				k += 1;
				if (k < 0) {
					ka = State::ERROR;
					break;
				}
				lexems.push_back(new OpeningBracket());
			}
						  else {
				ka = State::ERROR;
			}
				break;
			case State::Q4: if (infix[i] >= '0' && infix[i] <= '9') {
				ka = State::Q1;
				strNum = "";
				strNum += infix[i];
				if (i == infix.size() - 1) {
					double number = stod(strNum);
					lexems.push_back(new Floating(number));
					strNum = "";
				}
			}
						  else if (infix[i] == '(') {
				ka = State::Q3;
				k += 1;
				if (k < 0) {
					ka = State::ERROR;
					break;
				}
				lexems.push_back(new OpeningBracket());
			}
						  else {
				ka = State::ERROR;
			}
						  break;
			case State::Q5: if (infix[i] == ')') {
				ka = State::Q5;
				k -= 1;
				if (k < 0) {
					ka = State::ERROR;
					break;
				}
				lexems.push_back(new ClosingBracket());
			}
						  else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
				ka = State::Q4;
				switch (infix[i]) {
				case ('+'): lexems.push_back(new Add());
					break;
				case ('-'): lexems.push_back(new Sub());
					break;
				case ('*'): lexems.push_back(new Mul());
					break;
				case ('/'): lexems.push_back(new Div());
					break;
				}
			}
				break;
			case State::ERROR: break;
			default: ka = State::ERROR;
				break;
			}
		}//for
		return (ka == State::Q1 || ka == State::Q2 || ka == State::Q5);
	}

	void ToPostFix() {
		//Parse();
		Stack<Term*, vector> st;
		Term* stackItem;
		for (int i = 0; i < lexems.size(); i++) {
			if (lexems[i]->GetType() == "OpeningBracket") {
				st.push(lexems[i]);
			}
			else if (lexems[i]->GetType() == "ClosingBracket") {
				stackItem = st.top();
				st.pop();
				while (stackItem->GetType() != "OpeningBracket") {
					postfix.push_back(stackItem);
					stackItem = st.top();
					st.pop();
				}
			}
			else if (lexems[i]->GetType() == "Add" || lexems[i]->GetType() == "Sub" || \
				lexems[i]->GetType() == "Mul" || lexems[i]->GetType() == "Div") {
				while (!st.empty()) {
					stackItem = st.top();
					st.pop();
					Operators* op1 = dynamic_cast<Operators*>(lexems[i]);
					Operators* op2 = dynamic_cast<Operators*>(stackItem);
					if (op1->GetPriority() <= op2->GetPriority()) {
						postfix.push_back(stackItem);
					}
					else {
						st.push(stackItem);
						break;
					}
				}
				st.push(lexems[i]);
			}
			else {
				postfix.push_back(lexems[i]);
			}
		}//for
		while (!st.empty()) {
			stackItem = st.top();
			st.pop();
			postfix.push_back(stackItem);
		}
	}

	double Calculate() {
		Stack<double, vector> st;
		double leftOperand, rightOperand;
		for (int i = 0; i < postfix.size(); i++) {
			cout << postfix[i]->GetType() << endl;
			if (postfix[i]->GetType() == "Add") {
				rightOperand = st.top();
				st.pop();
				leftOperand = st.top();
				st.pop();
				st.push(leftOperand + rightOperand);
			}
			else if (postfix[i]->GetType() == "Sub") {
				rightOperand = st.top();
				st.pop();
				leftOperand = st.top();
				st.pop();
				st.push(leftOperand - rightOperand);
			}
			else if (postfix[i]->GetType() == "Mul") {
				rightOperand = st.top();
				st.pop();
				leftOperand = st.top();
				st.pop();
				st.push(leftOperand * rightOperand);
			}
			else if (postfix[i]->GetType() == "Div") {
				rightOperand = st.top();
				st.pop();
				leftOperand = st.top();
				st.pop();
				if (rightOperand == 0) {
					throw "cant divide by 0";
				}
				st.push(leftOperand / rightOperand);
			}
			else {
				Number* thing = dynamic_cast<Number*>(postfix[i]);
				double number = thing->GetValue();
				st.push(number);
			}
		}
		return st.top();
	}
};


#endif