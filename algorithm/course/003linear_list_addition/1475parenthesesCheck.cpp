#include <bits/stdc++.h>
using namespace std;
void check(string a)
{
    int top = 0;
    int n = a.length();
    while (n)
    {
        n--;
        if (a[n] == ')')
        {
            top++;
        }
        if (a[n] == '(')
        {
            top--;
        }
        if (top < 0)
        {
            cout << "Error";
            break;
        }
    }
    if (n == 0 && top ==0)
    {
        cout << "OK";
    }
}

int main()
{
    string a;
    getline(cin, a);
    check(a);
    return 0;
}