#include <bits/stdc++.h>
using namespace std;

int data1[1001];
priority_queue<int, vector<int>, greater<int>> q; //^ ascending order queue

void huffman(int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> data1[i];
        q.push(data1[i]);
    }
    int ans = 0;
    while (q.size() >= 2)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push(a + b);
        ans += (a + b);
    }
    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    huffman(n);
    return 0;
}
