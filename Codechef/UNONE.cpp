#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tc(x) \
    int x;    \
    cin >> x; \
    while (x--)
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

int32_t main()
{
    FIO;
    tc(t)
    {
        int n, temp;
        cin >> n;
        vector<int> evens, odds;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
            {
                evens.push_back(temp);
            }
            else
            {
                odds.push_back(temp);
            }
        }

        for (auto i : evens)
            cout << i << " ";
        for (auto i : odds)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}