#include <iostream>
#include <list>
using namespace std;


struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void AddNode(int data)
{
    if (head == nullptr)
    {
        // 🏠 첫번째 추가할 해준다.
        head = new Node;
        head->data = data;
        head->next = nullptr;

        tail = head;
    }
    else
    {
        // 🔗 제일 마지막 노드에 추가를 해준다.
        tail->next = new Node;
        tail->next->data = data;
        tail->next->next = nullptr;

        tail = tail->next;
    }
}

void RemoveNode(int data)
{
    if (head == nullptr)
        return;
    if (head->data == data)
    {
        Node* deleteNode = head;
        head = head->next;
        if (deleteNode == tail)
            tail = head;

        delete deleteNode;
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr)
    {
	    if (curr->data == data)
	    {
            prev->next = curr->next;
            if (tail == curr)
                tail = prev;
            delete curr;
            return;
	    }

        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    AddNode(3);
    AddNode(4);
    AddNode(5);

    // while, for 문을 활용한 linked list 순회
    Node* p = head;
    while (true)
    {
        if (p == nullptr)
            break;
    
        std::cout << p->data;
        p = p->next;
    }
    cout << endl;

    // 🔄 for문을 이용한 순회
    for (Node* p = head; p != nullptr; p = p->next)
    {
        std::cout << p->data;
    }
    cout << endl;

    RemoveNode(3);
    RemoveNode(5);
    RemoveNode(4);

    for (Node* p = head; p != nullptr; p = p->next)
    {
        std::cout << p->data;
    }
    cout << endl;
    return 0;
}
