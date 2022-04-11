#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    node *next;
};

class stacklist
{
public:
    stacklist();
    void empty();
    void put();
    void pop();
    node *first;
    node *top;
};
stacklist::stacklist()
{
    first = new node;
    first->a = -1;
    first->next = NULL;
    top = first;
}

void stacklist::put()
{
    node *t = new node;
    t->a = 0;
    t->next = NULL;
    top->next = t;
    top = t;
}

void stacklist::pop()
{
    
}
void check(string a)
{
    int n = a.length();
    while (n)
    {
        n--;
    }
}
