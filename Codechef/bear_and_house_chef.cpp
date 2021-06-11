#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sq_base,tri_top, tri_base;
    int low=0,high=1000,mid;
    string s1;

    //finding the base coordinate of the square (on the x axis)
    while(low<=high)
    {
        mid = low+(high-low)/2;
        cout<<"? "<<mid<<" "<<0<<endl;
        fflush(stdout);
        cin>>s1;
        if(s1.compare("YES")==0)
        {
            sq_base=mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }

    //finding the top of the triangle
    low=2*sq_base;
    high = 1000;
    while(low<=high)
    {
        mid = low+(high-low)/2;
        cout<<"? "<<0<<" "<<mid<<endl;
        fflush(stdout);
        cin>>s1;
        if(s1.compare("YES")==0)
        {
            tri_top=mid;
            low = mid+1;
        }
        else
            high = mid-1;        
    }

    //finding the base tip of the triangle
    low=sq_base;
    high = 1000;
    while(low<=high)
    {
        mid = low+(high-low)/2;
        cout<<"? "<<mid<<" "<<2*sq_base<<endl;
        fflush(stdout);
        cin>>s1;
        if(s1.compare("YES")==0)
        {
            tri_base=mid;
            low = mid+1;
        }
        else
            high = mid-1;        
    }
    cout<<"!"<<" "<<(4*sq_base*sq_base) + (tri_base*(tri_top-(2*sq_base)));
    return 0;
}