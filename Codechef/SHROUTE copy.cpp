#include <bits/stdc++.h>
using namespace std;

// vector<long long> find_res(vector<long long> a, vector<long long> b)
// {
//     vector<long long> res;
//     res.clear();

//     for (auto i = b.begin(); i != b.end(); i++)
//     {
//         // cout<<a[*i - 1]<<" ";
//         // cout<<a[*i-1]<<" ";

//         if (a[*i - 1] != 0)
//         {
//             res.push_back(0);
//             continue;
//         }

//         // cout<<*(a.begin() + (*i));
//         // cout<<*(a.begin() + ((*i) - 2));

//         auto right = find(a.begin() + (*i), a.end(), 2);
//         // cout<<"*right = "<<*right<<endl;

//         auto left = find(a.begin(), a.begin() + ((*i) - 1), 1);
//         // cout<<"*left = "<<*left<<endl;

//         if (*right != 2 && *left != 1)
//         {
//             res.push_back(-1);
//             continue;
//         }

//         long long r_margin, l_margin;
//         if (*right == 2)
//             r_margin = right - (a.begin() + (*i - 1));
//         else
//             r_margin = INT_MAX;
//         // cout<<"r_margin = "<<r_margin<<endl;

//         if (*left == 1)
//             l_margin = (a.begin() + *i - 1) - left;
//         else
//             l_margin = INT_MAX;
//         // cout<<"l_margin = "<<l_margin<<endl;

//         if (r_margin > l_margin)
//             res.push_back(l_margin);
//         else
//             res.push_back(r_margin);
//     }

//     return res;
// }

vector<long long> find_res_take_2(vector<long long> a, vector<long long> b)
{
    vector<long long> res, cmpA, cmpB;

    res.clear();
    cmpA.clear();
    cmpB.clear();

    // Filling distance when trying to reach using a train travelling towards right
    for (auto i = a.begin(); i != a.end(); i++)
    {
        if (*i == 1 || *i == 2)
        {
            cmpA.push_back(0);
            continue;
        }

        if (i == cmpA.begin() || *(i - 1) == -1)
            cmpA.push_back(-1);
        else
            cmpA.push_back(*(i - 1) + 1);
    }

    // Filling distance when trying to reach using a train travelling towards left
    for (auto i = a.rbegin(); i != a.rend(); i++)
    {
        if (*i == 1 || *i == 2)
        {
            cmpB.push_back(0);
            continue;
        }

        if (i == cmpB.rbegin() || *(i - 1) == -1)
            cmpB.push_back(-1);
        else
            cmpB.push_back(*(i - 1) + 1);
    }

    // Reverse cmpB
    reverse(cmpB.begin(), cmpB.end());
    int min = INT_MAX;

    for (auto i = 0; i < b.size(); i++)
    {
        if (cmpA[b[i] - 1] == -1 && cmpB[b[i] - 1] == -1)
        {
            res.push_back(-1);
            continue;
        }

        if (cmpA[b[i] - 1] != -1 && cmpB[b[i] - 1] != -1)
        {
            res.push_back(cmpA[b[i] - 1] < cmpB[b[i] - 1] ? cmpA[b[i] - 1] : cmpB[b[i] - 1]);
            continue;
        }

        res.push_back(cmpA[b[i] - 1] < cmpB[b[i] - 1] ? cmpB[b[i] - 1] : cmpA[b[i] - 1]);
    }

    return res;
}

int main()
{
    long long test, N, M, temp;
    vector<long long> A, B, result;

    cin >> test;

    while (test--)
    {
        cin >> N >> M;

        A.clear();
        B.clear();
        result.clear();
        while (N--)
        {
            cin >> temp;
            A.push_back(temp);
        }

        while (M--)
        {
            cin >> temp;
            B.push_back(temp);
        }

        result.clear();
        result = find_res_take_2(A, B);

        for (auto i = result.begin(); i != result.end(); i++)
            std::cout << *i << endl;
    }
    return 0;
}
