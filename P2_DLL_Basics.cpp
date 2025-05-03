#include <iostream>
#include <vector>

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

Node* deleteHead(Node* head)
{
    if(head==nullptr||head->next == nullptr)
    {
        delete(head);
        return nullptr;
    }


    Node* prevNode = head;
    head = head->next;

    head->prev = nullptr;
    prevNode->next = nullptr;
    delete(prevNode);
    return head;
}

Node* deleteTail(Node* head)
{
    if(head==nullptr||head->next==nullptr)
    {
        delete(head);
        return nullptr;
    }

    Node*temp = head;

    while(temp->next!=nullptr)
    {
        temp = temp->next;
    }
    Node* PrevNode = temp->prev;
    PrevNode->next = nullptr;
    temp->prev = nullptr;
    delete(temp);
    return head;
}
Node* delete_AtINDEX_k(Node* head,int k)
{
    if(head==nullptr)
        return nullptr;

    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr)
    {
        cnt++;
        if(cnt == k)
        {
           break;
        }
        temp = temp->next;
    }

    Node* PrevNode = temp->prev;
    Node* NextNode = temp->next;

    if(PrevNode==nullptr && NextNode == nullptr)
    {
        free(temp);
        return nullptr;
    }
    else if(PrevNode==nullptr && NextNode != nullptr)
    {
        return deleteHead(head);
    }
    else if(PrevNode!=nullptr && NextNode == nullptr)
    {
        return deleteTail(head);
    }
    else
    {
        PrevNode->next = NextNode;
        NextNode->prev = PrevNode;

        temp->prev = nullptr;
        temp->next = nullptr;

        delete(temp);
    }
    return head;
}




Node* delete_Val(Node* head,int val)
{
    if(head==nullptr)
        return nullptr;

    if(val==head->data)
        return deleteHead(head);

    Node* temp = head;
    while(temp->next!=nullptr)
    {
        if(temp->data == val)
        {
           Node* PrevNode = temp->prev;
           Node* NextNode = temp->next;

           temp->prev = nullptr;
           temp->next = nullptr;
           delete(temp);

           PrevNode->next = NextNode;
           if(NextNode!=nullptr)
               NextNode->prev = PrevNode;
           break;
        }
        temp = temp->next;
    }
    return head;
}
void delete_Node(Node* Temp)
{
    if(Temp==nullptr)
        return;
    Node* PrevNode = Temp->prev;
    Node* NextNode = Temp->next;

    PrevNode->next = NextNode;
    if(NextNode!=nullptr)
        NextNode->prev = PrevNode;

    Temp->prev = nullptr;
    Temp->next = nullptr;
    delete(Temp);
}

Node* InsertBeforeHead(Node* head,int val)
{
    Node* newHead = new Node(val,nullptr,head);
    head->prev = newHead;
    return newHead;
}

Node* InsertBeforeTail(Node* head,int val)
{
    if(head->next == nullptr) // Single Element Linked List
        return InsertBeforeHead(head,val);

    Node* temp = head;
    while(temp->next!=nullptr)
    {
        temp = temp->next;
    }
    // At the tail Index so temp -> current tail
    Node* PrevNode = temp->prev;
    Node* newNode = new Node(val,PrevNode,temp);

    PrevNode->next = newNode;
    temp->prev = newNode;
    return head;
}

Node* InsertAtKthNode(Node* head,int k,int val)
{
    if(head==nullptr)
    {
        if(k==1)
            return new Node(val);
        else
            return nullptr;
    }

    if(k==1)
    {
        return InsertBeforeHead(head,val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp->next!=nullptr)
    {
        cnt++;
        if(cnt==k)
        {
            break;
        }
        temp = temp->next;
    }

    Node* PrevNode = temp->prev;
    Node* NextNode = temp->next;

    if(NextNode==nullptr)
    {
        if(cnt==k)
            return InsertBeforeTail(head,val);
        else
            return head;
    }
    else
    {
        Node* newNode = new Node(val,PrevNode,temp);
        PrevNode->next = newNode;
        temp->prev = newNode;
    }
    return head;

}

void InsertBeforeNode(Node* Temp,int val)
{
    Node* PrevNode = Temp->prev;
    Node* newNode = new Node(val,PrevNode,Temp);

    PrevNode->next = newNode;
    Temp->prev = newNode;
}
int main()
{
    cout << "<----Doubly Linked List---->" << endl;
    vector<int> Arr = {4,12,30,70};
    Node* head = convert_Arr_to_DLL(Arr);
    print_DLL(head);
    //head = deleteHead(head);
    //print_DLL(head);

    //head = deleteTail(head);
    //print_DLL(head);
    head = delete_AtINDEX_k(head,4);
    print_DLL(head);

    head = delete_Val(head,12);
    print_DLL(head);

    delete_Node(head->next);
    print_DLL(head);

    head=InsertBeforeHead(head,4);
    print_DLL(head);

    head = InsertBeforeTail(head,70);
    print_DLL(head);

    head=InsertAtKthNode(head,2,12);
    print_DLL(head);

    head=InsertAtKthNode(head,8,30);
    print_DLL(head);

    InsertBeforeNode(head->next->next,100);
    print_DLL(head);
    return 0;
}
