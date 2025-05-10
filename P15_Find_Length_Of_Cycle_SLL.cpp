#include <iostream>
#include <vector>
#include <unordered_map>

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

void Print_SLL_With_Loop(Node* head,int k)
{
    Node* temp=head;
    int cnt = 0;

    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k)
            break;
        cout << temp->data <<  ",";
        temp = temp->next;
    }

    // Now traverse to the endl
    Node* last = temp;
    while(last->next!=temp)
    {
       cout << last->data <<  ",";
       last = last->next;
    }
    cout << last->data <<  ",";
    cout << endl;
}

Node* convert_List_to_A_Cycle_At_K(Node* head,int k)
{
    Node* temp=head;
    int cnt = 0;

    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k)
            break;
        temp = temp->next;
    }

    //cout << "temp->data =" << temp->data << endl;

    // Now traverse to the endl
    Node* last = temp;
    while(last->next!=nullptr)
        last = last->next;

    last->next = temp;
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

// TC --> O(N*2*logN) or O(N*2) if used with timer and O(N*2*LogN) + O(N*2*LogN) without timer
// SC -> O(N)
int lengthOf_Cycle_in_SLL_Sol1(Node* head)
{
    cout << "Using Hashing Algo" << endl;
    Node* temp = head;

    unordered_map<Node*,int> Mp; // Store Node and timer = 1 ,2 ,3 .... increasing

    int t=1;
    while(temp!=nullptr)
    {
        if(Mp.find(temp)!=Mp.end())
        {
            int val = Mp[temp];
            int diff_time = t - val;
            return diff_time;
        }

        Mp[temp]=t++;
        temp = temp->next;
    }

    return 0; // For Linear List

    /*
    Node* last = temp->next;
    int cnt = 1;  // temp moved 1 place so cnt=1
    while(last!=temp)
    {
        cnt++;
        last = last->next;
    }
    return cnt;
    */
}


int findLength(Node* slow,Node* fast)
{
    slow = slow->next;
    int cnt=1;
    while(slow!=fast)
    {
        cnt++;
        slow=slow->next;
    }
    return cnt;
}

int lengthOf_Cycle_in_SLL_Sol2(Node* head)
{
    cout << "Using Tortoise Hare Algo" << endl;
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return findLength(slow,fast) ;
    }

    return 0;
}

int main()
{
    vector<int> Arr = {1,2,3,4,5,6,7,8,9};
    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);
    cout << "Convert a List to A Cycle" << endl;
    head = convert_List_to_A_Cycle_At_K(head,4);
    Print_SLL_With_Loop(head,4);

    int len1 = lengthOf_Cycle_in_SLL_Sol1(head);
    cout << "Using Sol 1 Length of Loop/Cycle in SLL = " << len1 << endl;

    int len2 = lengthOf_Cycle_in_SLL_Sol2(head);
    cout << "Using Sol 2 Length of Loop/Cycle in SLL = " << len2 << endl;


    return 0;
}
