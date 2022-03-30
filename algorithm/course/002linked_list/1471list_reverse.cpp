#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
/* {
    example input
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
} */

/* {
    example input
00100 6 0
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
} */

/* {
    example input
00100 6 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
} */

/* {
    example input
00100 6 7
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
} */

/* {
00100 6 2
00000 4 -1
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
} */

//^ build node
struct node
{
    int a, data, b;
    struct node *next;
};

//^ build linklist
class linklist
{
private:
    node *first, *r;
    int num = 0;

public:
    linklist();
    void set(int, int, int);
    void sort(int);
    void print();
    void reverse(int);
};

//^ blank list
linklist::linklist()
{
    first = new node;
    first->next = NULL;
    r = first;
}

//^ add node ,link list
void linklist::set(int x, int y, int z)
{
    struct node *t = new node;
    t->a = x;
    t->data = y;
    t->b = z;
    t->next = NULL;
    r->next = t;
    r = t;
}

//^ sort the list by x.a as front address and x.b as next address
void linklist::sort(int x)
{
    first->b = x;
    node *q = first->next;
    node *o = first;
    node *sr = first;
    while (sr->b != -1)
    {
        if (q->a == sr->b)
        {
            o->next = q->next;
            if (sr->next == q)
            {
                sr = q;
                q = q->next;
                o = o->next;
            }
            else
            {
                q->next = sr->next;
                sr->next = q;
                sr = q;
                q = first->next;
                o = first;
            }
        }
        else
        {
            q = q->next;
            o = o->next;
        }
    }
    sr = first;
    while (sr->b != -1)
    {
        sr = sr->next;
    }
    sr->next = NULL;
}

//^ print list
void linklist::print()
{
    node *pr, *ppr;
    pr = first->next;
    ppr = pr->next;
    while (pr != NULL)
    {
        cout << setfill('0') << setw(5) << pr->a;
        cout << " " << pr->data << " ";
        if (pr->next != NULL)
        {
            cout << setfill('0') << setw(5) << pr->next->a << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
        pr = pr->next;
        if (pr->next != NULL)
        {
            ppr = pr->next;
        }
    }
}

//^reverse
void linklist::reverse(int n)
{
    node *a = first->next;
    node *rr;
    node *fr = first;
    num = 0;
    while (a != NULL)
    {
        num++;
        a = a->next;
    }
    a = fr->next;
    fr->next = NULL;
    int k;
    if (n == 0)
    {
        k = 0;
    }
    else
    {
        k = num / n;
    }
    while (k > 0)
    {
        k--;
        for (int i = 0; i < n; i++)
        {
            rr = a;
            a = a->next;
            rr->next = fr->next;
            fr->next = rr;
        }
        while (fr->next != NULL)
        {
            fr = fr->next;
        }
    }
    fr->next = a;
}

int main()
{
    int a, b, c;
    int m, n, q;
    cin >> m >> n >> q;
    linklist list1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        list1.set(a, b, c);
    }
    list1.sort(m);
    list1.reverse(q);
    list1.print();
    return 0;
}
