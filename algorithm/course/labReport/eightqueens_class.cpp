#include <bits/stdc++.h>
using namespace std;
class queen
{
private:
    int m;
    int p[100000]; // record the location of queen in each row

public:
    queen(int);
    void setqueen(int);
    int check(int, int);
};
queen::queen(int n)
{
    m = n;
}
void queen::setqueen(int i)
{
    // set queen
    if (i == m)
    {
        // end of recursion
        for (int k = 0; k < m; k++)
        {
            cout << p[k];
        }
        cout << endl;
        return;
    }
    for (int b = 0; b < m; b++)
    {
        // set every row
        if (queen::check(i, b))
        {
            // check if position b in row i is available
            p[i] = b;
            setqueen(i + 1);
            p[i] = 0; // empty the board
        }
    }
}
int queen::check(int k, int l)
{
    // for (int i = 0; i < m; i++)
    for (int i = 0; i < k; i++)
    {
        // check each row
        if (p[i] == l || i + p[i] == k + l || i - p[i] == k - l)
        {
            // not in same row or same column or in diagonal line
            return 0;
        }
    }
    return 1;
}
int main()
{
    int h;
    cin >> h;
    queen ans(h);
    ans.setqueen(0);
    return 0;
}
