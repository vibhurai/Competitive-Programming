#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,count=0,i=0,j,v,c;
    vector<int> a,b,sum;
    cin>>n>>m;
    a.clear();
    b.clear();
    sum.clear();
    v=n;
    c=m;
    while (v--)
    {
        cin>>j;
        a.push_back(j);
    }
    while (c--)
    {
        cin>>j;
        b.push_back(j);
    }
    while(count < n+m-1)
    {
        for(j=0;j<m;j++)
            if(count<n+m-1)
            {    if(sum.empty()==1)
                {
                    sum.push_back(a[i]+b[j]);
                    cout<<i<<" "<<j<<endl;
                    count++;
                } 
                else if(std::find(sum.begin(),sum.end(),a[i]+b[j]) == sum.end() )
                {
                    sum.push_back(a[i]+b[j]);
                    cout<<i<<" "<<j<<endl;
                    count++;
                } 
            }    
            else
                break;
        if(j<m)
            break;        
        i++;  
    }
    return 0;
}