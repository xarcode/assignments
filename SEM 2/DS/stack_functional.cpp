#include <iostream>
#include <cstdlib>
#include <cstdio>

#define INVALID_DATA ' '

using namespace std;

const int capacity = 5;
int topIdx = -1;
char arr[capacity];

bool isEmpty() { return (topIdx == -1); }
bool isFull() { return (topIdx == capacity - 1); }
int size() { return topIdx + 1; }

bool push(char c)
{
	if(isFull()) return false;
	arr[++topIdx] = c;
	
	return true;
}

char pop()
{
	if(isEmpty()) return INVALID_DATA;
	return arr[topIdx--];	
}

char top()
{ 
	if(isEmpty()) return INVALID_DATA;
	return arr[topIdx]; 
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
	char item;
	
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
		
//		cout << "Press enter to continue..." << endl;
//		getchar();
//		system("cls");
	}
	return 0;
}
