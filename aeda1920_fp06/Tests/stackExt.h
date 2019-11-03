# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const
{
	return true;
}

//a alterar
template <class T> 
T& StackExt<T>::top()
{
    T *novo = new T();
    return *novo;
}

//a alterar
template <class T> 
void StackExt<T>::pop()
{
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val)
{
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
    T *novo = new T();
    return *novo;
}

