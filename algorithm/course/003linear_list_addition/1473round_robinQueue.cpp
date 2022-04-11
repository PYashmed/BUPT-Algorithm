#include <bits/stdc++.h>
using namespace std;

// construct node
struct node
{
    int data;
    struct node *next;
};

class rrqueue
{
private:
    node *tail;

public:
    rrqueue();
    rrqueue(int, int[]);
    void insert(int);
    void head();
    void pop(int);
    void getlength();
};

rrqueue::rrqueue()
{
    tail = new node;
    tail->next = tail;
}

void rrqueue::insert(int a)
{
    node *t = new node;
    t->data = a;
    t->next = tail->next;
    tail->next = t;
}

void rrqueue::getlength()
{
    node *t = tail;
    int i = 0;
    while (t->next != tail)
    {
        t = t->next;
        i++;
    }
    cout << i;
}

void rrqueue::head()
{
    cout << tail->next->data;
}

void rrqueue::pop(int a)
{
    node *t = tail->next;
    node *r = tail;
    if (t->data == a)
    {
        r->next = t->next;
        delete t;
    }
    else
    {
        t = t->next;
        r = r->next;
    }
    cout << a;
}

int main()
{
    rrqueue list;
    int a;
    cin >> a;
    int i = 0;
    int b[100];
    int j = a;
    while (j)
    {
        cin >> b[i];
        i++;
        j--;
    }
    for (int k = a - 1; k >= 0; k--)
    {
        list.insert(b[k]);
    }
    list.getlength();
    cout << " ";
    list.head();
    cout << " ";
    list.pop(b[0]);
    cout << " ";
    list.getlength();
    return 0;
}