#include <iostream>
#include <limits.h>

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

stack<int> s1, s2;

bool enqueue(int v){
	if(s1.isFull()) return false;
	
	while(!s1.isEmpty()) s2.push(s1.pop());
	s1.push(v);
	
	while(!s2.isEmpty()) s1.push(s2.pop());
	
	return true;
}

int dequeue(){
	if(s1.isEmpty()) return INT_MIN;
	return s1.pop();
}

void printQueue(){
	if(!s1.isEmpty()){
		while(!s1.isEmpty()){
			cout << s1.top() << " ";
			s2.push(s1.pop());		
		}
		while(!s2.isEmpty()){
			s1.push(s2.pop());
		}
		cout << endl;
	}
	else
		cout << "Queue is empty\n";
}

void menu(){
	cout << "QUEUE OPERATIONS" << endl << endl;
	
	cout << "1. Enqueue" << endl;
	cout << "2. Dequeue" << endl;
	cout << "3. Print Queue" << endl;
	cout << "4. Exit" << endl;
	
	cout << "> Enter your choice: ";
}

int main(){
	int op;
	do{
		menu();
		int ele;
		cin >> op;
		
		switch(op){
			case 1:
				cout << "Enter element to add to queue: "; cin >> ele;
				enqueue(ele) ? (cout << "Successfully added element\n") : (cout << "Queue is full\n");
				break;
			case 2:
				ele = dequeue();
				ele == INT_MIN ? (cout << "Queue is empty\n") : (cout << ele << " has been removed\n");
				break;
			case 3:
				printQueue();
				break;
		}
		cout << endl;
	}while(op < 4);
	
	return 0;
}
