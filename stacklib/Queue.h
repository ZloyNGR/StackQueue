#pragma once
#include "Stack.h"
template<class A>
class TQueue : public TStack<A>
{
protected:
	int head;

public:
	TQueue() :TStack<A>() { head = 0; }
	TQueue(TQueue& lhs) :TStack<A>(lhs) { head = lhs.head; }
	TQueue(int _size) :TStack<A>(_size) { head = 0; }
	TQueue(const std::initializer_list<A>& list) :TStack<A>(list) { head = 0; this->tail = 0; }
	~TQueue() { head = 0; }

	void push(A elem)
	{
		this->arr[this->tail] = elem;
		this->tail = (this->tail + 1) % this->size;
	}

	A ()
	{
		
		A temp = this->arr[head];
		head = (head + 1) % this->size;
		return temp;
	}

	friend ostream& operator<<(ostream& ostr, const TQueue<A>& lhs)
	{
		if (lhs.tail == lhs.head)
			for (int i = lhs.head; i < lhs.size; i++)
				ostr << lhs.arr[i] << ' ';
		else
			if (lhs.tail > lhs.head)
				for (int i = lhs.head; i < lhs.tail; i++)
					ostr << lhs.arr[i] << ' ';
			else
			{
				int t = lhs.tail + lhs.head + lhs.head + 1;
				for (int i = lhs.head; i < t; i++)
					ostr << lhs.arr[i % lhs.size] << ' ';
			}
		ostr << endl;
		return ostr;
	}


};
