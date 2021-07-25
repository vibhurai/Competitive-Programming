#include <bits/stdc++.h>
using namespace std;

#define int long long
#define t(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int32_t main()
{
    FIO;
    t(t)
    {
        int a, b;
        cin >> a >> b;
        double x = log2(b);
        int y = log2(b);
        if (x == y)
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }
    return 0;
}