#include <iostream>
using namespace std;

namespace Homework
{
    class queue
    {
    private:
        struct Node
        {
            int data;
            Node* next;
        };
    public:
        queue() : mHead(), mTail(){}
        ~queue(){}

        void push(int data)
        {
            if(!mHead)
            {
                mHead = new Node;
                mHead->data = data;
                mHead->next = nullptr;
                mTail = mHead;
                return;
            }

            mTail->next = new Node;
            mTail->next->data = data;
            mTail->next->next = nullptr;
            mTail = mTail->next;
        }

        void pop()
        {
            if(!mHead)
                return;
            
            Node* deleteNode = mHead;
            mHead = mHead->next;

            delete deleteNode;
            deleteNode = nullptr;
        }

        void clear()
        {
            while (mHead != nullptr)
                pop();
        }

        void Print()
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
    
}


int main()
{
    Homework::queue qu;
    int input{};
    cin>>input;

    for(int i = 0; i < input; i++)
    {
        char c{};
        int data{};

        cin>>c>>data;
        
        if(c == 'E')
            qu.push(data);
        else   
            qu.pop();
    }

    qu.Print();
}