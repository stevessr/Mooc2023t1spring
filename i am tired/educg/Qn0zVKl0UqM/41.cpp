#include <iostream>
#include <fstream>
#include <string>
typedef struct _tagDList
{
    int data;
    struct _tagDList *pPre, *pNext;
} DLIST;
void InsertHead(DLIST *&head, int value)
{
    DLIST *newNode = new DLIST;
    newNode->data = value;
    newNode->pPre = nullptr;
    newNode->pNext = head;
    if (head != nullptr)
    {
        head->pPre = newNode;
    }
    head = newNode;
}
bool DeleteNode(DLIST *&head, int num)
{
    DLIST *current = head;
    while (current != nullptr)
    {
        if (current->data == num)
        {
            if (current == head)
            {
                head = current->pNext;
                if (head != nullptr)
                {
                    head->pPre = nullptr;
                }
            }
            else
            {
                if (current->pPre != nullptr)
                {
                    current->pPre->pNext = current->pNext;
                }
                if (current->pNext != nullptr)
                {
                    current->pNext->pPre = current->pPre;
                }
            }
            delete current;
            return true; 
        }
        current = current->pNext;
    }

    return false;
}

int main()
{
    std::ifstream infile("dlist.in");
    if (!infile.is_open())
    {
        std::cerr << "无法打开输入文件 dlist.in" << std::endl;
        return 1;
    }

    int n;
    infile >> n;
    n -= 1;
    if (n < 3 || n > 10)
    {
        std::cerr << "n的值必须满足 3 ≤ n ≤ 10" << std::endl;
        infile.close();
        return 1;
    }
    DLIST *head = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int value;
        infile >> value;
        InsertHead(head, value);
    }
    int num;
    infile >> num;
    infile.close();
    DeleteNode(head, num);
    std::ofstream outfile("dlist.out");
    if (!outfile.is_open())
    {
        std::cerr << "无法打开输出文件 dlist.out" << std::endl;
        DLIST *temp = head;
        while (temp != nullptr)
        {
            DLIST *next = temp->pNext;
            delete temp;
            temp = next;
        }
        return 1;
    }
    if (head == nullptr)
    {
        outfile << "-1";
    }
    else
    {
        DLIST *current = head;
        bool first = true;
        while (current != nullptr)
        {
            if (!first)
            {
                outfile << " ";
            }
            outfile << current->data;
            first = false;
            current = current->pNext;
        }
    }
    outfile.close();
    DLIST *temp = head;
    while (temp != nullptr)
    {
        DLIST *next = temp->pNext;
        delete temp;
        temp = next;
    }
    return 0;
}
