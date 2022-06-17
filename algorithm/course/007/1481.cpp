#include <bits/stdc++.h>
using namespace std;
int x;
int search(int *a, int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n;

    while (low <= high)
    {
        x++;
        mid = (low + high) / 2;
        if (key < a[mid])
        {
            high = mid - 1;
        }
        else if (key > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int a;
    cin >> a;
    int b[a];
    for (int i = 0; i < a; i++)
    {
        cin >> b[i];
    }
    int key;
    cin >> key;
    search(b, a - 1, key);
    cout << x;
    return 0;
}
