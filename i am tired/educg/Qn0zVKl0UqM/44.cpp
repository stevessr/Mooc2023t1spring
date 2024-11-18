#include <iostream>
#include <iomanip>
using namespace std;

struct BSTree
{
    int value;
    BSTree *left, *right, *parent;
};
BSTree *find_max_bstree(BSTree *tree);
static BSTree *CreateNode(int value, BSTree *left, BSTree *right, BSTree *parent)
{
    BSTree *p;
    if ((p = (BSTree *)malloc(sizeof(BSTree))) == NULL)
        return NULL;
    p->value = value;
    p->left = left;
    p->right = right;
    p->parent = parent;
    return p;
}
BSTree *insert_bstree(BSTree *tree, int value)
{
    if (tree == NULL)
    {
        tree = CreateNode(value, NULL, NULL, NULL);
    }
    else if (value < tree->value)
    {
        tree->left = insert_bstree(tree->left, value);
    }
    else if (value > tree->value)
    {
        tree->right = insert_bstree(tree->right, value);
    }
    return tree;
}
BSTree *find_bstree(BSTree *tree, int value)
{
    if (tree == NULL || tree->value == value)
    {
        return tree;
    }
    if (value < tree->value)
    {
        return find_bstree(tree->left, value);
    }
    if (value > tree->value)
    {
        return find_bstree(tree->right, value);
    }
    return nullptr;
}
BSTree *find_range_bstree(BSTree *tree, int small, int big)
{
    if (tree->value >= small && tree->value <= big)
    {
        return tree;
    }
    if (tree->value < small)
    {
        return find_range_bstree(tree->right, small, big);
    }
    if (tree->value > big)
    {
        return find_range_bstree(tree->left, small, big);
    }
    return nullptr;
}
BSTree *delete_bstree(BSTree *tree, int value)
{
    if (value == tree->value)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }
        else if (tree->left == NULL)
        {
            BSTree *temp = tree;
            tree = tree->right;
            free(temp);
            return tree;
        }
        else if (tree->right == NULL)
        {
            BSTree *temp = tree;
            tree = tree->left;
            free(temp);
            return tree;
        }
        else
        {
            BSTree *temp = find_max_bstree(tree->left);
            tree->value = temp->value;
            tree->left = delete_bstree(tree->left, temp->value);
            return tree;
        }
    }
    else if (value < tree->value)
    {
        tree->left = delete_bstree(tree->left, value);
    }
    else if (value > tree->value)
    {
        tree->right = delete_bstree(tree->right, value);
    }
    return tree;
}
BSTree *find_max_bstree(BSTree *tree)
{
    if (tree == NULL || tree->right == NULL)
    {
        return tree;
    }
    return find_max_bstree(tree->right);
}
BSTree *find_min_bstree(BSTree *tree)
{
    if (tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    return find_min_bstree(tree->left);
}
void print_bstree(BSTree *tree, int value, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)
        {
            cout <<setw(4)<<right<< tree->value;
        }
        else
        {
            cout << tree->value << " is " << value << "'s " << (direction == 1 ? "right child" : "left child") << endl;
        }
    }
}
void print_full_bstree(BSTree * tree){
    if(tree == NULL){
        return;
    }
    print_bstree(tree,tree->value,0);
    print_full_bstree(tree->left);
    print_full_bstree(tree->right);
}

int main()
{
    int i;
    cin >> i;
    BSTree *root = nullptr;
    while (i != -1)
    {
        root = insert_bstree(root, i);
        cin >> i;
    }
    cin>>i;
    root = delete_bstree(root,i);
    print_full_bstree(root);
    return 0;
}
