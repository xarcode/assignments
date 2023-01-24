#include <iostream>

using namespace std;

#define CAPACITY 5

int count = 0;

template <typename T>
class Queue{
	T arr[CAPACITY];
	int frontIdx;
	int rearIdx;
	int count;
	int capacity;
	
public:
	Queue(){
		frontIdx = rearIdx = -1;
		count = 0;
		capacity = CAPACITY;
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	bool isFull(){
		return count == capacity;
	}
	
	bool enqueue(T u){
		if(isFull())
			return false;
		if(isEmpty()) frontIdx = 0;
		rearIdx = (rearIdx + 1) % capacity;
		arr[rearIdx] = u;
		count ++;
		return true;
	}
	
	// called on non-empty queue
	T dequeue(){
		T ru = arr[frontIdx];
		if(size() == 1) frontIdx = rearIdx = -1;
		else frontIdx = (frontIdx + 1) % capacity;
		
		count --;
		return ru;
	}
	
	void print(){
		if(!isEmpty()){
			for(int i = frontIdx; i != rearIdx;){
				cout << arr[i];
				if(i == frontIdx) cout << " <- front";
				cout << endl;
				i = (i + 1) % capacity;
			}
			cout << arr[rearIdx] << " <- rear " << endl;
		}
	}
};

Queue<int> q1;
Queue<int> q2;

bool push(int u){
	q2.enqueue(u);
	while(!q1.isEmpty())
		q2.enqueue(q1.dequeue());
	while(!q2.isEmpty())
		q1.enqueue(q2.dequeue());
	
	count ++;
	return true;
}

int pop(){
	count --;
	return q1.dequeue();
}

int top(){
	int i = pop();
	push(i);
	return i;
}

bool isEmpty(){
	return count == 0;
}

bool isFull(){
	return count == CAPACITY;
}

int size(){
	return count;
}

void print(){
	bool topPrinted = false;
	cout << "top -> ";
	while(!q1.isEmpty()){
		int i = q1.dequeue();
		if(topPrinted) cout << "       ";
		else topPrinted = true;
		cout << i << endl;
		q2.enqueue(i);
	}
	while(!q2.isEmpty())
		q1.enqueue(q2.dequeue());
}

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
	int item;
	
	while(choice < 8)
	{
		menu();
		cout << "Enter your choice: "; cin >> choice;
		system("cls");
		switch(choice)
		{
			case 1:
				cout << "Enter an element to push on the stack: "; cin >> item;
				push(item) ? cout << item << " has been added to stack" : cout << item << " could not be added to stack";
				cout << endl;
				break;
			case 2:
				if(isEmpty())
					cout << "Cannot pop from stack" << endl;
				else cout << pop() << " has beem removed" << endl;
				break;
			case 3:
				cout << top() << endl;
				break;
			case 4:
				isEmpty() ? cout << "stack is empty" : cout << "stack is not empty";
				cout << endl;
				break;
			case 5:
				isFull() ? cout << "stack is full" : cout << "stack is not full";
				cout << endl;
				break;
			case 6:
				cout << "stack size = " << size() << endl;
				break;
			case 7:
				print();
				break;
		}
	}
	return 0;
}
