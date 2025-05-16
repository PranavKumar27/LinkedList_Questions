#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    string str;
    Node* next;
    Node* prev;
    Node(string s)
    {
        str = s;
        next = nullptr;
        prev = nullptr;
    }
    Node(string s,Node* nextNode,Node* prevNode)
    {
        str = s;
        next = nextNode;
        prev = prevNode;
    }
};

Node* visit(Node* head,string url)
{
    Node* temp = head;
    while(temp!=nullptr && temp->next!=nullptr)
        temp = temp->next;

    Node* newNode = new Node(url,nullptr,temp);
    temp->next = newNode;
    return head;
}

Node* forward_Page(Node* Page,int k)
{
    int cnt = k;
    Node* temp = Page->next;
    while(temp!=nullptr)
    {
        cnt--;
        if(cnt==0)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

Node* back_Page(Node* Page,int k)
{
    int cnt = k;
    Node* temp = Page->prev;
    while(temp!=nullptr)
    {
        cnt--;
        if(cnt==0)
            return temp;
        temp = temp->prev;
    }
    return nullptr;
}

void Print_All_Pages(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout << "Page URL =" << temp->str << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << "Design Browser History" << endl;
    vector<string> Browser_Urls = {"google.com","insta.com","profile.insta.com","about.insta"};
    Node* dummyHead = new Node("DummyPage");
    Node* res = nullptr;
    dummyHead = visit(dummyHead,Browser_Urls[0]);



    dummyHead = visit(dummyHead,Browser_Urls[1]);

    dummyHead = visit(dummyHead,Browser_Urls[2]);

    dummyHead = visit(dummyHead,Browser_Urls[3]);

    Print_All_Pages(dummyHead);

    res = back_Page(dummyHead->next->next->next,2);
    if(res!=nullptr)
        cout << "Page Now after back 2 is at URL = " << res->str << endl;
    else
        cout << "Cannot go back 2" << endl;

    res =forward_Page(dummyHead->next,2);
    if(res!=nullptr)
        cout << "Page Now after Forward 1 is at URL = " << res->str << endl;
    else
        cout << "Cannot go Forward 1" << endl;


    return 0;
}
