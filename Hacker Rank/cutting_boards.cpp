#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the boardCutting function below.
int boardCutting(vector<long long> cost_y, vector<long long> cost_x) {
        
    //y is horizontal cuts, x is vertical cuts
    multiset<long long,std::greater<int>> s;
    std::vector<long long>::iterator p;
    
    long long v_cuts=1,h_cuts=1,c=0;
    long long cost=0;
    //c=0 for horizontal cut to be made , c=1 for vertical cut to be made
    s.clear();
    
    for(auto i=cost_y.begin();i!=cost_y.end();i++)
        s.insert(*i);
    for(auto i=cost_x.begin();i!=cost_x.end();i++)
        s.insert(*i);   
    for(auto j=s.begin();j!=s.end();j++)
    {
        if(find(cost_y.begin(),cost_y.end(),*j)!=cost_y.end())
        {
            p = find(cost_y.begin(),cost_y.end(),*j);
            cost_y.erase(p);
            c=0;
            h_cuts++;
        }    
        else
        {
            p = find(cost_x.begin(),cost_x.end(),*j);
            cost_x.erase(p);
            c=1;
            v_cuts++;
        }   
        // cout<<v_cuts<<" "<<h_cuts<<endl;     
        if(c==0)
        {
            cost+=(*j)*v_cuts;
            // cout<<(*j)*v_cuts<<" "<<endl;
        }    
        else
        {
            cost+=(*j)*h_cuts;
            // cout<<(*j)*h_cuts<<" "<<endl;
        }
        // cout<<*j<<" ";                
        // cout<<cost<<" ";    
    }
    return cost % (1000000000+7);
}

int main()
{
    long long x,xsiz,ysiz,fl;
    cin>>x;
    vector<long long> c_x,c_y;
    c_x.clear();
    c_y.clear();

    while(x--)
    {
        c_x.clear();
        c_y.clear();
        cin>>ysiz>>xsiz;
        ysiz--;
        xsiz--;
        while(ysiz--)
        {
            cin>>fl;
            c_y.push_back(fl);
        }
        while(xsiz--)
        {
            cin>>fl;
            c_x.push_back(fl);
        }
        cout<<boardCutting(c_y,c_x)<<endl;
    }
}    