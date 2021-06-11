#include <bits/stdc++.h>
using namespace std;

vector<long long> find_res(vector<long long> a, vector<long long> b)
{
    vector<long long> res;
    res.clear();

    for (auto i = b.begin(); i != b.end(); i++)
    {
        // cout<<a[*i - 1]<<" ";
        // cout<<a[*i-1]<<" ";file

        if (a[*i - 1] != 0)
        {
            res.push_back(0);
            continue;
        }

        // cout<<*(a.begin() + (*i));
        // cout<<*(a.begin() + ((*i) - 2));

        auto right = find(a.begin() + (*i), a.end(), 2);
        // cout<<"*right = "<<*right<<endl;

        auto left = find(a.begin(), a.begin() + ((*i) - 1), 1);
        // cout<<"*left = "<<*left<<endl;

        if (*right != 2 && *left != 1)
        {
            res.push_back(-1);
            continue;
        }

        long long r_margin, l_margin;
        if (*right == 2)
            r_margin = right - (a.begin() + (*i - 1));
        else
            r_margin = INT_MAX;
        // cout<<"r_margin = "<<r_margin<<endl;

        if (*left == 1)
            l_margin = (a.begin() + *i - 1) - left;
        else
            l_margin = INT_MAX;
        // cout<<"l_margin = "<<l_margin<<endl;

        if (r_margin > l_margin)
            res.push_back(l_margin);
        else
            res.push_back(r_margin);
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
        result = find_res(A, B);

        for (auto i = result.begin(); i != result.end(); i++)
            std::cout << *i << endl;
        // cout<<endl<<endl;
    }
    return 0;
}

// vector<long long> find_res_take_2(unordered_map<long long, long long> a, vector<long long> b)
// {
//     vector<long long> res;
//     res.clear();

//     for (auto i = b.begin(); i != b.end(); i++)
//     {
//         // cout<<a[*i - 1]<<" ";
//         // cout<<a[*i-1]<<" ";
//         if (*i == INT_MAX)
//             continue;

//         // cout<<*(a.begin() + (*i));
//         // cout<<*(a.begin() + ((*i) - 2));

//         auto lb = lower_bound(a.begin(), a.end(), *i);

//         auto right = INT_MAX;
//         if (lb->second == 2)
//             right = lb->first - (*i);

//         else
//         {
//             auto temp = lb;
//             while (temp != a.end())
//             {
//                 if (temp->second == 2)
//                 {
//                     right = temp->first - (*i);
//                     break;
//                 }
//                 temp++;
//             }
//         }

//         auto temp = lb;
//         // temp--;

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

// int main()
// {
//     long long test, N, M, temp, count;
//     unordered_map<long long, long long> A_map;
//     vector<long long> B, result;

//     cin >> test;

//     while (test--)
//     {
//         cin >> N >> M;
//         A_map.clear();
//         B.clear();
//         count = 0;

//         while (N--)
//         {

//             count++;
//             cin >> temp;
//             if (temp != 0)
//                 A_map[count] = temp;
//         }

//         while (M--)
//         {
//             cin >> temp;
//             if (A_map[temp] != 0)
//                 B.push_back(INT_MAX);
//             else
//                 B.push_back(temp);
//         }

//         result.clear();
//         result = find_res_take_2(A_map, B);

//         for (auto i = result.begin(); i != result.end(); i++)
//             std::cout << *i << endl;
//     }
// }