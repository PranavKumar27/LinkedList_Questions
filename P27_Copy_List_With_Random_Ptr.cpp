#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* R_ptr;
    Node(int d)
    {
        val = d;
        next = R_ptr = nullptr;
    }
    Node(int d,Node* right,Node* random_ptr)
    {
        val = d;
        next = right;
        R_ptr = random_ptr;
    }
};

Node* Make_A_List(vector<int>& Arr)
{
    unordered_map<int,Node*> Mp; // <val and R_ptr;

    int n = Arr.size();

    Node* dummyhead = new Node(-1);
    Node* tail = dummyhead;
    for(int i=0;i<n;i++)
    {
        Node* newNode = new Node(Arr[i]);
        tail->next = newNode;
        tail = newNode;
        Mp[Arr[i]] = newNode;
    }

    Node* temp = dummyhead->next;
    while(temp!=nullptr)
    {
       int d = temp->val;
       cout << "d=" << d << endl;
       if(d%2==0)
       {
           if(temp->next!=nullptr && temp->next->next!=nullptr)
                temp->R_ptr = temp->next->next;
           else if(temp->next!=nullptr)
                temp->R_ptr = temp->next;
            else
                temp->R_ptr = temp ;
       }
       else if(d%3==0)
       {
            temp->R_ptr = dummyhead;
       }
       else
       {
           temp->R_ptr = nullptr;
       }

       cout << "temp->R_ptr=" << temp->R_ptr << endl;
       temp = temp->next;
    }
    return dummyhead->next;
}

void Print_SLL(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << temp->val <<  ",";
        int v = (temp!=nullptr && temp->R_ptr!=nullptr)?temp->R_ptr->val:0;
        cout << "Random PTR Data = " << v << endl;
        cout << "Random PTR = " << temp->R_ptr << endl;
        temp = temp->next;
    }
    cout << endl;
}
// TC --> O(N) + O(N) = O(2N)
// SC --> O(N) + O(N)
Node* clone_Random_Ptr_List_Sol1(Node* head)
{
    unordered_map<Node*,Node*> Mp; // <original Node,New Node>

    // First Create all Node and put in the Map
    Node* temp = head;
    while(temp!=nullptr)
    {
        Node* newNode = new Node(temp->val);
        Mp[temp]=newNode;
        temp = temp->next;
    }

    // Now retrieve each data from map and make original R_ptr same as new List R_ptr

    temp = head;
    while(temp!=nullptr)
    {
        Node* copyNode = Mp[temp];

        copyNode->next = Mp[temp->next];

        copyNode->R_ptr = Mp[temp->R_ptr];

        temp = temp->next;
    }
    return Mp[head];
}

Node* insert_Copy_Nodes(Node* head)
{
    Node* temp = head;
    Node* nextNode = nullptr;
    // Step 1 : Insert Copy Nodes and connect next
    while(temp!=nullptr)
    {
        Node* CopyNode = new Node(temp->val);
        CopyNode->next = temp->next;
        temp->next = CopyNode;
        temp = temp->next->next;
    }
    return head;
}

Node* Connect_Random_Ptr_in_Nodes(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        Node* CopyNode = temp->next;
        Node* random = temp->R_ptr;
        if(random!=nullptr)
            CopyNode->R_ptr = random->next;
        else
            CopyNode->R_ptr = nullptr;

        temp = temp->next->next;
    }
    return head;
}

Node* deep_Copy_Nodes(Node* head)
{
    Node* temp = head;
    Node* dummyHead = new Node(-1);
    Node* tail = dummyHead;

    while(temp!=nullptr)
    {
        // Make New Copy List Here
        tail->next = temp->next;
        tail = temp->next;

        // Restore Original List
        temp->next =  temp->next->next;
        temp = temp->next;

    }
    return dummyHead->next;
}

// TC --> O(3N)
// SC --> O(N)
Node* clone_Random_Ptr_List_Sol2(Node* head)
{
    // Step 1 : Insert Copy Nodes and connect next
    head=insert_Copy_Nodes(head);
    // Step 2: Point the Random pointers
    head=Connect_Random_Ptr_in_Nodes(head);
    // Step 3: Create New List dummyHead and Connect the next
    return deep_Copy_Nodes(head);
}

int main()
{

    cout << "Copy List With Random PTR" << endl;

    vector<int> Arr = {7,12,11,4,10,1};
    Node* head = Make_A_List(Arr);
    Print_SLL(head);

    Node* Copy_Head = clone_Random_Ptr_List_Sol1(head);
    cout << "Using Sol 1 Details of Copy Head" << endl;
    Print_SLL(Copy_Head);

    Node* Copy_Head2 = clone_Random_Ptr_List_Sol2(head);
    cout << "Using Sol 2 Details of Copy Head" << endl;
    Print_SLL(Copy_Head2);


    return 0;
}
