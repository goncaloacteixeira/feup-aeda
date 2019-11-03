# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
    stack<T> s;
    stack<T> min;
public:
	StackExt() {
	    this->s = {};
	    this->min = {};
	};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

template <class T>
bool StackExt<T>::empty() const
{
	return this->s.empty();
}

template <class T>
T& StackExt<T>::top()
{
    return this->s.top();
}

template <class T>
void StackExt<T>::pop()
{
    if (!min.empty())
        if (s.top() == min.top())
            min.pop();
    s.pop();
}

template <class T>
void StackExt<T>::push(const T & val)
{
    if (min.empty())
        min.push(val);
    else if (min.top() > val)
        min.push(val);
    s.push(val);
}

template <class T>
T& StackExt<T>::findMin()
{
    return min.top();
}

