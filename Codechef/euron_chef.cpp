#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
 

ll merge(ll arr[],ll l,ll mid,ll r)
{
	ll count = 0;
	ll pt1 = l;
	ll pt2 = mid+1;
	ll auxarr[r-l+1];
	ll arrpt = -1;
	while(pt1<=mid && pt2<=r)
	{
		if(arr[pt1] <= arr[pt2])
		{
			auxarr[++arrpt] = arr[pt1];
			pt1++;
		}
		else
		{
			auxarr[++arrpt] = arr[pt2];
			//cout<<mid<<" "<<pt1<<endl;
			count = count + (mid-pt1+1);
			pt2++;
		}
	}
	while(pt1<=mid)
	{
		auxarr[++arrpt] = arr[pt1];
		pt1++;
	}
	while(pt2<=r)
	{
		auxarr[++arrpt] = arr[pt2];	
		pt2++;
	}
	arrpt = -1;
	for(ll i=l;i<=mid;i++)
	{
		arr[i] = auxarr[++arrpt];
	}
	for(ll i=mid+1;i<=r;i++)
	{
		arr[i] = auxarr[++arrpt];
	}
	return count;
}

ll mergeUtil(ll arr[],ll n,ll l,ll r)
{
	ll count = 0;
	if(l<r)
	{
		ll mid = l + (r-l)/2;
		
		count += mergeUtil(arr,n,l,mid);
		count += mergeUtil(arr,n,mid+1,r);
		count += merge(arr,l,mid,r);
	}
	return count;
}

int main()
{
 
 	#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 	

 	ll n;
 	cin>>n;
 	ll arr[n];
 	for(ll i=0;i<n;i++)
 		cin>>arr[i];
 	ll count = mergeUtil(arr,n,0,n-1);
 	cout<<(count)<<endl;

    return 0;
}