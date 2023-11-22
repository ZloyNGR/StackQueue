#include <iostream>
using namespace std;
template<class A>
class TStack
{
protected:
	A* arr;
	int size, tail;
public:
	TStack()
	{
		arr = new A[1];
		size = 1;
		tail = 0;
		arr[0] = 0;
	}
	TStack(const TStack& other)
	{
		delete[] arr;
		this->size = other.size;
		this->arr = new A[size];
		this->tail = other.tail;
		for (int i = 0; i < size; i++)
			this->arr[i] = other.arr[i];
	}
	~TStack()
	{
		delete[] arr;
		size = 0;
		tail = 0;
	}
	TStack(int _size)
	{
		if (_size < 0) throw logic_error("ERROR");
		size = _size;
		arr = new A[size];

		tail = 0;
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}

	TStack(const std::initializer_list<A>& list)
		: TStack(list.size())
	{
		int count = 0;
		for (auto& element : list)
		{
			this->arr[count] = element;
			++count;
		}
		tail = size;
	}

	void push(A elem)
	{
		if (tail >= size) throw logic_error("out of range");
		arr[tail] = elem;
		tail++;
	}
	A pop()
	{
		if (tail == 0) throw logic_error("stack empty");
		A temp = arr[tail - 1];
		tail--;
		return temp;
	}



	friend ostream& operator<<(ostream& ostr, const TStack<A>& lhs)
	{
		for (int i = 0; i < lhs.tail; i++)
			ostr << lhs.arr[i] << ' ';
		ostr << endl;
		return ostr;
	}
};
