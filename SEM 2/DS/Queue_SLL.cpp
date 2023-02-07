#include <iostream>
#include <limits.h>

using namespace std;

struct node {
	int data;
	node *next;
};

node *front = NULL;
int c = 0;

bool isEmpty(){
	return front == NULL;
}

int size(){ return c; }

bool insertBegin(int v){
	node *nn = new node();
	
	if(!nn) return false;
	
	c++;
	nn->data = v;
	nn->next = front;
	front = nn;
	
	return true;
}

bool insertEnd(int v){
	node *nn = new node();
	
	if(!nn) return false;
	
	c++;
	if(isEmpty()) return insertBegin(v);
	
	node *temp = front;
	nn->data = v;
	nn->next = NULL;
	while(temp->next) temp = temp->next;
	
	temp->next = nn;
	
	return true;
}

int deleteBegin(){
	if(isEmpty()) return INT_MIN;
	c--;
	node *rn = front;
	front = front->next;
	
	int rv = rn->data;
	
	delete rn;
	
	return rv;
}

int deleteEnd(){
	node *rn, *temp;
	int rv;
	
	if(isEmpty()) return INT_MIN;
	c--;
	temp = front;
	
	while(temp->next->next) temp = temp->next;
	
	rn = temp->next;
	rv = rn->data;
	temp->next = NULL;
	delete rn;
	
	return rv;
}

void display(){
	if(isEmpty()) return;
	
	node *temp = front;
	
	cout << temp->data << " <- front" << endl;
	temp = temp->next;
	
	while(temp->next){
		cout << temp->data << "\n";
		temp = temp->next;
	} 
	cout << temp->data << " <- rear" << endl;
}

void menu(){
	cout << "------------------------------------------------\n";
	cout << "     Menu of opearations for Queue using SLL    \n";
	cout << "------------------------------------------------\n";
	cout << "1. Enqueue" << endl;
	cout << "2. Dequeue" << endl;
	cout << "3. Size of Queue" << endl;
	cout << "4. Check if Queue is Empty" << endl;
	cout << "5. Print the Queue" << endl;
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
				cout << "Enter a value: "; cin >> v;
				insertEnd(v);
				break;
			case 2:
				cout << deleteBegin() << " has been deleted" << endl;
				break;
			case 3:
				cout << "Size of Queue is " << size() << endl;
				break;
			case 4:
				if(isEmpty()) cout << "Queue is Empty" << endl;
				else cout << "Queue is not empty" << endl;
				break;
			case 5:
				display();
				break;
		}
	}while(ch < 6);
	return 0;
}
