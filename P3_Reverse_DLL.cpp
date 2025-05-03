#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }

    Node(int val,Node* left,Node* right)
    {
        data = val;
        next = right;
        prev = left;
    }
};

Node* convert_Arr_to_DLL(vector<int>& Arr)
{
    if(Arr.size()<1)
    {
        return new Node(Arr[0]);
    }
    int val = Arr[0];
    Node* head = new Node(val);
    int n = Arr.size();
    Node* prev = head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(Arr[i],prev,nullptr);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}

void print_DLL(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* reverseDLL_Sol1(Node* head)
{
    cout << __FUNCTION__ << " Using stack" << endl;
    // Using stack
    stack<int> S;
    Node* temp = head;
    while(temp!=nullptr)
    {
        S.push(temp->data);
        temp=temp->next;
    }

    temp = head;
    while(!S.empty())
    {
        temp->data = S.top();
        S.pop();
        temp = temp->next;
    }
    return head;
}
Node* reverseDLL_Sol2(Node* head)
{
    cout << __FUNCTION__ << " Using Link Changes" << endl;
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* current = head;
    Node* last = nullptr;
    while(current!=nullptr)
    {
        last = current->prev;
        current->prev = current->next;
        current->next = last;

        current = current->prev;
    }
    return last->prev;
}

int main()
{
    cout << "<----Doubly Linked List---->" << endl;
    vector<int> Arr = {4,12,30,70};
    Node* head = convert_Arr_to_DLL(Arr);
    print_DLL(head);

    head = reverseDLL_Sol1(head);
    print_DLL(head);

    head = reverseDLL_Sol2(head);
    print_DLL(head);

    return 0;
}
