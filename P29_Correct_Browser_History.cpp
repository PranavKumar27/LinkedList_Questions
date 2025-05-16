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

class BrowserHistory {
public:
    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
        //cout << "currentPage =" << currentPage->str << endl;
    }

    void visit(string url) {
        //cout << __FUNCTION__ << " At START currentPage =" << currentPage->str << endl;
        Node* newNode = new Node(url,nullptr,currentPage);
        currentPage->next = newNode;
        currentPage = newNode;
        //cout << __FUNCTION__ << " At END currentPage =" << currentPage->str << endl;
    }

    string back(int steps) {

        //cout << __FUNCTION__ << "  At START currentPage =" << currentPage->str << " step= " << steps << endl;
        while(steps>0)
        {
            if(currentPage->prev!=nullptr)
                currentPage = currentPage->prev;
            else
                break;
            steps--;
        }
        //cout << __FUNCTION__ << " At END currentPage =" << currentPage->str << endl;
        return currentPage->str;
    }

    string forward(int steps) {
        //cout << __FUNCTION__ << " At START currentPage =" << currentPage->str << endl;
        while(steps)
        {
            if(currentPage->next!=nullptr)
                currentPage = currentPage->next;
            else
                break;
            steps--;
        }
        //cout << __FUNCTION__ << " At END currentPage =" << currentPage->str << endl;
        return currentPage->str;
    }
};

int main()
{

    BrowserHistory Obj("google.com");
    Obj.visit("leetcode.com");
    Obj.visit("youtube.com");
    Obj.visit("StackOverflow.com");

    cout << "Current Page After Back 2 = " << Obj.back(2) << endl;

    cout << "Current Page After Forward 1 =" << Obj.forward(1) << endl;
    // Note StackOverflow.com can't be reached Here since we are youtube.com and insert TakeUForward.com
    Obj.visit("TakeUForward.com");
    Obj.visit("Java_DSA.com");

    cout << "Current Page After Back 3 = " << Obj.back(3) << endl;

    cout << "Current Page After Forward 2 =" << Obj.forward(2) << endl;

    cout << "Current Page After Back 9 = " << Obj.back(9) << endl;

    cout << "Current Page After Forward 4 =" << Obj.forward(4) << endl;


    return 0;
}
