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

void print_vector(vector<int>& V)
{
    for(auto d:V)
        cout << d << " ";
    cout << endl;
}

void sortList_Sol1(Node* head)
{
    if(head==nullptr || head->next == nullptr)
        return;
    map<int,int> Mp;
    int freq,val;
    Node* temp=head;
    while(temp!=nullptr)
    {
        val = temp->data;
        Mp[val]++;
        temp=temp->next;
    }

    temp = head;
    for(auto d:Mp)
    {
        freq = d.second;val=d.first;
        for(int i=0;i<freq;i++)
        {
            temp->data = val;
            temp = temp->next;
        }
    }
}

void sortList_Sol2(Node* head)
{
    Node* ZeroHead=new Node(-1);
    Node* OneHead=new Node(-1);
    Node* TwoHead=new Node(-1);

    Node* zero = ZeroHead;
    Node* one = OneHead;
    Node* two = TwoHead;

    Node* temp = head;
    int val;
    while(temp!=nullptr)
    {
        val = temp->data;
        if(val==0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if(val==1)
        {
            one->next = temp;
            one = temp;
        }
        else if(val==2)
        {
            two->next = temp;
            two = temp;
        }
        temp=temp->next;
    }

    zero->next = (OneHead->next)?OneHead->next:TwoHead->next;
    one->next = TwoHead->next;
    two->next = nullptr;

   // return ZeroHead->next;

}
int main()
{
    cout << "Sort 0,1 and 2" << endl;
    vector<int> Arr = {0,1,2,0,0,2,1,1,2,0};
    //vector<int> Arr = {9,6,5,3,4,5,7,72,3,7,23,-7};

    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);
    cout << "Sort Using Sol1 " << endl;
    sortList_Sol1(head);
    Print_SLL(head);


    cout << "Sort Using Sol2 " << endl;
    sortList_Sol2(head);
    Print_SLL(head);

    return 0;
}
