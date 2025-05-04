#include <iostream>
#include <vector>
#include <math.h>

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

Node* reverse_DLL(Node* head)
{
    cout << __FUNCTION__ << endl;
    if(head==nullptr || head->next == nullptr)
        return head;

    Node* temp = nullptr;
    Node* current = head;

    while(current!=nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    print_DLL(temp->prev);
    return temp->prev;
}

int ConvertDLL_to_No(Node* head)
{
    int val=0;
    Node* temp = head;
    int i=0;
    while(temp!=nullptr)
    {
        val = val + temp->data*pow(10,i);
        temp = temp->next;
        i++;
    }
    cout << val << endl;
    return val;
}

Node* ConvertNo_toDLL(int N)
{
    vector<int> Num;

    while(N!=0)
    {
        int val = N%10;
        Num.push_back(val);
        N=N/10;
    }
    Node* newHead = convert_Arr_to_DLL(Num);
    print_DLL(newHead);
    return newHead;
}

Node* findSumRev(Node* head1,Node* head2)
{
    head1 = reverse_DLL(head1);
    head2 = reverse_DLL(head2);

    print_DLL(head1);
    print_DLL(head1);

    int v1 = ConvertDLL_to_No(head1);
    int v2 = ConvertDLL_to_No(head2);

    int ans = v1+v2;
    cout << "ans=" << ans << endl;

    return ConvertNo_toDLL(ans);
}

int main()
{
    vector<int> Arr1 = {5,3,4};
    Node* head1 = convert_Arr_to_DLL(Arr1);
    print_DLL(head1);

    vector<int> Arr2 = {1,0,2,4};
    Node* head2 = convert_Arr_to_DLL(Arr2);
    print_DLL(head2);

    Node* SumHead = findSumRev(head1,head2);

    print_DLL(SumHead);

    cout << "Add 2 Nos Reversed and Store Ans as Reversed" << endl;
    return 0;
}
