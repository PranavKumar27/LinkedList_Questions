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

int lenOfSLL(Node* head)
{
    int cnt=0;
    Node* temp = head;
    while(temp!=nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// TC --> O(N) for len + O(N/2)
// SC --> O(1)
Node* delete_Mid_of_SLL_Sol1(Node* head)
{
    if(head==nullptr||head->next==nullptr)
        return head;
    int len = lenOfSLL(head);
    int mid = len/2;

    Node* temp = head;
    Node* prevNode = nullptr;
    while(temp!=nullptr)
    {
        if(mid==0)
            break;
        mid--;
        prevNode = temp;
        temp = temp->next;
    }
    if(temp!=nullptr)
    {
        prevNode->next = temp->next;
        delete(temp);
    }
    return head;
}

// TC --> O(N/2)
// SC --> O(1)
Node* delete_Mid_of_SLL_Sol2(Node* head)
{
    if(head==nullptr||head->next==nullptr)
    {
        if(head!=nullptr)
            head = head->next;
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prevNode = nullptr;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        prevNode = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prevNode->next = slow->next;
    delete(slow);
    return head;
}
int main()
{
    cout << "Delete Middle of SLL" << endl;
    vector<int> Arr = {1,2,3,4,5,6};
    Node* head = convertArrayToList(Arr);
    print_SLL(head);

    head = delete_Mid_of_SLL_Sol1(head);
    print_SLL(head);

    head = delete_Mid_of_SLL_Sol2(head);
    print_SLL(head);

    return 0;
}
