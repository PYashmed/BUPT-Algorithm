#include <bits/stdc++.h>
using namespace std;
//^ Josephus ring : Take the numbers 1,2,3...,nin a circle,
//^ counting clockwise from 1,output the number at that position when k is full (and delete the number from the ring),
//^ and then continue counting from the next number until all the numbers in the ring are output
struct node
{
    int data;
    struct node *next;
};

class linklist
{
private:
    node *tail;
    node *first;
    node *fr;
    int length;

public:
    linklist();
    void set(int);
    void get(int);
    void print();
    void printf();
};

linklist::linklist()
{
    tail = new node;
    first = new node;
    fr = first;
    tail->next = tail;
    first->next = NULL;
    length = 1;
}

void linklist::set(int n)
{
    tail->data = n;
    for (int i = n - 1; i > 0; i--)
    {
        struct node *t = new node;
        t->data = i;
        t->next = tail->next;
        tail->next = t;
        length++;
    }
}

void linklist::get(int n)
{
    node *tr = tail;
    while (length)
    {
        length--;
        int k = n;
        node *r = tr->next;
        while (k - 1)
        {
            k--;
            r = r->next;
            tr = tr->next;
        }
        tr->next = r->next;
        r->next = NULL;
        fr->next = r;
        fr = fr->next;
    }
}

// void linklist::print()
// {
//     cout << length << endl;
//     node *t = tail->next;
//     while (t != tail)
//     {
//         cout << t->data << " ";
//         t = t->next;
//     }
//     cout << tail->data << " ";
// }

void linklist::printf()
{
    node *t = first->next;
    while (t->next != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << t->data;
}

int main()
{
    linklist list1;
    int a, b;
    cin >> a >> b;
    list1.set(a);
    // list1.print();
    list1.get(b);
    list1.printf();
    return 0;
}
