#include <iostream>
#include <vector>

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

int LengthOfSLL(Node* head)
{
    int cnt =0;
    Node* temp = head;
    while(temp!=nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
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

void print_vector(vector<int>& V)
{
    for(auto d:V)
        cout << d << " ";
    cout << endl;
}

// TC -> O(N/2+N/2 + N) = O(2N) 
// SC -> O(N) for Vector
void ReArrangeOddIndex_EvenIndex_elements_Sol1(Node* head)
{
    vector<int> ReArrange;
    if(head==nullptr||head->next==nullptr)
        return;
    Node* temp = head;

    while(temp!=nullptr) // Reading odd indexes Here
    {
        ReArrange.push_back(temp->data);
        if(temp->next!=nullptr)
            temp=temp->next->next;
        else
            temp=temp->next;
    }

    temp = head->next;

    while(temp!=nullptr) // Reading Even indexes Here
    {
        ReArrange.push_back(temp->data);
        if(temp->next!=nullptr)
            temp=temp->next->next;
        else
            temp = temp->next;
    }

    print_vector(ReArrange);


    int idx=0;
    temp = head;
    while(temp!=nullptr)
    {
       temp->data = ReArrange[idx++];
       temp = temp->next;
    }
    return;
}

// TC -> O(N) 
// SC -> O(1)
void ReArrangeOddIndex_EvenIndex_elements_Sol2(Node* head)
{
   if(head==nullptr || head->next==nullptr)
        return;

   Node* OddHead = head;
   Node* EvenHead = head->next;
   Node* tempEven = head->next;
   while(EvenHead!=nullptr)
   {
       if(OddHead->next!=nullptr)
       {
           Node* NewOdd=OddHead->next->next;
          if(NewOdd!=nullptr) // We need to assign evenHead to OddHead at the END,
                            //Hence do not make OddHead as null
          {
             OddHead->next = NewOdd;
             OddHead = NewOdd;
          }
       }
       if(EvenHead->next!=nullptr)
       {
           Node* NewEven = EvenHead->next->next;
           EvenHead->next = NewEven;
           EvenHead = NewEven;
       }
       else
       {
           EvenHead = EvenHead->next;
       }

   }
   OddHead->next = tempEven;
   return;

}
int main()
{
    cout << "Print_Odd_then_Even" << endl;
    vector<int> Arr = {1,2,3,4,5,6};
    Node* head = convertArrToSLL(Arr);
    Print_SLL(head);

    cout << "After ReArrange of OddIndex and EvenIndex elements" << endl;
    ReArrangeOddIndex_EvenIndex_elements_Sol2(head);
    Print_SLL(head);
    return 0;
}
