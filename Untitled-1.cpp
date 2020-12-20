#include <bits/stdc++.h>
using namespace std;

void find_spread(vector<int> pos)
{
    int min=INT_MAX,max=INT_MIN,count;
    // map<int,set<int>> m; // map to contain all the indices and them directly affecting the other vals
    // m.clear();
    map<int,int> ho_ja;
    ho_ja.clear();
    // set<int> cts;//temporary container of all indices directly affected by any particular index
    
    for(auto i=0;i!=pos.size();i++)
    {
        count=1;
        ho_ja.clear();
        // vector<int> fl;
        // fl.clear();
        // cts.clear();
        for(auto j=i+1;j!=pos.size();j++)//current index will overtake the successive indices with lesser speed
        {    if(pos[j]<pos[i])
            {
                count++;
                ho_ja[j]=1;
                // cts.insert(j);//insert into set
            }      
            else
              ho_ja[j]=0;
        }      
        for(auto k=0;k!=i;k++)
        {   
            if(pos[k]>pos[i])//checking if a preceding index will overtake this index
            {
                // fl.push_back(1);
                // cts.insert(k);
                count++;//insert this index
            }
            else
            {
                for(auto h= ho_ja.begin();h!=ho_ja.end();h++)
                {
                    if(h->second == 0 && pos[h->first]<pos[k])
                        // count++;
                        cout<<"as";
                }
                // fl.push_back(0);
            }
        }        
        // for(auto k=0;k!=i;k++)
        //     if(fl[k]==1)        
        //     {    
        //         // cout<<i<<"-"<<k<<endl;
        //         for(auto x = m[k].begin();x!=m[k].end();x++)//iterate on the directly affected indices 
        //         {
        //             if(*x!=i)
        //             {
        //                 if(find(cts.begin(),cts.end(),*x)==cts.end())
        //                 {    
        //                     count++;   
        //                     // cout<<*x<<" ";
        //                 }
                        
        //             }
        //             // cout<<endl;  
        //         }
        //         //    cout<<endl; 
        //     }
            
        // for (auto k=0;k!=i;k++)                
                 
             
        // for(auto d= cts.begin();d!=cts.end();d++)
        //     cout<<*d<<" ";    
        // m[i]=cts; 
        // for(auto p=m.begin();p!=m.end();p++)
        // {
        //     // for(auto x = (p->second).begin();x!=(p->second).end();x++)
        //     //     cout<<*x<<" ";
        //     cout<<p->first<<" ";
        // }   
        cout<<endl;   
         
        cout<<count;        
        if(count>max)
            max = count;
        if (count<min)
        {
            min = count; 
            // cout<< i;
        }   

    }
    cout<<min<<" "<<max<<endl;
}

int main()
{
    int t,nos,fl;
    cin>>t;
    vector<int> a;
    while(t--)
    {
        cin>>nos;
        a.clear();
        while(nos--)
        {
            cin>>fl;
            a.push_back(fl);
        }
        find_spread(a);
    }
    return 0;
}