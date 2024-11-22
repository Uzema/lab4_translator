#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <vector>

using namespace std;

template <class T, template<class, class...> class Tcont>
class Stack {

	Tcont<T> data;

public:

	void push(const T& val);
	void pop();
	T& top();
	bool empty();
	size_t size();
};

template <class T, template<class, class...> class Tcont>
inline void Stack<T, Tcont>::push(const T& val) {
	data.push_back(val);
}

template <class T, template<class, class...> class Tcont>
inline void Stack<T, Tcont>::pop() {
	if (data.empty()) {
		throw "Empty stack";
	}
	data.pop_back();
}

template <class T, template<class, class...> class Tcont>
inline T& Stack<T, Tcont>::top() {
	if (data.empty()) {
		throw "Empty stack, no element on top";
	}
	return data.back();
}

template <class T, template<class, class...> class Tcont>
inline bool Stack<T, Tcont>::empty() {
	return (data.size() == 0);
}

template <class T, template<class, class...> class Tcont>
inline size_t Stack<T, Tcont>::size() {
	return data.size();
}
#endif
