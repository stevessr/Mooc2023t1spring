#include <iostream>
#include <fstream>
#include <string>

// 定义双链表结点结构
typedef struct _tagDList {
    int data;
    struct _tagDList *pPre, *pNext;
} DLIST;

// 插入结点到链表尾部
void InsertTail(DLIST*& head, DLIST*& tail, int value) {
    // 创建新结点
    DLIST* newNode = new DLIST;
    newNode->data = value;
    newNode->pPre = tail;
    newNode->pNext = nullptr;

    if (tail != nullptr) {
        tail->pNext = newNode;
    } else {
        // 如果链表为空，新结点也是头结点
        head = newNode;
    }

    // 更新尾指针
    tail = newNode;
}

// 删除所有值为num的结点
void DeleteNodes(DLIST*& head, DLIST*& tail, int num) {
    DLIST* current = head;

    while (current != nullptr) {
        if (current->data == num) {
            DLIST* toDelete = current;
            // 移动到下一个结点前先保存
            current = current->pNext;

            // 更新前驱结点的pNext
            if (toDelete->pPre != nullptr) {
                toDelete->pPre->pNext = toDelete->pNext;
            } else {
                // 如果删除的是头结点
                head = toDelete->pNext;
            }

            // 更新后继结点的pPre
            if (toDelete->pNext != nullptr) {
                toDelete->pNext->pPre = toDelete->pPre;
            } else {
                // 如果删除的是尾结点
                tail = toDelete->pPre;
            }

            // 释放被删除结点的内存
            delete toDelete;
        }
        else {
            current = current->pNext;
        }
    }
}

int main() {
    // 打开输入文件
    std::ifstream infile("dlist.in");
    if (!infile.is_open()) {
        std::cerr << "无法打开输入文件 dlist.in" << std::endl;
        return 1;
    }

    int n;
    infile >> n;

    if (n < 3 || n > 10) {
        std::cerr << "n的值必须满足 3 ≤ n ≤ 10" << std::endl;
        infile.close();
        return 1;
    }

    // 初始化链表头和尾指针
    DLIST* head = nullptr;
    DLIST* tail = nullptr;

    // 读取n个数并插入到链表尾部
    for (int i = 0; i < n; ++i) {
        int value;
        infile >> value;
        InsertTail(head, tail, value);
    }
    int num;
    infile >> num;
    infile.close();
    DeleteNodes(head, tail, num);
    std::ofstream outfile("dlist.out");
    if (!outfile.is_open()) {
        std::cerr << "无法打开输出文件 dlist.out" << std::endl;
        DLIST* temp = tail;
        while (temp != nullptr) {
            DLIST* next = temp->pPre;
            delete temp;
            temp = next;
        }
        return 1;
    }
    if (head == nullptr) {
        outfile << "-1";
    }
    else {
        DLIST* current = tail;
        bool first = true;
        while (current != nullptr) {
            if (!first) {
                outfile << " ";
            }
            outfile << current->data;
            first = false;
            current = current->pPre;
        }
    }
    outfile.close();
    DLIST* temp = tail;
    while (temp != nullptr) {
        DLIST* next = temp->pPre;
        delete temp;
        temp = next;
    }

    return 0;
}
