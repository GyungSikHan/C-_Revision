struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node node;  // 스택에 생성된 노드

    // 동적으로 노드 생성
    Node* pp = new Node;
    pp->data = 3;

    delete pp;  // 메모리 해제

    return 0;
}
