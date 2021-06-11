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
        int D, d, P, Q;
        cin >> D >> d >> P >> Q;

        int n = D / d, ans = 0;

        ans = n * d * P + d * Q * n * (n - 1) / 2;
        ans += (D % d) * (P + n * Q);
        cout << ans << endl;
    }

    return 0;
}