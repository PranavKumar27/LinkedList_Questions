#include <iostream>
#include<cmath>
#include<map>
using namespace std;

// Coded @Pranav on Feb 11,2022
// Question: There are two LinkedList of size m and size n 
// Both this linked list gets Merged at some point and become single list 
// Find the point where these Lists merge and become one
// Constraints: 
// 1.>  If the number in both list are unique/non repeating
// 2.> If numbers are repeating any number of times

// Solution 1: If number is not repeating
//Approach 1: Store all numbers from list1 in an array1, sort it
// Store all numbers from list2 in an array2, sort it
// traverse in array1 and array2 and the First element which is matching
// the first match is the intersection point of both the Lists

// Solution 2: Use 2 stack to store all the element of list1 and list2
// Keep pop of list1 and list2 and find the intersection point 
// whereby first element which is different, the next of that is the intersection point item
// Hence maintain a prev item before pop 

// Both Solution works with Constraints 1.

// Solution 3: Use Hash table , maintain the addresses of all items
// So first traverse list 1 and store all addresses in a hash table.
// Start Traversing list 2 and see if there is match in hash table
// If yes, then we are at merge point and value can be obtained.



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
       Node* getTailAddress()
        {
            if(head!=NULL)
            {
                Node* temp = head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                return temp;
            }
            else
            {
                cout << "getTail Failed Head is Empty!! " << endl;
                return head;
            }
        }
        
        void CreateAMergingList(Node* list2Tail)
        {
            // Assumptions
            // Size of list1 and list2 > 4
            // merge point is 3rd Index 
            
            // list 1: 1 2 3 4 5
            // list 2: 6 7 8 9 10
            
            // new List 
            // List 1: 1 2 3 4 5
            // List 2: 6 7 8 8 10 4 5
            // Merge point= 4
            
            int count=0;
            Node* temp=head;
            while(count<2 && count < size())
            {
                temp=temp->next;
                count++;
            }
            
            list2Tail->next=temp->next;
            
        }
        
};



int main()
{
    
    LinkedList list1;
    
    for(int i=1;i<=5;i++)
    {
        list1.insertNodeAtEnd(i);
    }
    
    list1.printAllNodes();
    
    LinkedList list2;
    
    for(int i=6;i<=10;i++)
    {
        list2.insertNodeAtEnd(i);
    }
    
    list2.printAllNodes();
    
    list1.CreateAMergingList(list2.getTailAddress());
    
    list1.printAllNodes();
    list2.printAllNodes();
    

    
    

    return 0;
}
