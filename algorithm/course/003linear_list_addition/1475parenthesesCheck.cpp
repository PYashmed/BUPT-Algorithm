#include <bits/stdc++.h>
using namespace std;
void check(string a)
{
    int top = 0;        // bottom of stack
    int n = a.length(); // length of string
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
        if (top < 0) // error ,appear a extra parenthese
        {
            cout << "Error";
            break;
        }
    }
    if (n == 0 && top == 0)
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