#include <iostream>
#include <vector>
#include <map>

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

Node* make_Y_List(Node* head1,vector<int>& Arr,int k)
{
    Node* head2 = convertArrToSLL(Arr);
    Print_SLL(head2);

    int cnt = 0;
    Node* temp1 = head1;
    while(temp1!=nullptr)
    {
        if(cnt==k)
            break;
        cnt++;
        temp1 = temp1->next;
    }

    cnt = 0;
    Node* temp2 = head2;
    while(temp2!=nullptr)
    {
        if(cnt==k+2)
            break;
        cnt++;
        temp2 = temp2->next;
    }

    temp2->next = temp1;
    return head2;
}



// TC --> O(N1*logN1) + O(N2*LogN2)
// SC --> O(N1) for storing in Map
bool findIfList_intersect_Sol1(Node* head1,Node* head2)
{
    map<Node*,int> Mp;

    Node* temp1 = head1;
    while(temp1!=nullptr)
    {
        Mp[temp1]++;
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while(temp2!=nullptr)
    {
        if(Mp.find(temp2)!=Mp.end())
        {
            cout << "Intersection Point Value =" << temp2->data << endl;;
            return true;
        }
        Mp[temp2]++;
        temp2 = temp2->next;
    }
    cout << "No Intersection Point Found in Lists " << endl;
    return false;

}
// TC --> O(N1) + O(N2) + O(N2-N1)+O(N1) = O(N1+2N2)
// SC --> O(1)
bool findIntersect(Node* Longer,Node* Shorter,int k)
{
    if(Longer!=nullptr)
    {
        // l1 is longer
        // Move l1 k steps
        int cnt =0;
        while(Longer!=nullptr)
        {
            if(cnt==k)
                break;
            cnt++;
            Longer = Longer->next;
        }

        cout << "Longer =" << Longer << endl;
        while(Longer!=nullptr && Shorter!=nullptr)
        {
            if(Longer==Shorter)
            {
               cout << "Intersection Point Value =" << Shorter->data << endl;;
                return true;
            }
            Longer = Longer->next;
            Shorter = Shorter->next;
        }

    }
    cout << "No Intersection Point Found in Lists " << endl;
    return false;
}

bool findIfList_intersect_Sol2(Node* head1,Node* head2)
{
    int N1 = findLenOf_SLL(head1);
    int N2 = findLenOf_SLL(head2);

    Node* temp1 = nullptr;
    Node* temp2 = nullptr;
    bool ans = false;
    int k;
    if(N1>N2)
    {
      k= N1-N2;
      ans = findIntersect(head1,head2,k);
    }
    else
    {
        k=N2-N1;
        ans = findIntersect(head2,head1,k);
    }

    return ans;
}
// TC --> O(N1+N2)
// SC --> O(1)
bool findIfList_intersect_Sol3(Node* head1,Node* head2)
{
    cout << __FUNCTION__ << endl;
    Node* t1 = head1;
    Node* t2 = head2;

    if(head1==nullptr || head2==nullptr)
        return false;

    if(t1==t2)
    {
        cout << "Intersection Point Value =" << t1->data << endl;;
        return true;
    }
    while(t1!=t2)
    {
        t1 = t1->next;
        t2 = t2->next;


        if(t1==nullptr && t2==nullptr)  // Un-connected List, No Y Shape.
            break;

        if(t1==t2)
        {
           cout << "Intersection Point Value =" << t1->data << endl;;
           return true;
        }

        if(t1==nullptr)
            t1=head2;
        if(t2==nullptr)
            t2=head1;

        if(t1==t2)
        {
           cout << "Intersection Point Value =" << t1->data << endl;;
           return true;
        }
    }
    cout << "No Intersection Point Found in Lists " << endl;
    return false;
}

int main()
{
    cout << "<---- Y List --->" << endl;
    vector<int> Arr = {3,1,4,6,2};
    Node* head1 = convertArrToSLL(Arr);
    Print_SLL(head1);

    int k = 2;
    vector<int> Arr2 = {1,2,3,4,5,6,7,8,9};
    Node* head2 = make_Y_List(head1,Arr2,k);
    //Node* head2 = convertArrToSLL(Arr2);
    Print_SLL(head2);

    bool IsIntersection = findIfList_intersect_Sol3(head1,head2);

    cout << "Is List Intersected =" << IsIntersection << endl;

    return 0;
}
