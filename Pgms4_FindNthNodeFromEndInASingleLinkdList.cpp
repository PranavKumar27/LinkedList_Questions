#include <iostream>
#include<cmath>
#include<map>
using namespace std;

// Question: Find the Kth Node in the linkedlist from behind.
//Solution: Count the total number of nodes, then Go to Total-n+1
// Ex: If there are 10 nodes and nth node is 3rd, then we can first reach
// Total-n+1, 10-3+1 i.e. 8th node would be 3rd node from the end if 1 based index
// If zero based index use Total-n;

class Node 
{
    public:
    
    int data;
    Node * next; 
    
     Node()
        {
            data=-1;
            next=NULL;
        }
        Node(int val)
        {
            this->data=val;
            this->next=NULL;
            
        }
};
class LinkedList 
{
    Node* head;
    
    public: 
    
        LinkedList()
        {
            head=NULL;
        }
       
       Node* getHeadAddress()
       {
           return head;
       }
        void insertNodeAtStart(int data)
        {
            Node* newNode=new Node(data);
            
            if(head==NULL)
            {
                head=newNode;
            }
            else
            {
                Node* temp=head;
                head=newNode;
                newNode->next=temp;
            }
        }
        void insertNodeAtEnd(int data)
        {
            Node* newNode = new Node(data);
            
            if(head==NULL)
            {
                head=newNode;
            }
            else
            {
                Node* temp=head;
                
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
            }
        }
        void insertNodeAtMid(int data)
        {
            Node* newNode = new Node(data);
            
            if(head==NULL)
            {
                head=newNode;
            }
            else
            {
                // You can also traverse till size()/2 index then write temp->next=temp->next->next;
                Node* ptrStep1 = head;
                Node* ptrStep2 = head;
                
                while(ptrStep2->next != NULL && ptrStep2->next->next != NULL)
                {
                    ptrStep1 = ptrStep1->next;
                    ptrStep2 = ptrStep2->next->next;
                }
                Node* temp = ptrStep1->next;
                ptrStep1->next = newNode;
                newNode->next = temp;
            }
        }
        void insertNodeAtindex(int data,int K)
        {
            int i;
            Node* newNode = new Node(data);
            if(head==NULL)
            {
                head=newNode;
                return;
            }
            else if(K==1)
            {
                insertNodeAtStart(data);
            }
            else if(K<=0 || K> size())
            {
                cout << "K is Invalid No Insert Performed.. Valid K Starts from 1" << endl;
                return;
            }
            else
            {
                Node* temp = head;
                cout << "K=" << K << endl;
                for(i==0; i<K && temp!=NULL; i++)
                {
                    if(i==K-1)
                    {
                        cout << "Break" << " i=" << i << endl;
                        Node* temp2=temp->next;
                        temp->next=newNode;
                        newNode->next=temp2;
                        break;
                    }
                    else
                    {
                        temp=temp->next;
                    }
                }
            }
        }
        
        void deleteNodeAtStart()
        {
            if(head!=NULL)
            {
                Node* temp=head;
                head = head->next;
                delete temp;
            }
            else
            {
                cout << "Head is Empty Delete At Start Failed" << endl;
            }
        }
        int deleteNodeAtEnd()
        {
            if(head!=NULL)
            {
                Node* prev = NULL;
                Node* temp = head;
                while(temp->next!=NULL)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if(prev != NULL)
                {
                    prev->next = NULL;
                    delete temp;
                }
                else
                {
                    delete temp;
                    head = NULL;
                }
            }
            else
            {
                cout << "Head is Empty Delete At End Failed" << endl;
            }
        }
        int deleteNodeAtMid()
        {
            if(head != NULL)
            {
                Node* ptrSteps1=head;
                Node* ptrSteps2=head;
                while(ptrSteps2->next!=NULL && ptrSteps2->next->next!=NULL)
                {
                    ptrSteps1=ptrSteps1->next;
                    ptrSteps2=ptrSteps2->next->next;
                }
                if(ptrSteps2->next!=NULL)
                {
                    ptrSteps2=ptrSteps2->next; // Even no of elements
                }
                Node *temp=NULL;
                while(ptrSteps1!=ptrSteps2)
                {
                    temp=ptrSteps1;
                    ptrSteps1=ptrSteps1->next;
                    temp->data=ptrSteps1->data;
                }
                if(temp != NULL)
                {   
                    temp->next=NULL;
                    delete ptrSteps1; // ptrSteps1 and ptrSteps2 are same;
                }
                else
                {
                    delete head;
                    head=NULL;
                }
            }
            else
            {
                cout << "Head is Empty Delete At Mid Failed" << endl;
            }
        }
        void deleteNodeAtIndex(int K)
        {
            if(head==NULL)
            {
                cout << "Head is Empty Delete At Index Failed" << endl;
                return;
            }
            else if(K==1) // delete at head and Head !=NULL check done in First IF
            {
                deleteNodeAtStart();
            }
            else if( K <= 0 || K > size() )
            {
                cout << "K is Invalid No Delete Performed ... . Valid K Starts from 1" << endl;
                return;
            }
            else if( head!=NULL )
            {
                int i=0;
                
                Node* prev=NULL;
                Node* temp=head;
                while(i<K && temp!=NULL)
                {
                    if(i==K-1)
                    {
                        // delete=true;
                        break;
                    }
                    else
                    {
                        i++;
                        prev=temp;
                        temp=temp->next;
                    }
                }
                if(prev != NULL && temp != NULL)
                {
                    prev->next=temp->next;
                }
                delete temp;
            }
            else
            {
                cout << " Delete At Index Failed  Reason Unknown" << endl;
            }
        }
        
