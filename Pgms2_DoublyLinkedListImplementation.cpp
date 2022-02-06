#include <iostream>
#include<cmath>
using namespace std;

// Question: Implement Double Linked List

class Node 
{
    public:
    
    int data;
    Node * prev;
    Node * next; 
    
    Node()
    {
        data=-1;
        prev=NULL;
        next=NULL;
    }
    Node(int val)
    {
        this->data=val;
        this->prev=NULL;
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
       
        void insertNodeAtStart(int data)
        {
            Node* newNode=new Node(data);
            
            if(head==NULL)
            {
                head=newNode;
            }
            else
            {
                head->prev=newNode;
                newNode->next=head;
                head=newNode;
                
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
                newNode->prev=temp;
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
                Node* ptrStep1 = head;
                Node* ptrStep2 = head->next;
                
                while(ptrStep2!= NULL && ptrStep2->next != NULL)
                {
                    ptrStep1 = ptrStep1->next;
                    ptrStep2 = ptrStep2->next->next;
                }
                Node* temp = ptrStep1->next;
                ptrStep1->next = newNode;
                newNode->prev = ptrStep1;
                newNode->next = temp;
                temp->prev = newNode;
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
                        cout << "i=" << i << endl;
                        cout << " val=" << temp->data << endl;
                        Node* temp2=temp->next;
                
                        temp->next=newNode;
                        newNode->prev=temp;
                        newNode->next=temp2;
                        if(temp2 != NULL)
                            temp2->prev=newNode;
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
                Node* prevNode;
                Node* nextNode;
                if(ptrSteps2->next!=NULL)
                {
                    ptrSteps2=ptrSteps2->next; // Even no of elements
                }
                
                prevNode=ptrSteps1->prev;
                nextNode=ptrSteps1->next;
                
                if(prevNode!=NULL)
                    prevNode->next=nextNode;
                else
                {
                    head=nextNode; // Only one node left 
                }
                if(nextNode!=NULL)  
                    nextNode->prev=prevNode;
                

                    delete ptrSteps1;
                
                
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
                    temp->prev=prev;
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
            else
            {
                cout << "List is Empty!!" << endl;
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

int main()
{
    
    
    LinkedList list;
    
    for(int i=0;i<5;i++)
    {
        list.insertNodeAtEnd(i+1);
    }
    
    
    list.printAllNodes();
    // list.insertNodeAtMid(50);
    
    // for(int i=0;i<5;i++)
    // {
    //     list.insertNodeAtEnd(i+10);
    // }
    // list.printAllNodes();
    // list.insertNodeAtindex(10,7);
    // list.insertNodeAtMid(70);
    
    // list.printAllNodes();
    // // list.printAllNodes();
    
    // list.deleteNodeAtStart();
    // list.printAllNodes();
    
    // list.deleteNodeAtStart();
    // list.printAllNodes();
    
    // list.deleteNodeAtStart();
    // list.printAllNodes();
    
    // list.deleteNodeAtStart();
    // list.printAllNodes();
    
    // list.deleteNodeAtStart();
    // list.printAllNodes();
    
    // list.deleteNodeAtStart();
    // list.printAllNodes();
    
    // list.deleteNodeAtStart();
    // list.printAllNodes();
    
    // list.deleteNodeAtEnd();
    // list.printAllNodes();
    
    // for(int i=0;i<5;i++)
    // {
    //     list.insertNodeAtStart(i+1);
    // }
    
    // list.printAllNodes();
    
    // list.deleteNodeAtMid();
    
    // list.printAllNodes();
    
    // list.deleteNodeAtMid();
    
    // list.printAllNodes();
    
    // list.deleteNodeAtMid();
    
    // list.printAllNodes();
        
    // list.deleteNodeAtMid();
    
    // list.printAllNodes();
        
    // list.deleteNodeAtMid();
    
    // list.printAllNodes();
        
    // list.deleteNodeAtMid();
    
    // list.printAllNodes();
    
    // list.deleteNodeAtMid();
    
    // list.printAllNodes();
    
    // list.deleteNodeAtIndex(4);
    list.deleteAllNodes();
    // list.printAllNodes();
    
    // list.deleteNodeAtIndex(3);
    // list.printAllNodes();
    
    // list.deleteNodeAtIndex(1);
    // list.printAllNodes();
    
    // // list.deleteNodeAtIndex(2);
    // list.printAllNodes();
    
    // list.deleteNodeAtIndex(1);
    
    list.printAllNodes();
    return 0;
}
