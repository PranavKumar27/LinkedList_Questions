#include <iostream>
#include <vector>

using namespace std;

/*
    Linked List = 1 5 9
    Add 1
                  1 6 0

    Step 1 : Reverse List
    Step 2 : Add     9  5  1
                     1
                     -------
                     0  6  1
            carry -> 1  0  0
    Step 3: Reverse List
                     1 6 0  Ans



*/
class Node
{
public:
    int val;
    Node* next;
    Node(int data)
    {
       val=data;
       next = nullptr;
    }

    Node(int data,Node* nextNode)
    {
        val = data;
        next = nextNode;
    }
};

Node* convertArrayToList(vector<int>& Arr)
{
    int n = Arr.size();
    if(Arr.size()==0)
        return nullptr;
    Node* head = new Node(Arr[0]);
    Node* PrevNode = head;

    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(Arr[i]);
        PrevNode->next = newNode;
        PrevNode = newNode;
    }
    return head;
}

void print_SLL(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << temp->val << " , ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverse_SLL(Node* head)
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

// TC --> O(N) rev +O(N) traversal +O(N) rev = O(3N)
// SC -> O(1)
Node* Add_1_to_List(Node* head)
{
    // step 1: Reverse List
    head = reverse_SLL(head);
    cout << "After Stage 1 Rev" << endl;
    print_SLL(head);
    // Step 2: Add 1 to list
    Node* temp = head;
    int data,carry=1; // carry is 1 since 1 is added
    while(temp!=nullptr)
    {
        data = temp->val;
        /*
        if(temp==head)
        {
            data = data + 1 + carry; // Not needed since carry =1
        }
        else
        */
        data = data + carry;

        int new_val = data%10;
        carry = data/10;
        cout << "new_val=" << new_val << endl;
        temp->val = new_val;
        temp = temp->next;
        if(carry==0)
            break;

        print_SLL(head);
    }

    cout << "After Stage 2 Add 1" << endl;
    print_SLL(head);

    head = reverse_SLL(head);
    cout << "After Stage 2 Rev" << endl;
    print_SLL(head);

    if(carry!=0)
    {
        Node* newNode = new Node(carry,head);
        head = newNode;
        cout << "After Stage 2 Add 1 IF carry > 0 Do not reverse" << endl;
        print_SLL(head);
        //return head;
    }

    return head;
}

int find_Carry(Node* head)
{
    if(head==nullptr)
        return 1;

    int carry = find_Carry(head->next);
    if(carry>0)
    {
        int newval = head->val+carry;
        head->val = newval%10;
        carry = newval/10;
    }
    return carry;
}
// TC -> O(N)
// SC -> O(N) for Recursion
Node* Add_1_to_List_Sol2(Node* head)
{
    int carry = find_Carry(head);
    if(carry==1)
    {
        Node* newNode = new Node(carry,head);
        head = newNode;
        cout << "Add New Node Since Carry=1" << endl;
        print_SLL(head);
    }
    return head;
}

int main()
{
    cout << "Add 1 to List" << endl;
    vector<int> Arr = {9,9,9};
    Node* head = convertArrayToList(Arr);
    print_SLL(head);

    head= Add_1_to_List_Sol2(head);

    print_SLL(head);





    return 0;
}