        void printAllNodes()
        {
            if(head!=NULL)
            {
                Node * temp=head;
                
                while(temp!=NULL)
                {
                    cout << temp->data << ",";
                    temp=temp->next;
                }
                cout << endl;
            }
        }
        
        int deleteAllNodes()
        {
            if(head!=NULL)
            {
                Node* temp=head;
                Node* prev=NULL;
                while(temp!=NULL)
                {
                    prev=temp;
                    temp=temp->next;
                    delete prev;
                }
                delete temp;
                head = NULL;
            }
        }
        int size()
        {
            int count=0;
            
            Node* temp=head;
            
            while(temp!=NULL)
            {
                count++;
                temp=temp->next;
            }
            
            return count;
        }
};

Node* FindDataOnNthNode_Approach1(LinkedList list,int K)
{
    // Step1: Find the Total no use size()
    int Total = list.size();
    int nodeToFind = Total - K ;
    
    int count=0;
    Node* temp=list.getHeadAddress();
    if(temp != NULL)
    {
       for(;count<nodeToFind && temp!=NULL;count++)
        {
            temp=temp->next;
        }
        // Node to find is in temp
        return temp;
    }
    else
    {
        return NULL;
    }
    
}

int FindDataOnNthNode_Approach2(LinkedList list,int K)
{
    map<int,int> m;
    
    // Step1: Find the Total no use size()
    int Total = list.size();
    int nodeToFind = Total - K ;
    
    int count=0;
    Node* temp=list.getHeadAddress();
    while(temp!=NULL)
    {
        m[count++]=temp->data;
        temp=temp->next;
    }
    // Node to find is in temp
        
    if(nodeToFind < Total)
        return m[nodeToFind];
    else
        return -1;
}

int FindDataOnNthNode_Approach3(LinkedList list,int K)
{
    int Res=-1;
    Node* first;
    Node* second;
    
    first=list.getHeadAddress();
    second=list.getHeadAddress();
    
    int count=0;
    while(first!=NULL && second->next!=NULL)
    {
        second=second->next;
        if(count<K)
            count++;
        
        if(count==K && second!=NULL)
        {
            first=first->next;
        }
    }

    if(first!=NULL)
    {
        Res = first->data;
        cout << "Res=" << Res << endl;
    }
    else
    {
        cout << "First is NULL" << endl;
    }
    
    return Res;;
    
}

int main()
{
    
    // Find the 3rd node in list from behind
    int n=3;
    
    LinkedList list;
    
    for(int i=0;i<10;i++)
    {
        list.insertNodeAtEnd(i+1);
    }
    
    list.printAllNodes();
    
    Node* NthNodeFromBehind = FindDataOnNthNode_Approach1(list,7);
    
    if(NthNodeFromBehind!=NULL)
    {
        cout << "Value of NthNodeFromBehind Approach 1=" << NthNodeFromBehind->data << endl;
    }
    else
    {
        cout << "NthNodeFromBehind is invalid, Can't find by Approach1" << endl;
    }
    
    
        
    int Res = FindDataOnNthNode_Approach2(list,2);
    
    if(Res!=-1)
    {
        cout << "Value of NthNodeFromBehind Approach 2=" << Res << endl;
    }
    else
    {
        cout << "NthNodeFromBehind is invalid, Can't find by Approach2" << endl;
    }
    
    
    
    int Res3 = FindDataOnNthNode_Approach3(list,7);
    
    if(Res3!=-1)
    {
        cout << "Value of NthNodeFromBehind Approach 3=" << Res3 << endl;
    }
    else
    {
        cout << "NthNodeFromBehind is invalid, Can't find Approach3" << endl;
    }
    
    
    return 0;
}
