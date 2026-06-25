#include<iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

public:
    LinkedList()
        : mHead(), mTail() 
    {

    }
    ~LinkedList()
    {
        clear();
    }

    void Add(T data)
    {
        if(mHead == nullptr)
        {
            mHead = new Node();
            mHead->data = data;
            mHead->next = nullptr;
            mTail = mHead;
            return;
        }

        mTail->next = new Node();
        mTail->next->data = data;
        mTail->next->next = nullptr;
        mTail = mTail->next;
    }

    void pop()
    {
        if(mHead == nullptr)
            return;

        Node* node = mHead;
        mHead = node->next;

        delete node;
        node = nullptr;
    }

    void clear()
    {
        while (mHead != nullptr)
            pop();    
    }

    void print()
    {
        Node* node = mHead;
        while (node != nullptr)
        {
            cout<<node->data<<" ";
            node = node->next;
        }
        
    }
private:
    Node* mHead;
    Node* mTail;
};

int main()
{
    int len{};
    cin>>len;

    LinkedList<char> list;
    for (size_t i = 0; i < len; i++)
    {
        char c{};
        cin>>c;
        list.Add(c);
    }

    list.print();
    
}