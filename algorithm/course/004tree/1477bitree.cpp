#include <bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node *lcd;
    node *rcd;
};
node *creat(const char *in, const char *pre, int l1, int h1, int l2, int h2)
{
    // ^ l1,h1 are infix order's first sequence number and last seqnum;
    // ^ l2,h2 are preorder's first and last seqnum;
    int llen = 0, rlen = 0, i = 0;
    node *root = new node;
    root->data = *(pre + l2);
    for (i = l1; *(in + i) != root->data; i++)
        ;
    llen = i - l1;
    rlen = h1 - i;
    if (llen)
    {
        root->lcd = creat(in, pre, l1, l1 + llen - 1, l2 + 1, l2 + llen);
    }
    else
    {
        root->lcd = NULL;
    }
    if (rlen)
    {
        root->rcd = creat(in, pre, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    }
    else
    {
        root->rcd = NULL;
    }
    return root;
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->lcd);
        postorder(root->rcd);
        cout << root->data;
    }
}

// ^ layerorder
void Layerorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q1;
    q1.push(root);
    node *t;
    while (!q1.empty())
    {
        t = q1.front();
        cout << t->data;
        q1.pop();
        if (t->lcd != NULL)
        {
            q1.push(t->lcd);
        }
        if (t->rcd != NULL)
        {
            q1.push(t->rcd);
        }
    }
}
int main()
{
    string in1, pre1;
    cin >> pre1;
    cin >> in1;
    const char *pre = pre1.c_str();
    const char *in = in1.c_str();
    node *root = creat(in, pre, 0, (strlen(in) - 1), 0, (strlen(pre) - 1));
    postorder(root);
    cout << endl;
    Layerorder(root);
    return 0;
}
