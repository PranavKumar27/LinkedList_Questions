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

// TC --> O(N) + O(N/2)
// SC --> O(1)
Node* mid_Of_SLL_Sol1(Node* head)
{
    int len = findLenOf_SLL(head);

    Node* temp = head;
    int k = (len/2)+1;
    while(temp!=nullptr)
    {
        k--;
        if(k==0)
            break;
        temp=temp->next;
    }
    cout << "mid=" << temp->data << endl;
    return temp;
}

// Tortoise and Hare Algo
// TC --> O(N/2)
// SC --> O(1)
Node* mid_Of_SLL_Sol2(Node* head)
{
    Node* tortoise = head;
    Node* hare = head;

    while(hare!=nullptr && hare->next!=nullptr)
    {
        //cout << "hare=" << hare << " tortoise=" << tortoise << endl;
        if(hare->next!=nullptr)
            hare = hare->next->next;
        tortoise= tortoise->next;
    }
    //cout << "mid=" << tortoise->data << endl;
    return tortoise;
}

int main()
{
    cout << "Middle of Linked List" << endl;
    vector<int> Arr = {1,2,3,4,5,6};

    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);

    Node* mid = mid_Of_SLL_Sol2(head);
    cout << "mid = " << mid->data << endl;

    return 0;
}
