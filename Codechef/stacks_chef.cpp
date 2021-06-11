#include<bits/stdc++.h>
using namespace std;

void find_stack(vector<int> order)
{
    vector<int> st;
    st.clear();
    for(auto i=order.begin();i!=order.end();i++)
    {
        if(st.empty() || upper_bound(st.begin(),st.end(),*i)==st.end())
        {
            st.push_back(*i);
        }
        else
        {
            auto fl = upper_bound(st.begin(),st.end(),*i);
            st.erase(fl);
            st.emplace(fl,*i);
        }        
    }
    cout<<st.size()<<" ";
    for(auto j=st.begin();j!=st.end();j++)
        cout<<*j<<" ";
    cout<<endl;        
}
int main()
{
    int x,size,fl;
    vector<int> a;
    cin>>x;
    while(x--)
    {
        cin>>size;
        a.clear();
        while(size--)
        {
            cin>>fl;
            a.push_back(fl);
        }
        find_stack(a);
    }
    return 0;
}
