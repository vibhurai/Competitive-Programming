#include <bits/stdc++.h>
using namespace std;

int find_time(vector<int> c)
{
    int count =*(c.end()-1),dif=*(c.end()-1)-(*(c.end()-2));
    auto itr = c.end()-3;
    while(itr>=c.begin())
    {
        if(dif>=*itr)
        {
            
            int initial_sum=*(c.end()-1)-accumulate(itr, c.end()-1, 0);
            if(initial_sum <=0)
                dif=0;
            else
            {
                dif=initial_sum;
            }
            itr--;
            continue;
        }
        else
        {
            count+=(*itr)-dif;
            dif=(*itr)-dif;
            itr--;
        }
    }
    
    return count; 
}
int main()
{
    int t,n,flag;
    vector<int> c;
    cin>>t;
    while(t--)
    {
        c.clear();
        cin>>n;
        while(n--)
        {
            cin>>flag;
            c.push_back(flag);
        }
        sort(c.begin(),c.end());
        cout<<find_time(c)<<endl;
    }    
    return 0;
}