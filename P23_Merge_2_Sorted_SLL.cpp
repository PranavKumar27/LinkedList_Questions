#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Notes in the Copy

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

int findLenOf_SLL(Node* head)
{
    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// TC --> O(N1)+O(N2) for Traversal +O(N1+N2* log(N1+N2))  for Sort + O(N1+N2) for Making List
// SC --> O(N1)+O(N2) for Arr + O(N1+N2) for Making new List

Node* mergeSorted_SLL_Sol1(Node* head1,Node* head2)
{
    cout << __FUNCTION__ << endl;
    vector<int> Arr;
    Node* temp1 = head1;
    while(temp1!=nullptr)
    {
        Arr.push_back(temp1->data);
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while(temp2!=nullptr)
    {
        Arr.push_back(temp2->data);
        temp2 = temp2->next;
    }

    sort(Arr.begin(),Arr.end());

    return convertArrToSLL(Arr);

}

// TC --> O(N)
// SC --> O(1)
Node* mergeSorted_SLL_Sol2(Node* head1,Node* head2)
{
    cout << __FUNCTION__ << endl;
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dummyHead = new Node(-1);
    Node* temp = dummyHead;
    int v1,v2;
    while(t1!=nullptr && t2!=nullptr)
    {
        v1 = t1->data;
        v2 = t2->data;

        if(v1<v2)
        {
            temp->next = t1;
            temp = t1;
            t1=t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2=t2->next;
        }
    }

    if(t1==nullptr)
    {
        temp->next = t2;
    }
    if(t2==nullptr)
    {
        temp->next = t1;
    }
    return dummyHead->next;
}


int main()
{
    cout << "Merge Two Sorted SLL" << endl;
    vector<int> Arr1 = {2,4,8,10};
    vector<int> Arr2 = {1,3,3,6,11,14};

    Node* head1 = convertArrToSLL(Arr1);
    Node* head2 = convertArrToSLL(Arr2);

    cout << "SLL-1 -> ";
    Print_SLL(head1);
    cout << "SLL-2 -> ";
    Print_SLL(head2);

    Node* MergeHead1 = mergeSorted_SLL_Sol1(head1,head2);
    cout << "Using Sol1 Merged SLL -> ";
    Print_SLL(MergeHead1);


    Node* MergeHead2 = mergeSorted_SLL_Sol2(head1,head2);
    cout << "Using Sol2 Merged SLL -> ";
    Print_SLL(MergeHead2);

    return 0;
}
