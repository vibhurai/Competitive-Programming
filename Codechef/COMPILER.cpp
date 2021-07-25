#include <bits/stdc++.h>
using namespace std;

int find_longest_valid_subs(string inp)
{
    stack<int> s;
    int longest_len = 0;

    for (auto i = 0; i != inp.size(); i++)
    {
        if (inp[i] == '<')
            s.push(i);
        else
        {
            if (!s.empty())
            {
                if (i - s.top() > longest_len)
                    longest_len = (i - s.top()) + 1;

                s.pop();
            }
        }
    }

    return longest_len;
}

int main()
{
    int t;
    cin >> t;

    string inp;

    while (t--)
    {
        inp.clear();
        cin >> inp;

        cout << find_longest_valid_subs(inp) << endl;
    }
}