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

// TC --> O(N*N)
// SC --> O(N) for storing ans
vector<pair<int,int>> PairSumInDLL_Sol1(Node* head,int k)
{
    vector<pair<int,int>> Ans;
    for(Node* temp1=head;temp1!=nullptr;temp1=temp1->next)
    {
        int sum = temp1->data;
        for(Node* temp2=temp1->next;temp2!=nullptr;temp2=temp2->next)
        {
            if(sum+temp2->data == k)
            {
                Ans.push_back({temp1->data,temp2->data});
            }
            if(sum+temp2->data>k) // More than Required Sum, Since Sorted Moving Ahead increases sum further so break
                break;
        }
    }
    return Ans;
}


// TC --> O(N) for finding tail + O(N) for traversing
// SC --> O(N) for storing ans
// ----->left % % % % %  right<----
vector<pair<int,int>> PairSumInDLL_Sol2(Node* head,int k)
{
    cout << __FUNCTION__ << endl;
    vector<pair<int,int>> Ans;
    Node* right = head;
    // Finding Tail Node Here
    while(right->next!=nullptr)
        right = right->next;

    Node* left = head;
    while(left->data<right->data)
    {
        int sum = left->data + right->data;
        if(sum==k)
        {
            Ans.push_back({left->data,right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum>k)
            right = right->prev;
        else if(sum<k)
            left = left->next;
    }
    return Ans;
}

void print_v_pi(vector<pair<int,int>> Vp)
{
    for(auto d:Vp)
    {
        cout << " { " << d.first << " , " << d.second << " } " << endl;
    }
}

int main()
{
    int k=5;
    cout << "Pair Sum in DLL k = " << k << endl;
    vector<int> Arr = {1,2,3,4,5,9};
    Node* head = convertArr_to_DLL(Arr);
    print_DLL(head);
    cout << "List of Pairs" << endl;
    vector<pair<int,int>> Ans1 = PairSumInDLL_Sol1(head,k);
    cout << "Using Sol1 :" << endl;
    print_v_pi(Ans1);

    vector<pair<int,int>> Ans2 = PairSumInDLL_Sol2(head,k);
    cout << "Using Sol2 :" << endl;
    print_v_pi(Ans2);
    return 0;
}
