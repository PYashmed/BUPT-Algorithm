#include <bits/stdc++.h>
using namespace std;
int x;
struct node
{
    int data;
    node *left;
    node *right;
};

void insert(node *&head, int data)
{
    node *t = new node;
    node *cur = head;
    t->data = data;
    t->left = NULL;
    t->right = NULL;

    if (head == NULL)
        head = t;
    else
    {
        while (true)
        {
            if (cur->data >= data)
            {
                if (cur->left == NULL)
                {
                    cur->left = t;
                    return;
                }
                else
                    cur = cur->left;
            }
            else
            {
                if (cur->right == NULL)
                {
                    cur->right = t;
                    return;
                }
                else
                    cur = cur->right;
            }
        }
    }
}

int searchBST(node *bst, int data)
{
    node *q;
    q = bst;
    while (q)
    {
        x++;
        if (q->data == data)
            return q->data;
        if (q->data > data)
            q = q->left;
        else
            q = q->right;
    }
    return -1;
}

int main()
{
    int n, a;
    node *head = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        insert(head, a);
    }
    int key;
    cin >> key;
    searchBST(head, key);
    cout << x;
    return 0;
}
