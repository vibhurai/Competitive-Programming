#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>n;
    vector<int> scores, a_scores, ranks;
    scores.clear();
    a_scores.clear();
    ranks.clear();
    while(n--)
    {   
        cin>>m;
        scores.push_back(m);
    }
    cin>>m;
    while(m--)
    {   
        cin>>n;
        a_scores.push_back(n);
    }
    vector<int>::iterator p=std::unique(scores.begin(),scores.end());
    scores.resize(std::distance(scores.begin(), p));   
    std::reverse(scores.begin(), p);
    int r;
    for(auto i=a_scores.begin();i<a_scores.end();i++)
    {
        p = lower_bound(scores.begin(),scores.end(),*i);
        if(*p==*i)
            r = scores.end() - p;
        else
            r = scores.end() - p+1;
        ranks.push_back(r);
    }
    for(auto l = ranks.begin();l<ranks.end();l++)
        cout<<*l<<endl;
    return 0;    
}