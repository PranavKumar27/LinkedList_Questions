#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* prev,*next;
    Node(int n)
    {
        data = n;
        prev = next = nullptr;
    }
    Node(int n,Node* PrevNode,Node* NextNode)
    {
        data = n;
        prev = PrevNode;
        next = NextNode;
    }
};

Node* convertArr_to_DLL(vector<int>& Arr)
{
    int n = Arr.size();
    Node* newNode = new Node(Arr[0]);
    Node* head = newNode;
    Node* prevNode = newNode;

    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(Arr[i],prevNode,nullptr);
        prevNode->next = newNode;
        prevNode = newNode;
    }
    return head;
}

void print_DLL(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << temp->data << " , ";
        temp = temp->next;
    }
    cout << endl;
}

Node* delete_All_Occurenses_Of_K(Node* head,int k)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        if(temp->data==k && temp==head)
        {
            // Delete at head
            head = head->next;
            head->prev = nullptr;
            delete(temp);
            temp = head;
            continue;
        }
        else if(temp->data==k)
        {
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            prevNode->next = nextNode;
            if(nextNode!=nullptr)
                nextNode->prev = prevNode;
            delete(temp);
            temp = nextNode;
        }
        else
            temp = temp->next;

    }
    return head;
}

int main()
{
    int k = 10;
    cout << "Delete All Occurences of key = " << k << endl;
    vector<int> Arr = {10,1,2,3,10,8,5,6,7,9,10,11,13,16,10};
    Node* head = convertArr_to_DLL(Arr);
    print_DLL(head);

    head = delete_All_Occurenses_Of_K(head,k);
    cout << "After delete All occurences of k = " << k << endl;
    print_DLL(head);
    return 0;
}
