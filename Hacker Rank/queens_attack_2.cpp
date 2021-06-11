#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<pair<ll ,ll>> rs,cs;
    ll n,k,rq,cq,f1,f2,r_l=0,r_r=0,c_u=0,c_d=0,total=0;
    cin>>n>>k>>rq>>cq;
    while(k--)
    {
        cin>>f1>>f2;
        rs.push_back(make_pair(f1,f2));
        cs.push_back(make_pair(f2,f1));
    }
    sort(rs.begin(),rs.end());//klogk
    sort(cs.begin(),cs.end());
    
    int rf=0,lf=0;
    auto x = lower_bound(rs.begin(),rs.end(),make_pair(rq,cq));
    
    //the queen is in the upper most row
    if(x==rs.end()) 
        rf=1;
    
    if(x!=rs.begin())
    {
        if((x-1)->first==rq)
            r_l = cq-(x-1)->second-1;
        else    
            r_l = cq-1;
    }
    else
        r_l = cq-1;
    
    if(rf!=1)
    {
        if((x)->first==rq)
            r_r = (x)->second-cq-1;
        else    
            r_r = n-cq;
        
    }
    else 
    {
        if(cq!=n)
           r_r = n-cq;
    }
    
    // cout<<r_l<<r_r<<endl;
    total+=r_l+r_r;

    //the queen is in the right most column
    x = lower_bound(cs.begin(),cs.end(),make_pair(cq,rq));
    
    if(x==cs.end()) 
        rf=1;
    
    if(x!=cs.begin())
    {
        if((x-1)->first==cq)
            c_d = rq-(x-1)->second-1;
        else    
            c_d = rq-1;
    }
    else
        c_d = rq-1;    

    if(rf!=1)
    {
        if((x)->first==cq)
            c_u = (x)->second-rq-1;
        else    
            c_u = n-rq;     
    }
    else 
    {
        if(rq!=n)
           c_u = n-rq;
    }
    // cout<<c_u<<c_d<<endl;    
    total+=c_d+c_u;

    //checking diagonals cuts above the queen
    ll u_l,u_r=n-cq,u_lb=0,u_rb=0;

    if(n-rq>cq-1)
        u_l =cq-1;
    else
        u_l =n-rq;

    if(n-cq >n-rq)
        u_r = n-rq;
    else
        u_r = n-cq;     
    // cout<<u_l<<" "<<u_r;

    
    x = lower_bound(rs.begin(),rs.end(),make_pair(rq,cq));
    for(x;x!=rs.end();x++)
    {
        if(u_lb==1 && u_rb==1)
            break;
        if(x->first==rq)
            continue;
        else
        {
            if(x->second < cq)
            {
                
                if(u_lb!=1)
                {
                    if(cq-(x->second)==x->first-rq)
                    {
                        u_l=cq-(x->second)-1;
                        u_lb=1;
                    }
                }
                else
                    continue;                 
            }
            else if(x->second > cq)
            {
                if(u_rb!=1)
                {
                    if(x->second-cq==x->first-rq)
                    {
                        u_r=x->second-cq-1;
                        u_rb=1;
                    }
                }
                else
                    continue;
            }
            else
                continue;
        }
            
    }
    total+=(u_l+u_r);

    //checking diagonals cuts below the queen 
    ll d_l,d_r,d_lb=0,d_rb=0;

    if(rq-1>cq-1)
        d_l =cq-1;
    else
        d_l =rq-1;
    // cout<<d_l;
    if(n-cq >rq-1)
        d_r = rq-1;
    else
        d_r = n-cq;     

    // cout<<d_l<<d_r;

       
    
    if(rs.size()!=0)
    {
        x = lower_bound(rs.begin(),rs.end(),make_pair(rq,cq));
        for(x;x>=rs.begin();x--)
        {
            if(d_lb==1 && d_rb==1)
                break;
            if(x->first==rq)
                continue;
            else
            {
                if(x->second < cq)
                {
                    
                    if(d_lb!=1)
                    {
                        if(cq-(x->second)==rq-x->first)
                        {
                            d_l=cq-(x->second)-1;
                            d_lb=1;
                        }
                    }
                    else
                        continue;                 
                }
                else if(x->second > cq)
                {
                    if(d_rb!=1)
                    {
                        if(x->second-cq==rq-x->first)
                        {
                            d_r=x->second-cq-1;
                            d_rb=1;
                        }
                    }
                    else
                        continue;
                }
                else
                    continue;
            }
                
        }

    }
    total +=(d_l+d_r);
    cout<<total;
    return 0;
}