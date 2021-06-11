#include <bits/stdc++.h>
using namespace std;

int call_fn(int l, int r, string st, int k)
{
    int count=(r-l+1)*(r-l+2)/2;

    return count;
}
int main()
{
    int x,N,K,Q,L,R;
    string str;
    cin>>x;
    while(x--)
    {
        cin>>N>>K>>Q;
        cin>>str;        
        while(Q--)
        {
            cin>>L>>R;
            cout<<call_fn(L,R,str,K)<<endl;
        }
    }
}