#include <bits/stdc++.h>
using namespace std;
int a[10000]; // record the location of queen in each row
int n, sum;
bool check(int k, int l)
{
    // if the location is available
    for (int i = 1; i < k + 1; i++)
    {
        if (a[i] == l || i + a[i] == k + l || i - a[i] == k - l)
        {
            // not in the same row or same column or in diagonal line
            return false;
        }
    }
    return true;
}
void queen(int t)
{
    // set queen in row t
    if (t == n + 1)
    {
        for (int i = 1; i < n + 1; i++)
        {
            cout << a[i]; // cout the answer
        }
        cout << endl;
        sum++; // answer ++
        return;
        // end of recursion
    }
    for (int i = 1; i <= n; i++)
    {
        // choose column
        if (check(t, i))
        {
            a[t] = i;
            queen(t + 1);
            a[t] = 0; // empty the board
        }
    }
}
int main()
{
    cin >> n;
    queen(1);
    cout << sum;
    return 0;
}