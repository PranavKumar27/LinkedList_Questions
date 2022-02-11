#include <iostream>
#include<cmath>
#include<map>
using namespace std;

// Question: Reverse a given LinkedList
// Solution 1: Use Iterative Approach to Reverse a list
// Solution 2: Use the Recursive Approach to Reverse a list

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
        
        void ReverseByIteration()
        {
            if(head != NULL)
            {
                Node* prev = NULL;
                Node* cur = head;
                Node* temp=NULL;
                
                while(cur != NULL)
                {
                    temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                // We have a PCT Logic whereby P-prev C-cur and T-temp keeps on moving until prev has new head
                }
                head = prev;
            }
            else
            {
                cout << " Reverse on List Failed as Head is Empty!!" << endl;
            }
        }
        
        void ReverseByRecursionAnotherApproach(Node* prev,Node*cur)
        {
            if(cur==NULL)
            {
                head=prev;
                return;
            }
            Node* temp = cur->next; // head of list which is not reversed
            cur->next=prev;
            prev=cur;
            cur=temp;// Remaing list
            ReverseByRecursionAnotherApproach(prev,cur);
            
        }
        Node* ReverseByRecursion(Node* head)
        {
            if(head==NULL || head->next==NULL)
            {
                return head;
            }
            Node* newhead=ReverseByRecursion(head->next);
            head->next->next=head;
            head->next=NULL;
            return newhead;
        }
        void setHead(Node* newHead)
        {
            if(newHead!=NULL)
            {
                head=newHead;
            }
            else
            {
                cout << "setHead Failed !! " << endl;
            }
        }
       
};



int main()
{
    
    LinkedList list;
    
    for(int i=1;i<=5;i++)
    {
        list.insertNodeAtEnd(i);
    }
    
    list.printAllNodes();
    
    // list.ReverseByRecursionAnotherApproach(NULL,list.getHeadAddress());
    
    // list.printAllNodes();
    
    list.setHead(list.ReverseByRecursion(list.getHeadAddress()));
    
    list.printAllNodes();
    return 0;
}
