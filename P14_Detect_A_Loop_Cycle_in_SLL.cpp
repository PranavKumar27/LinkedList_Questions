#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Explanation in Notes 
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

// TC --> O(N) for Unordered Map  or ON*LogN) for Map
// SC --> O(N)
Node* DetectLoop_in_SLL_Sol1(Node* head)
{
    unordered_map<Node*,int> Mp; // Hashing to keep track of visited Nodes
    Node* temp = head;

    while(temp!=nullptr && (Mp.find(temp)==Mp.end()))
    {
        Mp[temp]++;
        temp = temp->next;
    }

    //cout << "Loop has No loop temp=" << temp << endl;

    if(temp==nullptr)
    {
        cout << "Couldn't detect Loop " << endl;
        return nullptr;
    }
    else if(Mp.find(temp)!=Mp.end())
    {
        //cout << "detected Loop at " << temp->data << endl;
        return temp;
    }
}

// TC --> O(N)
// SC --> O(1)
bool DetectLoop_in_SLL_Sol2(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return true;
    }
    return false;
}
int main()
{
    vector<int> Arr = {1,2,3,4,5,6,7,8,9};
    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);
    cout << "Convert a List to A Cycle" << endl;
    head = convert_List_to_A_Cycle_At_K(head,4);
    Print_SLL_With_Loop(head,4);

    Node* LoopNode = DetectLoop_in_SLL_Sol1(head);
    if(LoopNode!=nullptr)
        cout << "LoopNode =" << LoopNode->data << endl;
    else
        cout << "No Loop Found" << endl;
    bool ans1 = (LoopNode!=nullptr)?true:false;
    cout << "Is Cycle Present Using Sol1 =" << ans1 << endl;

    bool ans2 = DetectLoop_in_SLL_Sol2(head);
    cout << "Is Cycle Present Using Sol2 =" << ans2 << endl;
    return 0;
}
