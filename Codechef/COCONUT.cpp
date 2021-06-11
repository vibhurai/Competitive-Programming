#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, xa, xb, XA, XB;
    cin >> test;
    while (test--)
    {
        cin >> xa >> xb >> XA >> XB;
        cout << ceil(XA / xa) + ceil(XB / xb) << endl;
    }
}