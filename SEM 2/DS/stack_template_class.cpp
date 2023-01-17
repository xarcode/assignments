#include <iostream>
#include <cstdlib>
#include <cstdio>

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

void menu()
{
	cout << "MENU IF OPERATIONS ON STACK" << endl;
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Show top" << endl;
	cout << "4. Check if stack is empty" << endl;
	cout << "5. Check if stack is full" << endl;
	cout << "6. Show size of stack" << endl;
	cout << "7. Display the contents of stack" << endl;
	cout << "8. Exit" << endl;
}

int main()
{
	int choice = 0;
	float item;
	stack<float> s;
	
	while(choice < 8)
	{
		menu();
		cout << "Enter your choice: "; cin >> choice;
		system("cls");
		switch(choice)
		{
			case 1:
				cout << "Enter an element to push on the stack: "; cin >> item;
				s.push(item) ? cout << item << " has been added to stack" : cout << item << " could not be added to stack";
				cout << endl;
				break;
			case 2:
				if(!s.isEmpty())
					cout << s.pop() << endl;
				else cout << "Stack underflow" << endl;
				break;
			case 3:
				if(!s.isEmpty())
					cout << s.top() << endl;
				else cout << "Stack is empty" << endl;
				break;
			case 4:
				s.isEmpty() ? cout << "stack is empty" : cout << "stack is not empty";
				cout << endl;
				break;
			case 5:
				s.isFull() ? cout << "stack is full" : cout << "stack is not full";
				cout << endl;
				break;
			case 6:
				cout << "stack size = " << s.size() << endl;
				break;
			case 7:
				s.print();
				break;
		}
	}
	return 0;
}
