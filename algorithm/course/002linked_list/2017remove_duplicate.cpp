#include <bits/stdc++.h>
using namespace std;
//^ Given an ascending list, remove duplicate nodes

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};

template <class T>
class linklist
{
public:
    linklist();
    int length;
    void insert(T, int);
    ~linklist();
    void removeduplicate();
    void print();

private:
    node<T> *first;
};

template <class T>
linklist<T>::linklist()
{
    first = new node<T>;
    first->next = NULL;
}

template <class T>
linklist<T>::~linklist()
{
    while (first != NULL)
    {
        node<T> *p = first;
        first = first->next;
        delete p;
    }
}

template <class T>
void linklist<T>::insert(T x, int n)
{
    node<T> *p = first;
    int j = 0;
    while (j < n - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    node<T> *t = new node<T>;
    t->data = x;
    t->next = p->next;
    p->next = t;
}

template <class T>
void linklist<T>::removeduplicate()
{
    node<T> *t = first;
    node<T> *p = first->next;
    while (p != NULL)
    {
        if (p->next != NULL && p->data == p->next->data)
        {
            while (p->next != NULL && p->data == p->next->data)
            {
                p = p->next;
            }
            t->next = p->next;
            p = p->next;
        }
        else
        {
            p = p->next;
            t = t->next;
        }
    }
}

template <class T>
void linklist<T>::print()
{
    node<T> *pt = first->next;
    if (pt == NULL)
    {
        cout << "empty";
    }
    else
    {
        while (pt->next != NULL)
        {
            cout << pt->data << " ";
            pt = pt->next;
        }
        cout << pt->data;
    }
}

int main()
{
    int a;
    linklist<int> list1;
    cin >> a;
    if (a == 0)
    {
        cout << "empty";
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            int k;
            cin >> k;
            list1.insert(k, i + 1);
        }
        list1.removeduplicate();
        list1.print();
        list1.~linklist();
    }
    return 0;
}