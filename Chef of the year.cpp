#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    map<string, int> chef_score,country_score;
    map<string,string> names; // chef-> country 
    string a,b;
    chef_score.clear();
    country_score.clear();
    names.clear();
    cin>>n>>m;
    while(n--)
    {
        cin>>a>>b;
        names[a]=b;
    }
    while(m--)
    {
        cin>>a;
        chef_score[a]++;
        country_score[names[a]]++;   
    }

    int max = chef_score.begin()->second;
    a = chef_score.begin()->first;
    for (auto itr = chef_score.begin(); itr != chef_score.end(); ++itr) 
        if(itr->second > max)
        {   
            max =  itr->second;
            a = itr->first;
        }    

    max = country_score.begin()->second;
    b = country_score.begin()->first;
    for (auto itr = country_score.begin(); itr != country_score.end(); ++itr) 
        if(itr->second > max)
        {   
            max =  itr->second;
            b = itr->first;
        }     
    cout<<b<<endl<<a;   

    //  for (auto itr = chef_score.begin(); itr != chef_score.end(); ++itr) 
    //     cout<<itr->first<<" "<<itr->second<<endl;

    // for (auto itr = names.begin(); itr != names.end(); ++itr) 
    //     cout<<itr->first<<" "<<itr->second<<endl;    
    // cout<<endl;
     
    //  for (auto itr = country_score.begin(); itr != country_score.end(); ++itr) 
    //     cout<<itr->first<<" "<<itr->second<<endl;   
}