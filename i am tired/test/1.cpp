#include <iostream>
using namespace std;
struct node
{
    int val;
    node *pre;
    node *next;
    char * point;
};
int main()
{
    node tree = {.val = 1, .pre = nullptr, .next = nullptr,.point = nullptr};
    node *p = &tree;
    node *q = new node({1, p, nullptr,"fuckme"});
    return 0;
}
