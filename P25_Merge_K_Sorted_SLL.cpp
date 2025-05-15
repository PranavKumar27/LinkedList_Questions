#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

// Note : Whenever We need to create a new List, Always create a dummy Node for clean implementation

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

// Brute Force- Using Array + Sort
// TC -> O(X) + O(XLogX) for sort + O(X) for convert to SLL where X = N+M N lists and M elements in each
// SC -> O(X) for New List
Node* merge_K_Sorted_SLL_Sol1(vector<Node*>& HeadList)
{
    int n = HeadList.size();
    vector<int> Arr;
    for(int i=0;i<n;i++)
    {
        Node* head = HeadList[i];
        while(head!=nullptr)
        {
            Arr.push_back(head->data);
            head = head->next;
        }
    }

    sort(Arr.begin(),Arr.end());

    return convertArrToSLL(Arr);
}

Node* merge_SLL(Node* head1,Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyHead = new Node(-1);
    Node* tail = dummyHead;
    int v1,v2;

    while(t1!=nullptr && t2!=nullptr)
    {
        v1 = t1->data;
        v2 = t2->data;

        if(v1<v2)
        {
            tail->next = t1;
            tail = t1;
            t1 = t1->next;
        }
        else
        {
            tail->next = t2;
            tail = t2;
            t2 = t2->next;
        }
    }
    Print_SLL(dummyHead);
    if(t1)
        tail->next = t1;
    else
        tail->next = t2;

    //tail->next = nullptr;

    return dummyHead->next;
}


// Better Approach- Using SLL Traversal and Sorted Nature of each List
// TC --> O(N*K*K)
//First and Second List TC = O(2N)
//Merged and third List TC = O(2N) + O(N) = O(3N)
//Merged and Fourth List TC = O(3N) + O(N) = O(4N)
// Total TC = O(2N) + O(3N) + O(4N) ..... O(kN)
// Hence Formula as O( N * (1 + 2+ 3 ......k))
//                  O( N * k*(k+1)/2)
//                  O(N*K*K)
//                  ~~ O( N^3 ) if k=N

// SC --> O(1)
Node* merge_K_Sorted_SLL_Sol2(vector<Node*>& HeadList)
{
    int n = HeadList.size();
    if(n==1)
        return HeadList[0];

    Node* head1 = HeadList[0];
    for(int i=1;i<n;i++)
    {
        Node* head2 = HeadList[i];

        head1 = merge_SLL(head1,head2);
    }

    return head1;
}



// TC --> O(K*LogK) + O(K*N*3LogK)
// SC --> O(K) for Heap
typedef pair<int,Node*> PairOfVal_Node;
// Using Min Heap
Node* merge_K_Sorted_SLL_Sol3(vector<Node*>& HeadList)
{
    priority_queue<PairOfVal_Node,vector<PairOfVal_Node>,greater<PairOfVal_Node>> pq;

    Node* dummyHead = new Node(-1);
    Node* temp = dummyHead;
    int k = HeadList.size();
    for(int i=0;i<k;i++) // O(K*LogK)
    {
        if(HeadList[i]!=nullptr)
        {
            pq.push({HeadList[i]->data,HeadList[i]});
        }

    }
    while(!pq.empty())  // O(K*N)
    {
        PairOfVal_Node MinNode = pq.top();  // O(LogK)  Each Operation in Heap Take O(Size of Heap)
        int v = MinNode.first;
        Node* ptr = MinNode.second;
        pq.pop();                           // O(LogK)

        if(ptr!=nullptr)
        {
            //cout << " Min Node = " << v << endl;
            temp->next = ptr;
            temp = ptr;
        }


        if(ptr!=nullptr && ptr->next!=nullptr)
        {
            int v = ptr->next->data;
            //cout << "Pushing in PQ next of Min Node = " << v << endl;
            pq.push({v,ptr->next});          // O(LogK)
        }
    }
    return dummyHead->next;
}

class Compare
{
   public:
       bool operator()(Node* a, Node* b) {
         if(a->data > b->data)
            return true;
         else
            return false;
    }
};

Node* merge_K_Sorted_SLL_Sol4(vector<Node*>& NodeList)
{
    cout << __FUNCTION__ << endl;
    priority_queue<Node*,vector<Node*>,Compare> heap; // Min Heap

    for(int i=0;i<NodeList.size();i++)
    {
        if(NodeList[i]!=nullptr)
            heap.push(NodeList[i]);
    }

    Node* dummyHead = new Node(-1);
    Node* tail = dummyHead;
    while(!heap.empty())
    {
        Node* TopNode = heap.top();
        //cout << "Top =" << TopNode->val << ",";
        heap.pop();

        if(tail!=nullptr)
            tail->next = TopNode;

        tail = TopNode;

        if(TopNode!=nullptr && TopNode->next!=nullptr)
            heap.push(TopNode->next);
    }
    return dummyHead->next;
}

int main()
{
    cout << "Merge K Sorted SLL" << endl;
    vector<int> Arr1={1,7,11,12};
    vector<int> Arr2={2,4,9,10};
    vector<int> Arr3={3,5,6,8};

    Node* head1 = convertArrToSLL(Arr1);
    Node* head3 = convertArrToSLL(Arr3);
    Node* head2 = convertArrToSLL(Arr2);

    vector<Node*> HeadList1 = {head1,head2,head3};

    vector<int> Arr4={1,7,11,12};
    vector<int> Arr5={2,4,9,10};
    vector<int> Arr6={3,5,6,8};

    Node* head4 = convertArrToSLL(Arr4);
    Node* head5 = convertArrToSLL(Arr5);
    Node* head6 = convertArrToSLL(Arr6);

    vector<Node*> HeadList2 = {head4,head5,head6};

    vector<int> Arr7={1,7,11,12};
    vector<int> Arr8={2,4,9,10};
    vector<int> Arr9={3,5,6,8};

    Node* head7 = convertArrToSLL(Arr7);
    Node* head8 = convertArrToSLL(Arr8);
    Node* head9 = convertArrToSLL(Arr9);

    vector<Node*> HeadList3 = {head7,head8,head9};



    Node* MergedHead1 = merge_K_Sorted_SLL_Sol1(HeadList1);
    cout << "Using Sol 1 Merged K Sorted SLL" << endl;
    Print_SLL(MergedHead1);


    Node* MergedHead2 = merge_K_Sorted_SLL_Sol2(HeadList1);
    cout << "Using Sol 2 Merged K Sorted SLL" << endl;
    Print_SLL(MergedHead2);


    Node* MergedHead3 = merge_K_Sorted_SLL_Sol3(HeadList2);
    cout << "Using Sol 3 Merged K Sorted SLL" << endl;
    Print_SLL(MergedHead3);


    Node* MergedHead4 = merge_K_Sorted_SLL_Sol4(HeadList3);
    cout << "Using Sol 4 Merged K Sorted SLL" << endl;
    Print_SLL(MergedHead4);

    return 0;
}
