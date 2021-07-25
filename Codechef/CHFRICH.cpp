#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, A, B, X;
    cin >> t;
    vector<int> c;

    while (t--)
    {
        cin >> A >> B >> X;
        cout << (B - A) / X;
    }
}
