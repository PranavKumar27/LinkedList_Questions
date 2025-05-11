#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Notes in the Copy

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

// TC --> O(2N+m*K) for store in stack and Traverse, m are pairs
// SC --> O(3)
Node* Reverse_K_elements_Group(Node* head,int k)
{
    Node* temp = head;

    while(temp!=nullptr)
    {
        // Count K Nodes
        int cnt = 0;
        stack<int> St;
        Node* temp1 = temp;
        while(temp1!=nullptr && cnt!=k)
        {
            St.push(temp1->data);
            temp1 = temp1->next;
            cnt++;
        }

        if(cnt==k)
        {
            while(cnt>0 && temp!=nullptr) // O(m*K)
            {
                temp->data = St.top();
                St.pop();
                temp=temp->next;
                cnt--;
            }
        }
        else
            temp=temp->next;

    }
    return head;
}

Node* reverse_SLL(Node* head)
{
    Node* temp = head;
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* newHead = reverse_SLL(head->next);
    Node* frontNode = head->next;
    frontNode->next = head;
    head->next = nullptr;
    return newHead;
}

// TC --> O(2N) for Rev and Traverse
// SC --> O(1)
Node* Reverse_K_elements_Group_Sol2(Node* head,int k)
{
    Node* temp = head;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;

    while(temp!=nullptr)
    {
        // Finding Kth Node
        int cnt = 1;
        Node* KthNode = temp;
        while(KthNode!=nullptr && cnt!=k)
        {
            cnt++;
            KthNode=KthNode->next;
        }
        if(KthNode!=nullptr)
        {
            nextNode = KthNode->next;
            KthNode->next = nullptr;
            Node* newHead = reverse_SLL(temp);
            if(temp==head)
                head=newHead;
            else
               prevNode->next = newHead;

            prevNode = temp;
            temp = nextNode;
        }
        else
        {
            prevNode->next = temp;
            temp = KthNode;
        }
    }
    return head;
}

int main()
{
    cout << "Reverse SLL for K Groups Only" << endl;
    vector<int> Arr = {1,2,3,4,5,6,7,8,9,10,11};
    int k=3;
    Node* head = convertArrToSLL(Arr);
    cout << "List ->" << endl;
    Print_SLL(head);

    head = Reverse_K_elements_Group_Sol2(head,k);
    Print_SLL(head);
    return 0;
}
