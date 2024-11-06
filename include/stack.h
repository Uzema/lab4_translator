#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

template <class T, template <class> class Tcont>
class Stack {

	Tcont<T> data;

public:

	void push(const T& val);
	void pop();
	T& top();
	bool empty();
	size_t size();
};

#endif
