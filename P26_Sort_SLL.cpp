#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Note : Whenever We need to create a new List, Always create a dummy Node for clean implementation

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

Node* sort_SLL_Sol1(Node* head)
{
    Node* temp = head;
    vector<int> T_Arr;
    while(temp!=nullptr)
    {
        T_Arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(T_Arr.begin(),T_Arr.end());

    int j=0;
    temp=head;
    while(temp!=nullptr)
    {
        temp->data = T_Arr[j++];
        temp = temp->next;
    }
    return head;
}

Node* merge_2_SLL(Node* head1,Node* head2)
{
    Node* t1=head1;
    Node* t2 = head2;

    Node* dummyhead = new Node(-1);
    Node* tail = dummyhead;
    int v1,v2;
    while(t1!=nullptr && t2!=nullptr)
    {
        v1 = t1->data;
        v2 = t2->data;

        if(v1<v2)
        {
            tail->next = t1;
            tail = t1;
            t1 = t1->next;
        }
        else
        {
            tail->next = t2;
            tail = t2;
            t2=t2->next;
        }
    }
    if(t1)
        tail->next = t1;
    else
        tail->next = t2;

    return dummyhead->next;
}

Node* sort_SLL_Sol2(Node* head)
{
    cout << __FUNCTION__ << endl;
    Print_SLL(head);
    if(head==nullptr || head->next==nullptr)
        return head;

    // Find Len of SLL
    int len = 1;
    Node* temp = head;
    while(temp!=nullptr)
    {
        len++;
        temp = temp->next;
    }
    int mid = len/2;
    cout << "mid=" << mid << endl;
    // List-1  = 0     to mid
    // List-2  = mid+1 to n


    // Forming List-1
    Node* list1=head;
    Node* list2=nullptr;
    temp=head;
    int c_1=0;
    while(temp!=nullptr)
    {
        c_1++;
        if(c_1==mid)
            break;
        temp=temp->next;
    }

    if(c_1==mid)
    {
        list2 = temp->next;
        temp->next = nullptr;
    }

    temp = list2;
    while(temp!=nullptr)
    {
        temp=temp->next;
    }

    if(temp!=nullptr)
        temp->next = nullptr;

    list1 =sort_SLL_Sol2(list1);
    list2 =sort_SLL_Sol2(list2);

    Node* l3=merge_2_SLL(list1,list2);
    return l3;
}


// Using Tortoise and Hare Algo Modified with fast = fast->next;
// If element is 1,2
/*      s                 s                 s
        4 5 2 1  --->   4 5 2 1   --->  4 5 2 1
        f                   f                   f

    mid = 2,  s  <---- incorrect mid

    Mid = 1

    Solve as
        s                 s
        4 5 2 1  --->   4 5 2 1   --->  f->next == null
          f                   f             return s

    s= 1  as mid Hence correct

*/
Node* findMid(Node* head)
{
    cout << __FUNCTION__ << endl;
    if(head==nullptr||head->next==nullptr)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* sort_SLL_Sol3(Node* head)
{
    cout << __FUNCTION__ << endl;
    Print_SLL(head);
    if(head==nullptr || head->next==nullptr)
        return head;


    // Find Middle of the List Using Tortoise and Hare

    Node* mid = findMid(head);

    Node* list2 = mid->next;
    mid->next = nullptr;
    Node* list1 = head;

    list1 =sort_SLL_Sol3(list1);
    list2 =sort_SLL_Sol3(list2);

    Node* l3=merge_2_SLL(list1,list2);
    return l3;
}

int main()
{
    cout << "Sorting SLL " << endl;
    vector<int> Arr = {21,4,2,12,3,17,1,5,2};
    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);

    head = sort_SLL_Sol1(head);
    cout << "Using Sol 1 -> After Sort" << endl;
    Print_SLL(head);


    head = sort_SLL_Sol2(head);
    cout << "Using Sol 2 -> After Sort" << endl;
    Print_SLL(head);

    head = sort_SLL_Sol3(head);
    cout << "Using Sol 3 -> After Sort" << endl;
    Print_SLL(head);
    return 0;
}
