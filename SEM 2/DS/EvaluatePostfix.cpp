#include <iostream>

using namespace std;

template <typename T>
class stack
{
private:
	int capacity;
	int topIdx;
	T arr[100];

public:
	stack()
	{
		capacity = 5;
		topIdx = -1;
	}
	
	stack(int c)
	{
		capacity = c;
		topIdx = -1;
	}
	
	bool isEmpty() { return (topIdx == -1); }
	bool isFull() { return (topIdx == capacity - 1); }
	int size() { return topIdx + 1; }
	
	bool push(T c)
	{
		if(isFull()) return false;
		arr[++topIdx] = c;
		
		return true;
	}
	
	T pop()
	{
		T ele;
		if(!isEmpty())
			ele = arr[topIdx--];
		
		return ele;
	}
	
	T top()
	{ 
		T ele;
		if(!isEmpty())
			ele = arr[topIdx];
		
		return ele;
	}
		
	void print()
	{
		cout << "Stack: " << endl;
		for(int i = topIdx; i > -1; i--)
		{
			cout << arr[i];
			if(i == topIdx) cout << " <- top";
			cout << endl;
		}
	}	
};
