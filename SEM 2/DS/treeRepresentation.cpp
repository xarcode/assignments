#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int v)
    {
        this->data = v;
        this->left = NULL;
        this->right = NULL;
    }
};

// create tree
node *buildTree(node *root)
{
    cout << "\nEnter data:";
    int data;
    cin >> data;
    root = new node(data);

    // base case
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the element to the left of " << data << "::";
    root->left = buildTree(root->left);
    cout << "Enter the element to the right of " << data << "::";
    root->right = buildTree(root->right);

    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {   //level completed move to the next level
            cout << endl;
            if (!q.empty())
            {
                //check if queue right or left child node
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->data << " ";
}
void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
int main()
{
    node *root = NULL;

    // creating a tree
    root = buildTree(root);
    //1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1

    cout << "\nPreOrder Traversal:";
    preOrderTraversal(root);
    cout << "\nPostOrder Traversal:";
    postOrderTraversal(root);
    cout << "\nInOrder Traversal:";
    inOrderTraversal(root);
    cout << "\nLevelOrder Traversal:";
    levelOrderTraversal(root);
}