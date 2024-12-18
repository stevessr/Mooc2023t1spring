#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
    int key;
    node *next;
};

node *newNode(int item)
{
    node *temp = new node;
    temp->key = item;
    temp->next = nullptr;
    return temp;
}

node *insertNode(node *head, int item)
{
    if (head == nullptr)
        return newNode(item);

    node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode(item);
    return head;
}

// 删除链表中指定值的节点
node *deleteNode(node *head, int item)
{
    if (head == nullptr)
        return head;

    if (head->key == item)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node *current = head;
    while (current->next != nullptr && current->next->key != item)
    {
        current = current->next;
    }

    if (current->next != nullptr)
    {
        node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}

string outputNode(node *head)
{
    if (head == nullptr)
        return "";

    string result = "";
    node *temp = head;
    while (temp != nullptr)
    {
        result += to_string(temp->key);
        if (temp->next != nullptr)
            result += " ";
        temp = temp->next;
    }
    return result;
}

int main()
{
    node *head = nullptr;
    int value;

    while (cin >> value && value != -1)
    {
        head = insertNode(head, value);
    }

    cin >> value;
    head = deleteNode(head, value);

    string str = outputNode(head);
    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}
