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
        cout << temp->data <<  ",";
        temp = temp->next;
    }
    cout << endl;
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

Node* deleteAtHead(Node* head)
{
    if(head==nullptr)
        return nullptr;

    Node*temp = head;
    head=head->next;
    delete(temp);
    return head;
}

Node* InsertAtHead(Node* head,int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node* InsertAtTail(Node* head,int val)
{
    if(head==nullptr)
        return new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr)
    {
        temp =  temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* deleteAtTail(Node* head)
{
    if(head==nullptr)
        return nullptr;

    Node* temp = head;
    Node* prev=nullptr;
    while(temp->next!=nullptr)
    {
        prev = temp;
        temp=temp->next;
    }

    prev->next = temp->next;
    delete(temp);
    return head;
}

Node* deleteAtIndex(Node* head,int k)
{
    if(head==nullptr)
        return nullptr;

    if(k==1)
    {
        return deleteAtHead(head);
    }

    int lenofSLL = LengthOfSLL(head);
    if(k==lenofSLL)
    {
        return deleteAtTail(head);
    }
    else if(k>lenofSLL)
    {
        return head;
    }

    Node*temp = head;
    Node*prev = nullptr;
    int cnt = 0;
    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k)
        {
           prev->next = temp->next;
           delete(temp);
           break;
        }
        prev = temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteAtValue(Node* head,int val)
{
    if(head==nullptr)
        return head;

    if(head->data == val)
    {
        return deleteAtHead(head);
    }
    Node* prev = nullptr;
    Node* temp = head;

    while(temp!=nullptr)
    {
        if(temp->data == val)
        {
            prev->next = temp->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;

    }
    return head;
}

Node* InsertAtIndex(Node* head,int k,int val)
{
    if(head==nullptr)
        return new Node(val);

    if(k==1)
    {
        return InsertAtHead(head,val);
    }

    Node* temp = head;
    Node* prev = nullptr;

    int cnt = 0;
    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k)
        {
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;

    }
    if(cnt+1 == k)
    {
        InsertAtTail(head,val);
    }

    return head;
}
int main()
{
    cout << "Singly Linked List" << endl;

    vector<int> Arr = {1,2,3,4,5,6,7,8,9,10};

    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);

    cout << "Len of SLL =" << LengthOfSLL(head) << endl;

    cout << "Is 5 Present in SLL =" << searchInSLL(head,3) << endl;

    head = deleteAtHead(head);
    cout << "SLL after deleteAtHead--> " ;
    Print_SLL(head);

    head = deleteAtTail(head);
    cout << "SLL after deleteAtTail--> " ;
    Print_SLL(head);

    head = deleteAtIndex(head,2);
    cout << "SLL after deleteAtIndex 2 --> " ;
    Print_SLL(head);

    head = deleteAtValue(head,5);
    cout << "SLL after deleteAtValue 1 --> " ;
    Print_SLL(head);

    head = InsertAtHead(head,1);
    cout << "SLL after InsertAtHead  --> " ;
    Print_SLL(head);


    head = InsertAtTail(head,10);
    cout << "SLL after InsertAtTail  --> " ;
    Print_SLL(head);

    head = InsertAtIndex(head,3,3);
    cout << "SLL after InsertAtIndex  --> " ;
    Print_SLL(head);

    return 0;
}
