#include <iostream>
#include <limits.h>

using namespace std;

struct node {
	int data;
	node *next, *prev;
};

node *head = NULL;
int c = 0;

bool isEmpty(){
	return head == NULL;
}

int size(){ return c; }

bool insertBegin(int v){
	node *nn = new node;
	
	if(!nn) return false;
	c++;
	nn->next = nn->prev = NULL;
	nn->data = v;
	
	if(isEmpty()) head = nn;
	else{
		nn->next = head;
		head = nn;
		head->prev = nn;
	}
	
	return true;
}

bool insertEnd(int v){
	node *temp, *nn = new node();
	
	nn->next = nn->prev = NULL;
	nn->data = v;
	
	if(!nn) return false;
	c++;
	if(isEmpty()) head = nn;
	else{
		temp = head;
		while(temp->next) temp = temp->next;
		temp->next = nn;
		nn->prev = temp;
	}
	
	return true;
}

int deleteBegin(){
	if(isEmpty()) return INT_MIN;
	
	node *rn = head;
	head = head->next;
	
	if(size() > 1) head->prev = NULL;
	int rv = rn->data;
	delete rn;
	c--;
	return rv;
}

int deleteEnd(){
	node *rn, *temp;
	int rv;
	
	if(isEmpty()) return INT_MIN;
	
	if(size() == 1) return deleteBegin();
	
	temp = head;
	while(temp->next->next) temp = temp->next;
	
	rn = temp->next;
	rv = rn->data;
	
	temp->next = NULL;
	
	delete rn;
	
	return rv;
}

void display(){
	if(isEmpty()) return;
	
	node *temp = head;
	
	if(size() == 1){
		cout << temp->data << endl;
		return;
	}
	
	while(temp->next){
		cout << temp->data << "->";
		temp = temp->next;
	} 
	cout << temp->data << endl;
}

void menu(){
	cout << "------------------------------------------------\n";
	cout << "       Menu of opearations for LINKED LIST      \n";
	cout << "------------------------------------------------\n";
	cout << "1. Insert at Begin" << endl;
	cout << "2. Insert at End" << endl;
	cout << "3. Remove from Begin" << endl;
	cout << "4. Remove from End" << endl;
	cout << "5. Size of Linked List" << endl;
	cout << "6. Check if Linked List is Empty" << endl;
	cout << "7. Print the Linked List" << endl;
	cout << "8. Exit" << endl;
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
				insertBegin(v);
				break;
			case 2:
				cout << "Enter a value: "; cin >> v;
				insertEnd(v);
				break;
			case 3:
				cout << deleteBegin() << " has been deleted" << endl;
				break;
			case 4:
				cout << deleteEnd() << " has been deleted" << endl;
				break;
			case 5:
				cout << "Size of Linked List is " << size() << endl;
				break;
			case 6:
				if(isEmpty()) cout << "Linked List is Empty" << endl;
				else cout << "Linked List is not empty" << endl;
				break;
			case 7:
				display();
				break;
		}
	}while(ch < 8);
	return 0;
}
