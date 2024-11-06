#include "stack.h"

template <class T, template <class> class Tcont>
void Stack<T, Tcont>::push(const T& val) {
	data.push_back(val);
}

template <class T, template <class> class Tcont>
void Stack<T, Tcont>::pop() {
	if (empty) {
		throw "Empty stack";
	}
	data.pop_back();
}

template <class T, template <class> class Tcont>
T& Stack<T, Tcont>::top() {
	if (empty) {
		throw "Empty stack, no element on top";
	}
	return data.back();
}

template <class T, template <class> class Tcont>
bool Stack<T, Tcont>::empty() {
	return (data.size() == 0);
}

template <class T, template <class> class Tcont>
size_t Stack<T, Tcont>::size() {
	return data.size();
}
