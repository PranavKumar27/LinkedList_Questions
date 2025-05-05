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

Node* deleteKthNode_fromEnd(Node* head,int k)
{
    // Step1: Count the Nodes;
    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    cout << "cnt=" << cnt << endl;

    int diff = cnt-k;

    cout << "diff=" << diff << endl;
    if(cnt<k)
        return head;
    else if(diff==0)
    {
        Node* delNode = head;
        head=head->next;
        delete(delNode);
        return head;
    }




    temp = head;
    while(temp!=nullptr && diff>1)
    {
        diff--;
        temp = temp->next;
    }


    Node* NextNode = temp->next->next;
    Node* delNode = temp->next;
    temp->next = NextNode;
    delete(delNode);
    return head;

}

int main()
{
    cout << "Delete Kth Node from End" << endl;
    vector<int> Arr = { 5,6,9,11,2,3,7};
    int k = 7;
    // Delete Kth Node from End

    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);
    head = deleteKthNode_fromEnd(head,k);
    cout << "After Delete of Kth Node" << endl;
    Print_SLL(head);
    return 0;
}
