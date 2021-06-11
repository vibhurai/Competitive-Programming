#include <bits/stdc++.h>
using namespace std;

void find_ans(long long int a, long long int b)
{
    long long int ans=0,small,big;
    if(a<b)
    {
        small=a;
        big=b;
    }
    else
    {
        small=b;
        big=a;
    }

    if(small%2==0) //division 2 will give no of even as well as odd
    {
        if(big%2==0)
            ans+=2*((small/2)*(big/2));//count even
        else
        {
            ans+=(small/2)*(big/2);//count even
            ans+=(small/2)*((big/2)+1);//count odd
        }  
    }
    else //division 2 will give no of even and odd-1
    {
        ans+=((small/2)*(big/2));//count even
        
        //count odd
        if(big%2==0)
            ans+=((small/2)+1)*(big/2);
        else
            ans+=((small/2)+1)*((big/2)+1);    
    }

    cout<<ans<<endl;       
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int A,B;
        cin>>A>>B;
        find_ans(A,B);
    }
    return 0;
}