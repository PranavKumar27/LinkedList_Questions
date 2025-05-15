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

// Brute Force- Using Array + Sort
// TC -> O(X) + O(XLogX) for sort + O(X) for convert to SLL where X = N+M N lists and M elements in each
// SC -> O(X) for New List
Node* merge_K_Sorted_SLL_Sol1(vector<Node*>& HeadList)
{
    int n = HeadList.size();
    vector<int> Arr;
    for(int i=0;i<n;i++)
    {
        Node* head = HeadList[i];
        while(head!=nullptr)
        {
            Arr.push_back(head->data);
            head = head->next;
        }
    }

    sort(Arr.begin(),Arr.end());

    return convertArrToSLL(Arr);
}

Node* merge_SLL(Node* head1,Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyHead = new Node(-1);
    Node* tail = dummyHead;
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
            t2 = t2->next;
        }
    }
    Print_SLL(dummyHead);
    if(t1)
        tail->next = t1;
    else
        tail->next = t2;

    //tail->next = nullptr;

    return dummyHead->next;
}


// Better Approach- Using SLL Traversal and Sorted Nature of each List
// TC --> O(X)  where X = N*M
// SC --> O(1)
Node* merge_K_Sorted_SLL_Sol2(vector<Node*>& HeadList)
{
    int n = HeadList.size();
    if(n==1)
        return HeadList[0];

    Node* head1 = HeadList[0];
    for(int i=1;i<n;i++)
    {
        Node* head2 = HeadList[i];

        head1 = merge_SLL(head1,head2);
    }

    return head1;
}


int main()
{
    cout << "Merge K Sorted SLL" << endl;
    vector<int> Arr1={1,7,11,12};
    vector<int> Arr2={2,4,9,10};
    vector<int> Arr3={3,5,6,8};

    Node* head1 = convertArrToSLL(Arr1);
    Node* head3 = convertArrToSLL(Arr3);
    Node* head2 = convertArrToSLL(Arr2);

    vector<Node*> HeadList = {head1,head2,head3};

    Node* MergedHead1 = merge_K_Sorted_SLL_Sol1(HeadList);
    Print_SLL(MergedHead1);


    Node* MergedHead2 = merge_K_Sorted_SLL_Sol2(HeadList);
    Print_SLL(MergedHead2);

    return 0;
}
