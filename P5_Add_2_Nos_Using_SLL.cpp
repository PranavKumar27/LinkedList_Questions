#include <iostream>
#include <vector>

using namespace std;

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

Node* AddTwoList_Sol1(Node* head1,Node* head2)
{
    Node* tmp1 = head1;
    Node* tmp2 = head2;
    vector<int> res;
    int carry = 0;
    int v=0;
    while(tmp1!=nullptr && tmp2!=nullptr)
    {
        int v1 = tmp1->val;
        int v2 = tmp2->val;

        int s = v1+v2+carry;
        carry = s/10;
        v = s%10;
        res.push_back(v);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;

    }

    while(tmp1!=nullptr)
    {
        int v1 = tmp1->val;
        int s = v1+carry;
        carry = s/10;
        v = s%10;
        res.push_back(v);
        tmp1 = tmp1->next;
    }

    while(tmp2!=nullptr)
    {
        int v2 = tmp2->val;
        int s = v2+carry;
        carry = s/10;
        v = s%10;
        res.push_back(v);
        tmp2 = tmp2->next;
    }

    if(carry!=0)
      res.push_back(carry);

    return convertArrayToList(res);
}

Node* AddTwoList_Sol2(Node* head1,Node* head2)
{
    Node* tmp1 = head1;
    Node* tmp2 = head2;
    Node* sumHead = nullptr;
    Node* PrevNode = nullptr;
    vector<int> res;
    int carry = 0;
    int v=0;
    while(tmp1!=nullptr && tmp2!=nullptr)
    {
        int v1 = tmp1->val;
        int v2 = tmp2->val;

        int s = v1+v2+carry;
        carry = s/10;
        v = s%10;
        Node* newNode = new Node(v);
        if(sumHead==nullptr)
        {
            sumHead = newNode;
            PrevNode = newNode;
        }
        else
        {
            PrevNode->next = newNode;
            PrevNode = newNode;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;

    }

    while(tmp1!=nullptr)
    {
        int v1 = tmp1->val;
        int s = v1+carry;
        carry = s/10;
        v = s%10;
        Node* newNode = new Node(v);
        if(sumHead==nullptr)
        {
            sumHead = newNode;
            PrevNode = newNode;
        }
        else
        {
            PrevNode->next = newNode;
            PrevNode = newNode;
        }
        tmp1 = tmp1->next;
    }

    while(tmp2!=nullptr)
    {
        int v2 = tmp2->val;
        int s = v2+carry;
        carry = s/10;
        v = s%10;
        Node* newNode = new Node(v);
        if(sumHead==nullptr)
        {
            sumHead = newNode;
            PrevNode = newNode;
        }
        else
        {
            PrevNode->next = newNode;
            PrevNode = newNode;
        }
        tmp2 = tmp2->next;
    }

    if(carry!=0)
    {
        Node* newNode = new Node(carry);
        if(sumHead==nullptr)
        {
            sumHead = newNode;
            PrevNode = newNode;
        }
        else
        {
            PrevNode->next = newNode;
            PrevNode = newNode;
        }
    }

    return sumHead;
}

int main()
{
    cout << "Add 2 Nos in SLL" << endl;

    vector<int> Arr1;
    vector<int> Arr2 = {5,7,9};

    Node* head1 = convertArrayToList(Arr1);
    Node* head2 = convertArrayToList(Arr2);

    print_SLL(head1);
    print_SLL(head2);

    //Node* sumHead1 = AddTwoList_Sol1(head1,head2);

    //print_SLL(sumHead1);

    Node* sumHead2 = AddTwoList_Sol2(head1,head2);

    print_SLL(sumHead2);

    return 0;
}
