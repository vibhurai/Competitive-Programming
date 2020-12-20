#include <bits/stdc++.h>
using namespace std;

void find_min_time(map<int, int> a, set<int> v, set<int> w ) 
{
    int min=INT_MAX;
    for(auto it = a.begin(); it!=a.end();it++)
    {
        auto fl = w.end();
        fl--;
        if(*(v.begin()) > it->first || *(fl) < it->second)
            continue;
        auto xit = v.lower_bound(it->first);
        if((*xit) != (it->first))
            xit--;
        auto yit = w.lower_bound(it->second);  
        if((*yit - *xit +1) < min)   
            min = (*yit - *xit +1);
    }
    cout<<min<<endl;
}

int main()
{
    map<int, int> times;
    set<int> entry_times, exit_times;

    times.clear();
    int n,x,y;
    cin>>n>>x>>y;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        times[a]=b;
    } 
    while(x--)
    {
        int a;
        cin>>a;
        entry_times.insert(a);
    }
    while(y--)
    {
        int a;
        cin>>a;
        exit_times.insert(a);
    }
    find_min_time(times, entry_times, exit_times);

    return 0;
}