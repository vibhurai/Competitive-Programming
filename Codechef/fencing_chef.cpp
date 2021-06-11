#include<bits/stdc++.h>
using namespace std;

void find_fence(set<pair<int,int>> co, int n, int m, int k)
{
    int fl=0;
    for(auto i=co.begin(); i!=co.end();i++)
    {
        if(co.find(pair<int,int>(i->first+1,i->second))==co.end() || (i->first+1)>n)
            fl++;
        if(co.find(pair<int,int>(i->first-1,i->second))==co.end() || (i->first-1)==0)
            fl++;
        if(co.find(pair<int,int>(i->first,i->second+1))==co.end() || (i->second+1)>m)
            fl++;
        if(co.find(pair<int,int>(i->first,i->second-1))==co.end() || (i->second-1)==0)
            fl++;                    
    }
    cout<<fl<<endl;
}
int main()
{
    int t,N,M,K,r,c;
    set< pair<int,int>> s;
    pair<int, int> fl;
    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>N>>M>>K;
        while(K--)
        {
            cin>>r>>c;
            fl=make_pair(r,c);
            s.insert(fl);
        }
        find_fence(s,N,M,K);
    }
}