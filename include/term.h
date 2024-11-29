#ifndef __TERM_H__
#define __TERM_H__

#include "stack.h"
#include <vector>
#include <string>

using namespace std;


class Translator {
	string infix;
	vector<Term*> postfix;
	vector<Term*> lexems;
	
public:
	void Parse() {}
	void ToPostFix() {
		Parse();
		Stack<Term*, vector> st;
		Term* stackItem;
		for (int i = 0; i < lexems.size(); i++) {
			if (lexems[i]->GetType() == "OpeningBracket") {
				st.push(lexems[i]);
			}
			else if (lexems[i]->GetType() == "ClosingBracket") { // :3
				stackItem = st.top();
				while (stackItem->GetType() != "OpeningBracket") {
					postfix.push_back(stackItem);
					stackItem = st.top();
					st.pop();
				}
			}
		}
	}
	void Calculate() {}
};

class Term {

public:
	virtual ~Term() {}
	string GetType() {
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
};

class Operators : public Term {

public:
	string GetType() {
		return "Operators";
	}
};

class Add : public Operators {
	int priority = 1;
public:
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
	string GetType() {
		return "OpeningBracket";
	}
};

class ClosingBracket : public Brackets {

public:
	string GetType() {
		return "ClosingBracket";
	}
};

#endif