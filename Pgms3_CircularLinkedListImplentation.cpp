#include <iostream>
#include<cmath>
using namespace std;

// Question: Implement Circular Linked List

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
        this->next=this;
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
                Node* temp = head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
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
                
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->next=head;
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
                Node* ptrStep2 = head;
                
                while(ptrStep2->next!= head && ptrStep2->next->next != head)
                {
                    ptrStep1 = ptrStep1->next;
                    ptrStep2 = ptrStep2->next->next;
                }
                newNode->next = ptrStep1->next;
                ptrStep1->next = newNode;
            }
        }
        // void insertNodeAtindex(int data,int K)
        // {
        //     int i;
        //     Node* newNode = new Node(data);
        //     if(head==NULL)
        //     {
        //         head=newNode;
        //         return;
        //     }
        //     else if(K==1)
        //     {
        //         insertNodeAtStart(data);
        //     }
        //     else if(K<=0 || K> size())
        //     {
        //         cout << "K is Invalid No Insert Performed.. Valid K Starts from 1" << endl;
        //         return;
        //     }
        //     else
        //     {
        //         Node* temp = head;
        //         cout << "K=" << K << endl;
        //         for(i==0; i<K && temp!=NULL; i++)
        //         {
        //             if(i==K-1)
        //             {
        //                 cout << "i=" << i << endl;
        //                 cout << " val=" << temp->data << endl;
        //                 Node* temp2=temp->next;
                
        //                 temp->next=newNode;
        //                 newNode->prev=temp;
        //                 newNode->next=temp2;
        //                 if(temp2 != NULL)
        //                     temp2->prev=newNode;
        //                 break;
        //             }
        //             else
        //             {
        //                 temp=temp->next;
        //             }
        //         }
        //     }
        // }
        
        void deleteNodeAtStart()
        {
            if(head!=NULL)
            {
                Node* temp=head;
                Node* newHead=head->next;
                
                if(temp==newHead) // Only one Node
                {
                    delete head;
                    head=NULL;
                    return;
                }
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newHead;
                delete head;
                head=newHead;
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
                while(temp->next!=head)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if(prev != NULL)
                {
                    prev->next = head;
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
                Node* prev=NULL;
                Node* slowPtr=head;
                Node* fastPtr=head;
                while(fastPtr->next!=head)
                {
                    fastPtr=fastPtr->next->next;
                    prev=slowPtr;
                    slowPtr=slowPtr->next;
                    if(fastPtr==head)
                    {
                        break;
                    }
                    
                }
                Node* nextNode;
                
                if(prev!=NULL)
                    prev->next=slowPtr->next;
                else
                    head=NULL;
                
                delete slowPtr;
                
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
                
                while(temp->next!=head)
                {
                    cout << temp->data << ",";
                    temp=temp->next;
                }
                cout << temp->data;
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
                while(temp!=head)
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
            int count=1;
            
            Node* temp=head;
            
            while(temp->next!=head)
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
    
    // list.deleteNodeAtEnd();
    // list.printAllNodes();
    
    // list.deleteNodeAtEnd();
    // list.printAllNodes();
    
    // list.deleteNodeAtEnd();
    // list.printAllNodes();
    
    // list.deleteNodeAtEnd();
    // list.printAllNodes();
    
    // list.deleteNodeAtEnd();
    // list.printAllNodes();
    
    // list.deleteNodeAtEnd();
    // list.printAllNodes();
    
    // list.deleteNodeAtEnd();
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
    
    list.deleteAllNodes();
    list.deleteNodeAtIndex(1);
    
    list.printAllNodes();
    
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
