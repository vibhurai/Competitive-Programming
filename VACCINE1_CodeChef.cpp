#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d1,v1,d2,v2,p,final=0,produced=0,small,big,small_v,big_v;
    cin>>d1>>v1>>d2>>v2>>p;
    
    //adding non-production days
    if(d1<d2)
    {
        final+=d1-1;
        small=d1;
        small_v=v1;
        big= d2;
        big_v=v2;
    }    
    else    
    {    
        final+=d2-1;
        small=d2;
        small_v=v2;
        big= d1;
        big_v=v1;
    }
   

    if(small_v*(big-small) >=p)
    {
        if(small_v*(big-small) ==p)
            final=big-1;
        else
            final+=p/small_v;
    }
    
    else
    {
        int left = p-small_v*(big-small); //calculating left over medicines to be produced
        final=(big-1)+left/(v1+v2);
        if(left%(v1+v2)!=0)
            final++;
    }      

    cout<<final<<endl;
    
    return 0;
}