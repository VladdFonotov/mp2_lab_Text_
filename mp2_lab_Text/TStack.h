#pragma once

#define _TSTack_
using namespace std;

template<class T>
class TStack
{
	T* arr;
	int size;
	int num;
public:
	TStack(int _size = 10);
	~TStack() { delete[] arr; };
	TStack(const TStack<T>& a);
	TStack& operator=(const TStack& a);
	bool IsEmpty() const;
	bool IsFull() const;
	T Pop();
	T Top() const;
	void Clear();
	void Push(const T& a);
	int GetSize() { return size; }
	int GetNum() { return num; }
};
template <class T>
TStack<T>::TStack(int _size)
{
	if (_size <= 0) throw 1;
	size = _size;
	arr = new T[size];
	num = -1;
}
template <class T>
TStack<T>::TStack(const TStack& a)
{
	size = a.size;
	num = a.num;
	arr = new T[size];
	for (int i = 0; i < num; i++)
	{
		arr[i] = a.arr[i];
	}
}
template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& a)
{
	size = a.size;
	num = a.num;
	arr = new T[size];
	for (int i = 0; i < num; i++)
	{
		arr[i] = a.arr[i];
	}
	return *this;
}
template <class T>
bool TStack<T>::IsEmpty() const
{
	return num == -1;
}
template <class T>
bool TStack<T>::IsFull() const
{
	return num == size - 1;
}
template <class T>
T TStack<T> ::Pop()
{
	if (IsEmpty()) throw - 2;
	return arr[num--];
}
template <class T>
T TStack<T> ::Top() const
{
	if (IsEmpty()) throw - 2;
	return arr[num];
}
template <class T>
void TStack<T> ::Push(const T& a)
{
	if (IsFull()) throw - 1;
	arr[++num] = a;
}
template <class T>
void TStack<T> ::Clear()
{
	num = -1;
}
