#include <iostream>
#include <vector>
#include <map>

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

Node* findNth_Node(Node* head,int x)
{
    int cnt=1;
    Node* temp = head;
    while(temp->next!=head)
    {
        if(cnt==x)
        {
            return temp;
        }
        cnt++;
        temp=temp->next;
    }
    return nullptr;
}

Node* rotate_SLL_By_K(Node* head,int k)
{
    // Step 1: Find length of the SLL and reach the tail and connect tail->next = head;
    Node* tail = head;
    int len = 1;
    if(head==nullptr||head->next==nullptr||k==0)
    {
        return head;
    }

    while(tail->next!=nullptr)
    {
        len++;
        tail = tail->next;
    }

    if(k%len==0)
        return head;
    else
        k=k%len;

    if(tail!=nullptr)
        tail->next = head;


    // Step 2 Need to traverse x distance from head and set it to null and make x+1 distance node as newHead
    int x = len-k;

    Node* temp = head;
    int cnt=1;

    Node* NthNode = findNth_Node(head,x);
    Node* newHead=NthNode->next;
    NthNode->next=nullptr;
    head = newHead;

    return head;

}

int main()
{
    cout << "Challenge : Rotate SLL by K" << endl;
    vector<int> Arr = {1,2,3,4,5};
    int k = 2;
    Node* head = convertArrToSLL(Arr);
    cout << "Before Rotate SLL by K" << endl;
    Print_SLL(head);
    head = rotate_SLL_By_K(head,k);
    cout << "After Rotate SLL by K" << endl;
    Print_SLL(head);

    return 0;
}
