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

// TC --> O(N)
// SC --> O(1)
Node* remove_Duplicates(Node* head)
{
    Node* temp = head;

    while(temp!=nullptr)
    {
        int val = temp->data;
        Node* nextNode = temp->next;
        while(nextNode!=nullptr)
        {
            if(nextNode->data == val)
            {
                Node* delNode = nextNode;
                delete(delNode);
                nextNode = nextNode->next;
            }
            else
                break;
        }
        // Steps Can be same whether Value is repeated or not
        // Works for 1,1,1,2,2 as well as 1,2,2,3,3
        // No special condition needed if nextNode == temp->next above while loop is skipped
        temp->next = nextNode;
        if(nextNode!=nullptr)
            nextNode->prev = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
    cout << "Remove Duplicates from DLL" << endl;
    vector<int> Arr = {1,1,1,2,2,3,4,4,4,5,5,5};
    Node* head = convertArr_to_DLL(Arr);
    print_DLL(head);

    cout << "After Removing Duplicates from DLL" << endl;
    head = remove_Duplicates(head);
    print_DLL(head);

    return 0;
}
