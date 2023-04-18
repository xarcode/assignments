#include <iostream>
#include <limits.h>

using namespace std;

struct node
{
	int data, ht;
	struct node *left;
	struct node *right;
	
	node(){
		data = ht = 0;
		left = right = NULL;
	}
};

node *root = NULL;

int max(int a, int b){
	return a < b ? b : a;
}

int height(node *curNode){
	if(curNode == NULL) return -1;
	return curNode->ht;
}

int 

// Search
node *search(node *curNode, int sv)
{
	if (curNode == NULL)
		return NULL;
	if (curNode->data == sv)
	{
		return curNode;
	}
	else if (curNode->data < sv)
		return search(curNode->right, sv);
	else
		return search(curNode->left, sv);
}

bool search(int sv)
{
	node *serNode = search(root, sv);
	if (serNode == NULL)
		return false;
	if (serNode->data == sv)
		return true;
	return false;
}

// insert
node *insert(node *curNode, int v)
{
	if (curNode == NULL)
	{
		node *nn = new node();
		nn->data = v;
		nn->left = NULL;
		nn->right = NULL;
		return nn;
	}
	if (v < curNode->data)
		curNode->left = insert(curNode->left, v);
	else if (v > curNode->data)
		curNode->right = insert(curNode->right, v);
	
	
	return curNode;
}

bool insert(int v)
{
	root = insert(root, v);
	return search(v);
}

// MAX and MIN
int maxVal(node *curNode)
{
	if (curNode == NULL)
		return -1;
	if (curNode->right == NULL)
		return curNode->data;
	return maxVal(curNode->right);
}

int minVal(node *curNode)
{
	if (curNode == NULL)
		return -1;
	if (curNode->left == NULL)
		return curNode->data;
	return minVal(curNode->left);
}

// Predecessor and Successor
int predecessor(int v)
{
	node *serNode = search(root, v);
	if(serNode)
		return maxVal(serNode->left);
	return -1;
}

int successor(int v)
{
	node *serNode = search(root, v);
	if(serNode)
		return minVal(serNode->right);
	return -1;
}

// Traversals
// inorder
void inorder(node *curNode)
{
	if (curNode != NULL)
	{
		inorder(curNode->left);
		cout << curNode->data << " ";
		inorder(curNode->right);
	}
}

void preorder(node *curNode)
{
	if (curNode != NULL)
	{
		cout << curNode->data << " ";
		preorder(curNode->left);
		preorder(curNode->right);
	}
}

void postOrder(node *curNode)
{
	if (curNode != NULL)
	{
		postOrder(curNode->left);
		postOrder(curNode->right);
		cout << curNode->data << " ";
	}
}

// DELETE
node *deleteNode(node *curNode, int v)
{
	if (curNode == NULL)
		return NULL;
	if (v < curNode->data)
		curNode->left = deleteNode(curNode->left, v);
	else if (v > curNode->data)
		curNode->right = deleteNode(curNode->right, v);
	else if (curNode->data == v)
	{
		if (curNode->left == NULL)
		{
			node *temp = curNode->right;
			delete curNode;
			return temp;
		}
		else if (curNode->right == NULL)
		{
			node *temp = curNode->left;
			delete curNode;
			return temp;
		}
		int succesorVal = minVal(curNode->right);
		curNode->data = succesorVal;
		curNode->right = deleteNode(curNode->right, succesorVal);
		// or
		//		int predecesorVal=maxVal(curNode->left);
		//		curNode->data=predecesorVal;
		//		curNode->left=deleteNode(curNode->left,predecesorVal);
	}
	return curNode;
}

void menu()
{
	cout << "+---------------------------------------------------+\n";
	cout << "|                  BST OPERATIONS                   |" << endl;
	cout << "+---------------------------------------------------+\n";
	cout << "|  1. Insert into BST                               |" << endl;
	cout << "|  2. Search the BST                                |" << endl;
	cout << "|  3. Delete from BST                               |" << endl;
	cout << "+---------------------------------------------------+\n";
	cout << "|  4. Print inorder                                 |" << endl;
	cout << "|  5. Print preorder                                |" << endl;
	cout << "|  6. Print postorder                               |" << endl;
	cout << "+---------------------------------------------------+\n";
	cout << "|  7. Print the max value of tree                   |" << endl;
	cout << "|  8. Print the min value of tree                   |" << endl;
	cout << "|  9. Print the successor of a node                 |" << endl;
	cout << "+---------------------------------------------------+\n";
	cout << "|  10. Print the predecessor of a node              |" << endl;
	cout << "|  11. Exit                                         |" << endl;
	cout << "+---------------------------------------------------+\n";
}

int main()
{
	int op;
	int d;
	while (op < 11)
	{
		menu();
		cout << endl
			 << "Enter your choice: ";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Enter a integer 1:" << endl;
			cin >> d;
			cout << (insert(d) ? "inserted" : "cant insert") << "\n";
			break;
		case 2:
			cout << "Enter the key you want to search : " << endl;
			cin >> d;
			cout << (search(d) ? "found" : "not  found") << "\n";
			break;
		case 3:
			cout << "inorder traversal before deletion :" << endl;
			inorder(root);
			cout << "Enter the key you want to delete : ";
			cin >> d;
			root = deleteNode(root, d);
			cout << endl
				 << "inorder traversal after deletion: " << endl;
			inorder(root);
			break;
		case 4:
			inorder(root);
			cout << endl;
			break;

		case 5:
			preorder(root);
			cout << endl;
			break;

		case 6:
			postOrder(root);
			cout << endl;
			break;

		case 7:
			cout << maxVal(root) << endl;
			break;

		case 8:
			cout << minVal(root) << endl;
			break;
		case 9:
			cout << "Enter an element to find the successor for: ";
			cin >> d;
			cout << successor(d) << endl;
			break;
		case 10:
			cout << "Enter an element to find the predecessor for: ";
			cin >> d;
			cout << predecessor(d) << endl;
			break;
		}
	}
	return 0;
}
