#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void find_if_pl(vector<int> fl, int len)
{
    vector<int> :: iterator i;
    for(i=fl.begin();i<fl.end();i++)
    {
        if(find(i+2, fl.end(), *i) != fl.end())
        {
            cout<<"YES"<<endl;
            break;
        }
    }
    if(i==fl.end())
        cout<<"NO"<<endl;
}
int main()
{
    int x;
    vector<int> ar;
    cin>>x;
    while(x--)
    {
        int n,fl,l;
        cin>>n;
        l=n;
        ar.clear();
        while(n--)
        {
           cin>>fl;
           ar.push_back(fl); 
        }
        find_if_pl(ar,l);
    }
    return 0;
}