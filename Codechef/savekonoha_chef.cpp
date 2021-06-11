#include <bits/stdc++.h>
using namespace std;

int check(multiset<int> strengths, int z)
{
    int att=0,fl;
    if(strengths.lower_bound(z)!=strengths.end())
        return 1;
    while(z>0 && strengths.empty()==0)
    {
        z-=*strengths.rbegin();
        fl = *strengths.rbegin();
        strengths.erase(--strengths.end());
        if(fl/2 > 0)
            strengths.insert(fl/2);
        att++;    
    }
    if(z>0)
        return 0;
    else
        return att;    
}


int main()
{
    int x,z0,n0,fl;
    cin>>x;
    multiset<int> str;
    while(x--)
    {
        cin>>n0;
        cin>>z0;
        str.clear();
        while(n0--)
        {
            cin>>fl;
            str.insert(fl);
        }
        int ans = check(str,z0);
        if(ans==0)
            cout<<"Evacuate"<<endl;
        else
            cout<<ans<<endl;            
    }    
    return 0;
}





