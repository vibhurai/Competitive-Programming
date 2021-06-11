#include<unordered_map>
#include<iostream>


using namespace std;


int main()
{
    int p,c,l;
    int b,s;
    cin>>p>>c>>l>>b>>s;
    int maxi=0;
    if(b>s)
    {
        int p2=0;
        int p1=min(p/2,c);
        if(p1!=p/2)
            p2=min(p/2-c,l);
        maxi=p1*b+p2*s;
    }
    else
    {
        int p2=0;
        int p1=min(p/2,l);
        if(p1!=p/2)
            p2=min(p/2-l,c);
        maxi=p1*s+p2*b;
    }
      cout<<maxi<<"\n";
 }
}