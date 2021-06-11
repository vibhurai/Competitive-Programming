#include<bits/stdc++.h>
using namespace std;

long long int find_hrs(vector<int> rk, long long int n, long long int p)
{
    std::sort(rk.begin(),rk.end(),greater<int>());
    long long int min = INT_MAX,sum=accumulate(rk.begin(),rk.end(),0),wsum;
    vector<int>::iterator ptr;
    // cout<< accumulate(rk.begin()+p,rk.end(),0)<<" ";
    wsum = accumulate(rk.begin(),rk.begin()+p,0);
    min = p*(*rk.begin()) - wsum;
    // cout<<wsum<<" ";
    for(auto i=rk.begin()+1;i+p<=rk.end();i++)
    {
        wsum = wsum - (*(i-1))+ (*(i+p-1))  ;             
        if(p*(*i)-wsum< min)
            min = p*(*i)-wsum;
    }
    return min;
}
int main()
{
    long long int x,N,P,fl,s;
    vector<int> rankss;
    rankss.clear();
    cin>>x;
    s=x;
    while(x--)
    {
        cin>>N>>P;
        rankss.clear();
        while(N--)
        {
            cin>>fl;
            rankss.push_back(fl);
        }        
        cout<<"Case #"<<s-x<<": "<<find_hrs(rankss,rankss.size(),P)<<endl;
    }
    return 0;
}