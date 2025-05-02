#include <iostream>
#include <vector>

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

int LengthOfSLL(Node* head)
{
    int cnt =0;
    Node* temp = head;
    while(temp!=nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void Print_SLL(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << "val=" << temp->data <<  ",";
        temp = temp->next;
    }
}

bool searchInSLL(Node*head,int x)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        if(temp->data == x)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    cout << "Singly Linked List" << endl;

    vector<int> Arr = {1,2,3,4};

    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);

    cout << "Len of SLL =" << LengthOfSLL(head) << endl;

    cout << "Is 5 Present in SLL =" << searchInSLL(head,3) << endl;
    return 0;
}
