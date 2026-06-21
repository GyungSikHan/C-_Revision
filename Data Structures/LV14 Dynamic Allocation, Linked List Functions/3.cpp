struct Node
{
    int data;
    Node* next;
};

int main()
{
    // 🔗 추가 확장이 매우 편리해진다
    Node* head;

    // 3개의 노드를 동적으로 생성하고 연결
    head = new Node();
    head->next = new Node();
    head->next->next = new Node();

    // 데이터 설정
    head->data = 1;
    head->next->data = 2;
    head->next->next->data = 3;

    // 데이터 출력
    std::cout << head->data;                    // 1
    std::cout << head->next->data;              // 2
    std::cout << head->next->next->data;        // 3

    // 🧹 해제는 조립의 역순 (뒤에서부터)
    delete head->next->next;
    head->next->next = nullptr;

    delete head->next;
    head->next = nullptr;

    delete head;
    head = nullptr;

    return 0;
}
