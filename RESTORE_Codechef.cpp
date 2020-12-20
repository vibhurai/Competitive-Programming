#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int>::iterator ptr;
#define all(v) v.begin(), v.end() 
// typedef unsigned long long int int; 
void find_seq(vector<int> b)
{
    int seq[b.size()];  
    unordered_map<int, list<int>> reln;

    //determining all the relations
    for(auto i=b.begin();i<b.end();i++)
    {
        if(reln.find(*i)==reln.end())
        {
            reln[*i].push_back(i-b.begin());
            auto flg = i+1;
            while(find(flg,b.end(),*i)!=b.end())
            {
                auto temp=find(flg,b.end(),*i);
                reln[*i].push_back(temp-b.begin());
                flg=temp+1;
            }
        }
        else 
            continue;
    } 
    //  for(auto it = reln.begin();it!=reln.end();it++)
    // {
    //     cout<<(*it).first<<"=";
    //     for (auto m=(*it).second.begin();m!=(*it).second.end();m++)
    //     {
    //         cout<<*m<<"->";
    //     }
    //     cout<<endl;
    // }
    
    for(auto it = reln.begin();it!=reln.end();it++)
    {
        for (auto m=(*it).second.begin();m!=(*it).second.end();m++)
        {
            seq[*m]=*ptr;
        }
        ptr++;
    }
    
    for(auto v =0;v!=b.size();v++)
        cout<< seq[v]<<" ";
    cout<<endl;   

}

vector<int> sieve(int n) 
{ 
    // Create a boolean vector "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // Not a prime, else true. 
    vector<bool> prime(n + 1, true); 

    prime[0] = false; 
    prime[1] = false; 
    int m = sqrt(n); 

    for (int p = 2; p <= m; p++) { 

        // If prime[p] is not changed, then it 
        // is a prime 
        if (prime[p]) { 

            // Update all multiples of p 
            for (int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 

    // push all the primes into the vector ans 
    vector<int> ans; 
    for (int i = 0; i < n; i++) 
        if (prime[i]) 
            ans.push_back(i); 
    return ans; 
} 

vector<int> sieveRange(int start, int end) 
{ 
    // find primes from [0..end] range 
    vector<int> ans = sieve(end); 

    // Find index of first prime greater than or 
    // equal to start 
    // O(sqrt(n)loglog(n)) 
    int lower_bound_index = lower_bound(all(ans), start) - 
                                            ans.begin(); 

    // Remove all elements smaller than start. 
    // O(logn) 
    ans.erase(ans.begin(), ans.begin() + lower_bound_index); 

    return ans; 
} 

// Driver Program to test above function 



  
int main()
{
    int t,n,temp;
    int start = 1; 
    int end = 10000; 
    ans = sieveRange(start,end); 
    ptr=ans.begin();
    cin>>t;
    vector<int> b;
    while(t--)
    {
        cin>>n;
        b.clear();
        while(n--)
        {
            cin>>temp;
            b.push_back(temp);
        }
        find_seq(b);
    }
    // for (auto i : ans) 
    //     cout << i << ' '; 
    return 0;
}