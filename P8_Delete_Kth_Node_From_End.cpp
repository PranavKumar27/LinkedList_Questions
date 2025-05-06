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

// TC --> O(2N)
// SC --> O(3)
Node* deleteKthNode_fromEnd_Sol1(Node* head,int k)
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
    while(temp!=nullptr)
    {
        diff--;
        if(diff==0)
            break;
        temp = temp->next;
    }


    Node* NextNode = temp->next->next;
    Node* delNode = temp->next;
    temp->next = NextNode;
    delete(delNode);
    return head;

}
/*
    Move fast Ptr k places k=2
   fast
    1    2     3      4     5

        fast
    1    2     3      4     5

             fast
    1    2     3      4     5

    Now initial slow at head and move both fast and slow 1 step sequnetially till fast->next!=nullptr

              fast
    1    2     3      4     5
   slow

                     fast
    1    2     3      4     5
       slow

                           fast
    1    2     3      4     5              Here fast->next == null break;
             slow


    Now delete slow->next
    Make connection as slow->next = slow->next->next
    return head

    if k=5 length of list

    fast
    1    2     3      4     5

        fast
    1    2     3      4     5

             fast
    1    2     3      4     5

                    fast
    1    2     3      4     5

                          fast
    1    2     3      4     5

                                fast   Here fast=nullptr
    1    2     3      4     5

    if(fast==nullptr) it means remove first element or head
    Hence newHead = head->next;
          delete(head);
          return newHead;

*/

// TC --> O(N)
// SC -> O(1)
Node* deleteKthNode_fromEnd_Sol2(Node* head,int k)
{
    Node* fast = head;
    for(int i=0;i<k;i++)
        fast  = fast->next;

    if(fast==nullptr)
    {
        Node* delNode = head;
        Node* neweHead = head->next;
        free(delNode);
        return neweHead;
    }

    Node* slow = head;
    while(fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node* delNode = slow->next;
    slow->next = delNode->next;
    free(delNode);
    return head;
}

int main()
{
    cout << "Delete Kth Node from End" << endl;
    vector<int> Arr = { 5,6,9,11,2,3,7};
    int k = 3;
    // Delete Kth Node from End

    Node* head1 = convertArrToSLL(Arr);
    Print_SLL(head1);
    head1 = deleteKthNode_fromEnd_Sol1(head1,7);
    cout << "Using Sol1 After Delete of Kth Node" << endl;
    Print_SLL(head1);


    Node* head2 = convertArrToSLL(Arr);
    head2 = deleteKthNode_fromEnd_Sol2(head2,7);
    cout << "Using Sol2 After Delete of Kth Node" << endl;
    Print_SLL(head2);
    return 0;
}
