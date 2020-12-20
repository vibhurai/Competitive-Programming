#include <bits/stdc++.h>
using namespace std;

void findd(string s, string p)
{
    
    
    if(s.find(p)==string::npos)
    {
        vector<char> str(s.begin(),s.end());
        vector<char> patt(p.begin(),p.end());
        for(auto i=patt.begin();i!=patt.end();i++)
        {
            auto flag= find(str.begin(), str.end(),*i);
            str.erase(flag);
        }
        sort(str.begin(),str.end());
        auto fl=upper_bound(str.begin(),str.end(),*patt.begin());
        str.insert(fl, patt.begin(), patt.end());        
        for (auto t = str.begin(); t != str.end() ; ++t) 
                cout << *t;
        cout<<endl;     
    }
    else
    {      
        auto fl = s.find(p);
        s.erase(fl,fl+p.size()-1);
        vector<char> str(s.begin(),s.end());
        vector<char> patt(p.begin(),p.end());
        sort(str.begin(),str.end());
        auto fll=upper_bound(str.begin(),str.end(),*patt.begin());
        str.insert(fll, patt.begin(), patt.end());
        for (auto t = str.begin(); t != str.end() ; ++t) 
                cout << *t;
        cout<<endl;     
    }
}
int main()
{
    int x;
    cin>>x;
    string S,P;
    S.clear();
    P.clear();
    while(x--)
    {
        cin>>S>>P;
        findd(S,P);        
    }
}









// #include <bits/stdc++.h>
// using namespace std;

// void findd(string s, string p)
// {
//     vector<char> str(s.begin(),s.end());
//     vector<char> patt(p.begin(),p.end());
//     for(auto i=patt.begin();i!=patt.end();i++)
//     {
//         auto flag= find(str.begin(), str.end(),*i);
//         str.erase(flag);
//     }
//     sort(str.begin(),str.end());
//     auto fl=upper_bound(str.begin(),str.end(),*patt.begin());
//     str.insert(fl, patt.begin(), patt.end());
//     for (auto it = str.begin(); it != str.end(); ++it) 
// 		cout << *it;
//     cout<<endl;     
// }
// int main()
// {
//     int x;
//     cin>>x;
//     string S,P;
//     S.clear();
//     P.clear();
//     while(x--)
//     {
//         S.clear();
//         P.clear();
//         cin>>S>>P;
//         findd(S,P);        
//     }
// }

