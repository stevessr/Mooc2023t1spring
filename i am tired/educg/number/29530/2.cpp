#include <iostream>
#include <string>
using namespace std;
struct node
{
    int key;
    node *left, *right;
};
node *newNode(int item)
{
    node *temp = new node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}
node *insertNode(node *tree, int item)
{
    if (tree == nullptr)
    {
        return newNode(item);
    }
    else if (tree->right == nullptr)
    {
        node *temp = newNode(item);
        tree->right = temp;
    }
    else
    {
        insertNode(tree->right, item);
    }
    return tree;
}
node *deleteNode(node *tree, int item)
{
    if (tree->key == item)
    {
        node *temp = tree->left;
        tree->left = tree->right;
        delete tree;
        return temp;
    }
    else if (tree->right == nullptr)
    {
        return tree;
    }
    else
    {
        return deleteNode(tree->right, item);
    }
}
string outputNode(node *tree)
{
    if (tree->left == nullptr)
    {
        return to_string(tree->key);
    }
    else
    {
        return outputNode(tree->left) + " " + to_string(tree->key);
    }
}
int main()
{
    node *tree = nullptr;
    int value;
    while (cin >> value && value != -1)
    {
        tree = insertNode(tree, value);
    }
    cin >> value;
    deleteNode(tree, value);
    cout << outputNode(tree);
    return 0;
}
