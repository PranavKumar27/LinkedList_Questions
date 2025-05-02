#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }

    Node(int val,Node* left,Node* right)
    {
        data = val;
        next = right;
        prev = left;
    }
};

Node* convert_Arr_to_DLL(vector<int>& Arr)
{
    if(Arr.size()<1)
    {
        return new Node(Arr[0]);
    }
    int val = Arr[0];
    Node* head = new Node(val);
    int n = Arr.size();
    Node* prev = head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(Arr[i],prev,nullptr);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}

void print_DLL(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteHead(Node* head)
{
    if(head==nullptr||head->next == nullptr)
    {
        delete(head);
        return nullptr;
    }


    Node* prevNode = head;
    head = head->next;

    head->prev = nullptr;
    prevNode->next = nullptr;
    delete(prevNode);
    return head;
}

Node* deleteTail(Node* head)
{
    if(head==nullptr||head->next==nullptr)
    {
        delete(head);
        return nullptr;
    }

    Node*temp = head;

    while(temp->next!=nullptr)
    {
        temp = temp->next;
    }
    Node* PrevNode = temp->prev;
    PrevNode->next = nullptr;
    temp->prev = nullptr;
    delete(temp);
    return head;
}
Node* delete_AtINDEX_k(Node* head,int k)
{
    if(head==nullptr)
        return nullptr;

    if(k==1)
        return deleteHead(head);

    int cnt= 0 ;
    Node* temp = head;
    while(temp->next!=nullptr)
    {
        cnt++;
        if(cnt == k)
        {
           Node* PrevNode = temp->prev;
           Node* NextNode = temp->next;

           temp->prev = nullptr;
           temp->next = nullptr;
           delete(temp);

           PrevNode->next = NextNode;
           NextNode->prev = PrevNode;
           break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    cout << "<----Doubly Linked List---->" << endl;
    vector<int> Arr = {3,1,2,7};
    Node* head = convert_Arr_to_DLL(Arr);
    print_DLL(head);
    //head = deleteHead(head);
    print_DLL(head);

    //head = deleteTail(head);
    print_DLL(head);
    head = delete_AtINDEX_k(head,3);
    print_DLL(head);
    return 0;
}
