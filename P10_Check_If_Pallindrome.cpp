#include <iostream>
#include <vector>
#include <stack>

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
// TC -> O(2N)
// SC -> O(N)
bool IsPallindrome_Sol1(Node* head)
{
    Node* temp = head;
    stack<int> st;

    while(temp!=nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp!=nullptr)
    {
        if(temp->data!=st.top())
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node* reverse_SLL(Node* head)
{
   if(head==nullptr||head->next==nullptr)
        return head;

   Node* newHead = reverse_SLL(head->next);
   Node* _front = head->next;
   _front->next = head;
   head->next = nullptr;
   return newHead;
}

// TC -> O(N/2) + O(N/2) while + rev +  O(N/2) + O(N/2) while + rev  = O(2N)
// SC -> O(1)
bool IsPallindrome_Sol2(Node* head)
{
    if(head==nullptr||head->next==nullptr)
        return head;

    Node* slow = head;
    Node* fast = head;

    while(fast->next->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast->next==nullptr)
            break;
    }


    Node* RevHead = reverse_SLL(slow->next);

    Print_SLL(RevHead);
    Node* first = head;
    Node* second = RevHead;

    while(second!=nullptr)
    {
       if(first->data!=second->data)
       {
           reverse_SLL(RevHead); // Bring back original state
           return false;
       }

       first = first->next;
       second = second->next;
    }
    reverse_SLL(RevHead); // Bring back original state
    return true;
}
int main()
{
    cout << "IsPallindrome" << endl;
    vector<int> Arr ={1,2,3,2,1};
    Node* head1 = convertArrToSLL(Arr);
    bool res1 = IsPallindrome_Sol1(head1);
    cout << "Using Sol1 Is Pallindrome = " << res1 << endl;

    Node* head2 = convertArrToSLL(Arr);
    bool res2 = IsPallindrome_Sol2(head2);
    cout << "Using Sol2 Is Pallindrome = " << res2 << endl;

    return 0;
}
