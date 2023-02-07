#include <iostream>
#include <limits.h>

using namespace std;

struct node {
	int data;
	node *next;
};

node *top = NULL;
int c = 0;

bool isEmpty(){
	return top == NULL;
}

int size(){ return c; }

bool insertBegin(int v){
	node *nn = new node();
	
	if(!nn) return false;
	
	c++;
	nn->data = v;
	nn->next = top;
	top = nn;
	
	return true;
}

bool insertEnd(int v){
	node *nn = new node();
	
	if(!nn) return false;
	
	c++;
	if(isEmpty()) return insertBegin(v);
	
	node *temp = top;
	nn->data = v;
	nn->next = NULL;
	while(temp->next) temp = temp->next;
	
	temp->next = nn;
	
	return true;
}

int deleteBegin(){
	if(isEmpty()) return INT_MIN;
	c--;
	node *rn = top;
	top = top->next;
	
	int rv = rn->data;
	
	delete rn;
	
	return rv;
}

int deleteEnd(){
	node *rn, *temp;
	int rv;
	
	if(isEmpty()) return INT_MIN;
	c--;
	temp = top;
	
	while(temp->next->next) temp = temp->next;
	
	rn = temp->next;
	rv = rn->data;
	temp->next = NULL;
	delete rn;
	
	return rv;
}

void display(){
	if(isEmpty()) return;
	
	node *temp = top;
	
	cout << temp->data << " <- top" << endl;
	temp = temp->next;
	while(temp){
		cout << temp->data << endl;
		temp = temp->next;
	}
}

void menu(){
	cout << "------------------------------------------------\n";
	cout << "     Menu of opearations for Stack using SLL    \n";
	cout << "------------------------------------------------\n";
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Size of Stack" << endl;
	cout << "4. Check if Stack is Empty" << endl;
	cout << "5. Print the Stack" << endl;
	cout << "6. Exit" << endl;
}

int main(){
	int ch, v;
	do{
		menu();
		cout << "Enter your choice: ";
		cin >> ch;
		
		switch(ch){
			case 1:
				cout << "Push: "; cin >> v;
				insertBegin(v);
				break;
			case 2:
				cout << deleteBegin() << " has been popped" << endl;
				break;
			case 3:
				cout << "Size of Stack is " << size() << endl;
				break;
			case 4:
				if(isEmpty()) cout << "Stack is Empty" << endl;
				else cout << "Stack is not empty" << endl;
				break;
			case 5:
				display();
				break;
		}
	}while(ch < 6);
	return 0;
}
