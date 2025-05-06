#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }

    Node(int val,Node* ptr)
    {
        this->data = data;
        next = ptr;
    }
};

Node* convertArrToSLL(vector<int>& Arr)
{
    Node* head = new Node(Arr[0]);
    Node* mover = head; // Points to last node

    for(int i=1;i<Arr.size();i++)
    {
        Node* temp = new Node(Arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void Print_SLL(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << temp->data <<  ",";
        temp = temp->next;
    }
    cout << endl;
}

// TC --> O(2N)
// SC --> O(N)
Node* reverse_SLL_Sol1(Node* head)
{
    Node* temp = head;
    stack<int> st;

    while(temp!=nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp!=nullptr && !st.empty())
    {
        int val = st.top();
        st.pop();
        temp->data = val;
        temp = temp->next;
    }

    return head;
}

// TC --> O(N)
// SC --> O(1)
Node* reverse_SLL_Sol2(Node* head)
{
    Node* prevNode = nullptr;
    Node* temp = head;
    Node* nextNode = nullptr;

    while(temp!=nullptr)
    {
        nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }
    return prevNode;
}

Node* reverse_SLL_Sol3(Node* head)
{
    if(head==nullptr||head->next == nullptr)
        return head;

    Node* newHead = reverse_SLL_Sol3(head->next);
    Node* front_ = head->next;
    front_->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    cout << "Reverse SLL" << endl;
    vector<int> Arr = {1,2,3,4,5};

    Node* head1 = convertArrToSLL(Arr);
    Print_SLL(head1);
    cout << "Using Sol1 Reverse:" << endl;
    reverse_SLL_Sol1(head1);
    Print_SLL(head1);


    Node* head2 = convertArrToSLL(Arr);
    Print_SLL(head2);
    cout << "Using Sol2 Iterative Reverse:" << endl;
    head2=reverse_SLL_Sol2(head2);
    Print_SLL(head2);


    Node* head3 = convertArrToSLL(Arr);
    Print_SLL(head3);
    cout << "Using Sol3 Recursion Reverse:" << endl;
    head3=reverse_SLL_Sol3(head3);
    Print_SLL(head3);

    return 0;
}
