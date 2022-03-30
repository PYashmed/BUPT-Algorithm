#include <bits/stdc++.h>
using namespace std;
//^ define node
template <class T>
struct node
{
    T data;
    struct node<T> *next;
};

//^link node construct linked list
template <class T>
class linklist
{
public:
    linklist();
    linklist(T a[], int n);
    int length;
    T get(int n);
    int locate(T);
    void insert(T, int);
    T Delete(int);
    ~linklist();

private:
    node<T> *first;
};

//^ empty list
template <class T>
linklist<T>::linklist()
{
    first = new node<T>;
    first->next = NULL;
}

//^ constructor----first interpolation
/* template <class T>
linklist<T>::linklist(T a[], int n)
{
    //^ initialize first node
    first = new node<T>;
    first->next = NULL;
    //! continue building (first interpolation)
    for (int i = 0; i < n; i++)
    {
        //^ build new node
        node<t> *s = new node<T>;
        s->data = a[i];
        //^ link new node (next first node)
        s->next = first->next;
        first->next = s;
    }
} */

//^ contrustor end interpolation
template <class T>
linklist<T>::linklist(T a[], int n)
{
    //^ initialize first node
    node<T> *first = new node<T>;
    node<T> *r = first;
    //! continue building (end interpolation)
    for (int i = 0; i < n; i++)
    {
        node<T> *s = new node<T>;
        s->data = a[i];
        s->next = NULL;
        r->next = s;
        r = s;
    }
};

//^ destructor
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

//^ locate
template <class T>
int linklist<T>::locate(T x)
{
    node<T> *p = first->next;
    int j = 1;
    while (p != NULL)
    {
        if (p->data = x)
        {
            return j;
        }
        j++;
    }
}

//^ Get
template <class T>
T linklist<T>::get(int n)
{
    node<T> *p = first->next;
    int j = 1;
    while (j < i && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (p = NULL)
    {
        throw "location error"
    }
    return p->data;
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
    if (p = NULL)
    {
        throw "location error"
    }
    else
    {
        node<T> *t = new node<T>;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

