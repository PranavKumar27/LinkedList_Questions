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

void Print_SLL_With_Loop(Node* head,int k)
{
    Node* temp=head;
    int cnt = 0;

    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k)
            break;
        cout << temp->data <<  ",";
        temp = temp->next;
    }

    // Now traverse to the endl
    Node* last = temp;
    while(last->next!=temp)
    {
       cout << last->data <<  ",";
       last = last->next;
    }
    cout << last->data <<  ",";
    cout << endl;
}

Node* convert_List_to_A_Cycle_At_K(Node* head,int k)
{
    Node* temp=head;
    int cnt = 0;

    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k)
            break;
        temp = temp->next;
    }

    // Now traverse to the endl
    Node* last = temp;
    while(last->next!=nullptr)
        last = last->next;

    last->next = temp;
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
// TC --> O(N*2*logN)
// SC --> O(N)
Node* start_Of_Cycle_Sol1(Node* head)
{
    map<Node*,int> Mp;
    Node* temp = head;

    while(temp!=nullptr)
    {
        if(Mp.find(temp)!=Mp.end())
            return temp;

        Mp[temp]++;
        temp = temp->next;
    }
    return nullptr;
}

// This Algo is doen in 2 steps
//1.)Detect a cycle and
//2.)If cycle start slow from head and move slow and fast one step till they meet,
//Meeting point will be start of cycle
// TC --> O(N+N/2)
// SC --> O(1)

Node* start_Of_Cycle_Sol2(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast=fast->next->next;

        if(slow==fast) // A cycle Detected
        {
            slow = head;
            while(slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int main()
{
    vector<int> Arr = {1,2,3,4,5,6,7,8,9};
    Node* head = convertArrToSLL(Arr);
    head = convert_List_to_A_Cycle_At_K(head,4);
    Print_SLL_With_Loop(head,4);
    cout << "Start of Loop" << endl;

    Node* res1 = start_Of_Cycle_Sol1(head);
    if(res1!=nullptr)
        cout << "Using Sol1 Start of Cycle At Node = " << res1->data << endl;

    Node* res2 = start_Of_Cycle_Sol2(head);
    if(res2!=nullptr)
        cout << "Using Sol2 Start of Cycle At Node = " << res2->data << endl;

    return 0;
}
