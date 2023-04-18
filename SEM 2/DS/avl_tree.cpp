#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

Node *root = NULL;


int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Search
Node *search(Node *curNode, int sv)
{
	if (curNode == NULL)
		return NULL;
	if (curNode->key == sv)
	{
		return curNode;
	}
	else if (curNode->key < sv)
		return search(curNode->right, sv);
	else
		return search(curNode->left, sv);
}

bool search(int sv)
{
	Node *serNode = search(root, sv);
	if (serNode == NULL)
		return false;
	if (serNode->key == sv)
		return true;
	return false;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool insert(int v)
{
	root = insert(root, v);
	// cout<<"se";
	return search(v);
}

Node * minValueNode(Node* node)
{
    Node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
//            free(temp);
			delete temp;
        }
        else
        {

            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// MAX and MIN

int maxVal(Node *curNode)
{
	if (curNode == NULL)
		return -1;
	if (curNode->right == NULL)
		return curNode->key;
	return maxVal(curNode->right);
}

int minVal(Node *curNode)
{
	if (curNode == NULL)
		return -1;
	if (curNode->left == NULL)
		return curNode->key;
	return minVal(curNode->left);
}

// Traversals
// inorder

void inorder(Node *curNode)
{
	if (curNode != NULL)
	{
		inorder(curNode->left);
		cout << curNode->key << " ";
		inorder(curNode->right);
	}
}
void preorder(Node *curNode)
{
	if (curNode != NULL)
	{
		cout << curNode->key << " ";
		preorder(curNode->left);
		preorder(curNode->right);
	}
}
void postOrder(Node *curNode)
{
	if (curNode != NULL)
	{
		postOrder(curNode->left);
		postOrder(curNode->right);
		cout << curNode->key << " ";
	}
}

// Predecessor and Sucessor

int predecessor(int v)
{
	Node *serNode = search(root, v);
	if(serNode)
		return maxVal(serNode->left);
	return -1;
}
int successor(int v)
{
	Node *serNode = search(root, v);
	if(serNode)
		return minVal(serNode->right);
	return -1;
}



void menu()
{
	cout << "+---------------------------------------------------+\n";
	cout << "|                  BST OPERATIONS                   |" << endl;
	cout << "+---------------------------------------------------+\n";
	cout << "|  1. Insert into AVL Tree                          |" << endl;
	cout << "|  2. Search the AVL Tree                           |" << endl;
	cout << "|  3. Delete from AVL Tree                          |" << endl;
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
			cout << "\nEnter the key you want to delete : ";
			cin >> d;
			root = deleteNode(root, d);
			cout << endl
				 << "inorder traversal after deletion: " << endl;
			inorder(root);
			cout << endl;
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
