#include <bits/stdc++.h>
using namespace std;
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

int Degree0(node *T)
{
    if (T == NULL)
        return 0;
    if (T->left == NULL && T->right == NULL)
        return Degree0(T->left) + Degree0(T->right) + 1;
    else
        return Degree0(T->left) + Degree0(T->right);
};

int Degree1(node *T)
{
    if (T == NULL)
        return 0;
    if ((T->left == NULL && T->right != NULL) || (T->left != NULL && T->right == NULL))
        return Degree1(T->left) + Degree1(T->right) + 1;
    else
        return Degree1(T->left) + Degree1(T->right);
};

int Degree2(node *T)
{
    if (T == NULL)
        return 0;
    if ((T->left != NULL && T->right != NULL))
        return Degree2(T->left) + Degree2(T->right) + 1;
    else
        return Degree2(T->left) + Degree2(T->right);
};

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
    cout << Degree0(head) << " " << Degree1(head) << " " << Degree2(head) << endl;
    return 0;
}
