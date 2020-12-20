#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findf(vector<long long int> nos)
{
    vector<long long int>::iterator i;
    int n=0;
    for(i= nos.begin();i!= nos.end();i++)
    {
        vector<long long int>::iterator j;
        for(j=i+1;j!=nos.end();j++)
        {
            auto place = upper_bound(j+1,nos.end(),(*i)+(*j));
            if(place!=nos.end())
            {
                cout<<i-nos.begin()+1<<" "<<j-nos.begin()+1<<" "<<place-nos.begin()+1<<endl;
                n=0;
                break;
            }
            else
            {
                n=1;
                break;
            }
            
        }
        if(n==1)
            continue;
        if(j!=nos.end())
            break;
    }
    if(i==nos.end())
        cout<<"-1"<<endl;
    
}
int main()
{
    vector<long long int> s;
    s.clear();
    long long int no;
    cin>>no;
    while(no--)
    {
        s.clear();
        int fl,x;
        cin>>fl;
        while(fl--)
        {
            cin>>x;
            s.push_back(x);
        }
        findf(s);
    }
}