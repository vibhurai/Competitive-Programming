#include <bits/stdc++.h>
using namespace std;

void find_spread(vector<int> pos)
{
    int min=INT_MAX,max=INT_MIN,count;
    map<int,int> ho_ja;
    ho_ja.clear();
    
    for(auto i=0;i!=pos.size();i++)
    {
        count=1;
        ho_ja.clear();
        for(auto j=i+1;j!=pos.size();j++)//current index will overtake the successive indices with lesser speed
        {   
            if(pos[j]<pos[i])
            {
                count++;
                ho_ja[j]=1;
                // cts.insert(j);//insert into set
            }      
            else
              ho_ja[j]=0;
        }      
        //  for(auto h= ho_ja.begin();h!=ho_ja.end();h++)
        //         {
        //             cout<<h->first<<" - "<<h->second<<" ";
        //                 // cout<<"as";
        //         }a
        //    cout<<endl;     
        for(auto k=0;k!=i;k++)
        {   
            if(pos[k]>pos[i])//checking if a preceding index will overtake this index
                count++;//insert this index
            for(auto h= i+1;h!=pos.size();h++)
            {
                if(  pos[h]<pos[k])
                    count++;
                        // cout<<"as";
            }
           
        }        
        // cout<<count<<endl;        
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