#include <bits/stdc++.h>
using namespace std;

/*
                    Node1--->Node2--->Node3--->Node4--->nullptr
Node Index:           0        1        2        3         
InBetween Index:  0       1         2       3         4
*/

struct Node {
    int data;
    struct Node* next;
} *first = nullptr;

struct Node* createList(int arr[], int size) 
{
    struct Node *last = nullptr, *p = nullptr;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < size; i++)
    {
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = arr[i];
        p->next = nullptr;
        last->next = p;
        last = p;
    }

    return first;
}

void displayList(struct Node* node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void displayListRecursive(struct Node* node) 
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    displayListRecursive(node->next);
}

void releaseResources(struct Node* node)
{
    struct Node* tmp = nullptr;

    while (node != nullptr)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}

int length(struct Node* node)
{
    int count = 0;
    while (node != nullptr) {
        count++;
        node = node->next;
    }
    return count;
}

bool isSorted(struct Node* node) 
{
    struct Node* p = node->next;
    while (p != nullptr)
    {
        if (p->data < node->data)
            return false;
        p = p->next;
        node = node->next;
    }
    return true;
}

void insertSorted(struct Node* node, int data) 
{
    struct Node* q = nullptr;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nullptr;

    if (data < node->data) {
        newNode->next = first;
        first = newNode;
    }
    else {
        while (node != nullptr && node->data < data) {
            q = node;
            node = node->next;
        }

        newNode->next = node;
        q->next = newNode;
    }
}

void insertNode(struct Node* node, int data, int pos) 
{
    struct Node *newNode;
    int i = 1;

    if (pos < 0 || pos > length(node))
        return;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nullptr;

    if (pos == 0) {
        newNode->next = first;
        first = newNode;
    }
    else {
        while (i < pos) {
            node = node->next;
            i++;
        }
        newNode->next = node->next;
        node->next = newNode;
    }
}

int deleteNode(struct Node* node, int pos) 
{
    struct Node* q = first;
    int data, i = 0;

    if (pos < 0 || pos > length(node) -1)
        return -1;

    if (pos == 0) {
        data = node->data;
        first = first->next;
        free(q);
    }
    else {
        while (i < pos - 1) {
            node = node->next;
            i++;
        }
        data = node->next->data;
        q = node->next;
        node->next = node->next->next;
        free(q);
    }

    return data;
}

int maxValue(struct Node* node)
{
    int max = node->data;
    while (node != nullptr) {
        if (max < node->data) max = node->data;
        node = node->next;
    }
    return max;
}

int minValue(struct Node* node)
{
    int min = node->data;
    while (node != nullptr) {
        if (min > node->data) min = node->data;
        node = node->next;
    }
    return min;
}

int sumValue(struct Node* node)
{
    int total = 0;
    while (node != nullptr) {
        total += node->data;
        node = node->next;
    }
    return total;
}

struct Node* search(struct Node* node, int searchData)
{
    while (node != nullptr) {
        if (node->data == searchData) return node;
        node = node->next;
    }
    return nullptr;
}

void mergeList(struct Node* node1, struct Node* node2)
{
    while (node1->next != nullptr) node1 = node1->next;

    node1->next = node2;
}

int main()
{
    int arr[] = { 1,2,3,4 };
    createList(arr, 4);
    
    displayList(first);
    releaseResources(first);
    return 0;
}
