#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <conio.h>
using namespace std;

// #define int long long
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

int main()
{
    // FIO;
    tc(t)
    {
        string tag;
        cin >> tag;

        if (tag[0] != '<' || tag[1] != '/' || tag.back() != '>' || tag.length() <= 3)
        {
            cout << "Error";
        }
        else
        {
            bool check = true;
            for (int i = 2; i < tag.length() - 1; i++)
            {
                if ((tag[i] >= '0' && tag[i] <= '9') || (tag[i] >= 'a' && tag[i] <= 'z'))
                {
                    continue;
                }
                check = false;
                break;
            }

            if (check)
                cout << "Success";
            else
                cout << "Error";
        }
        cout << endl;
    }

    return 0;
}