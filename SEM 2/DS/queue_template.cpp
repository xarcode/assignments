#include <iostream>

using namespace std;

#define CAPACITY 5

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

void menu()
{
	cout << "MENU OF OPERATIONS ON QUEUE" << endl;
	cout << "1. Enqueue" << endl;
	cout << "2. Dequeue" << endl;
	cout << "3. Check if queue is empty" << endl;
	cout << "4. Check if queue is full" << endl;
	cout << "5. Show size of queue" << endl;
	cout << "6. Display the contents of queue" << endl;
	cout << "7. Exit" << endl;
}

int main()
{
	Queue<char> q;
	int op;
	char ele;
	do{
		menu();
		cout << "Enter your choice: "; cin >> op;
		
		switch(op){
			case 1:
				cout << "Enter an element to enter in the queue: ";
				cin >> ele;
				if(!q.enqueue(ele)) cout << "Queue is full" << endl;
				break;
			case 2:
				if(!q.isEmpty()) cout << q.dequeue() << " has been removed from the queue" << endl;
				break;
			case 3:
				if(q.isEmpty()) cout << "Queue is empty" << endl;
				else cout << "Queue is not empty" << endl;
				break;
			case 4:
				if(q.isFull()) cout << "Queue is full" << endl;
				else cout << "Queue is not full" << endl;
				break;
			case 5:
				cout << "Size of queue is " << q.size() << endl;
				break;
			case 6:
				q.print();
				break;
		}
	}while(op < 7);
	return 0;	
}
