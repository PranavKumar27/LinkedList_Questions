#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* child;
    Node(int d)
    {
        val=d;
        next=nullptr;
        child=nullptr;
    }

    Node(int d,Node* right,Node* below)
    {
        val = d;
        next = right;
        child = below;
    }
};

Node* convert_Arr_to_SLL(vector<int>& Arr)
{
    int n = Arr.size();

    Node* head = new Node(Arr[0]);
    Node* prevNode = head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(Arr[i]);
        prevNode->child = newNode;
        prevNode = newNode;
    }
    return head;
}
Node* convert_Arr_to_2D_SLL(vector<int>& Arr)
{
    vector<int> v1 = {Arr[0]};
    vector<int> v2 = {Arr[1],Arr[2]};
    vector<int> v3 = {Arr[3],Arr[4],Arr[5],Arr[6]};
    vector<int> v4 = {Arr[7],Arr[8]};
    vector<int> v5 = {Arr[9],Arr[10],Arr[11]};

    Node* head1 = convert_Arr_to_SLL(v1);
    Node* head2 = convert_Arr_to_SLL(v2);
    Node* head3 = convert_Arr_to_SLL(v3);
    Node* head4 = convert_Arr_to_SLL(v4);
    Node* head5 = convert_Arr_to_SLL(v5);

    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;

    return head1;
}

Node* print_2D_SLL(Node* head)
{
    Node* temp1 = head;
    while(temp1!=nullptr)
    {
        Node* temp2 =  temp1;
        while(temp2!=nullptr)
        {
            cout << temp2->val << ",";
            temp2 = temp2->child;
        }
        temp1 = temp1->next;
    }
    cout << endl;
}

vector<int> convert_2D_SLL_to_Arr(Node* head)
{
    vector<int> Arr;
    Node* temp1 = head;
    while(temp1!=nullptr)
    {
        Node* temp2 =  temp1;
        while(temp2!=nullptr)
        {
            Arr.push_back(temp2->val);
            temp2 = temp2->child;
        }
        temp1 = temp1->next;
    }
    return Arr;
}
void print_Arr(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}
// TC --> O(X) + X*Log(X) + O(X) where X = N*M
// SC --> O(X)
Node* flatten_2D_SLL(Node* head)
{
    vector<int> List_Arr = convert_2D_SLL_to_Arr(head);

    sort(List_Arr.begin(),List_Arr.end());

    Node* newHead = convert_Arr_to_2D_SLL(List_Arr);

    return newHead;

}



Node* merge_2_SLL(Node* head1,Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;

    Node* head = new Node(-1);
    Node* temp=head;
    int v1,v2;
    while(t1!=nullptr && t2!=nullptr)
    {
        v1 = t1->val;
        v2 = t2->val;

        if(v1<v2)
        {
            temp->child = t1;
            temp = t1;
            t1=t1->child;
        }
        else
        {
            temp->child = t2;
            temp = t2;
            t2 = t2->child;
        }
        temp->next = nullptr;
    }

    if(t1)
        temp->child = t1;
    else
        temp->child = t2;

    //cout << "After Merge" << endl;
    //print_2D_SLL(head);
    return head->child;
}

// TC --> N*O(X)  where X = N+M
// SC --> O(N)  where N is size of Horizontal SLL and M is the size of vertical SLL
Node* flatten_2D_SLL_Sol2(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* head2 = flatten_2D_SLL_Sol2(head->next);
    Node* newHead = merge_2_SLL(head,head2);
    return newHead;
}



int main()
{
    cout << "Flatten 2D SLL" << endl;
    vector<int> Arr = {3,2,10,1,7,11,12,4,9,5,6,8};
    Node* head = convert_Arr_to_2D_SLL(Arr);
    print_2D_SLL(head);

    cout << "Using Sol1 After Flattening Sorted SLL" << endl;
    Node* newHead = flatten_2D_SLL(head);
    print_2D_SLL(newHead);


    cout << "Using Sol2 After Flattening Sorted SLL" << endl;
    Node* newHead2 = flatten_2D_SLL_Sol2(head);
    print_2D_SLL(newHead2);

    return 0;
}
