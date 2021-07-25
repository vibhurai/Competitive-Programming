#include <bits/stdc++.h>
using namespace std;

int min_res(string shots, int n)
{
    int count_A = 0, count_B = 0;

    for (auto i = 0; i < shots.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (shots[i] == '1')
                count_A++;
        }
        else
        {
            if (shots[i] == '1')
                count_B++;
        }

        if (i % 2 != 0)
        {
            if (count_B > ((shots.size() - (i + 1)) / 2) + count_A)
                return (i + 1);

            if (count_A > ((shots.size() - (i + 1)) / 2) + count_B)
                return (i + 1);
        }
        else
        {
            if (count_B > (shots.size() - (i + 1)) + count_A)
                return (i + 1);

            if (count_A > (shots.size() - (i + 1)) + count_B)
                return (i + 1);
        }
    }

    return n * 2;
}

int main()
{
    int t, N;
    cin >> t;

    string shoots;

    while (t--)
    {
        shoots.clear();
        cin >> N;
        cin >> shoots;

        cout << min_res(shoots, N) << endl;
    }

    return 0;
}