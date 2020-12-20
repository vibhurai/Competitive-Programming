// #include <bits/stdc++.h>
// using namespace std;

// long long int find_min(long long int dist, map<long long int,long long int,greater<long long int>> dish,  map<long long int,pair<long long int,long long int>,greater<long long int>> clans)
// {
//     long long int cost=1;
//     if(clans.size()==0)
//     {
//         for(auto x = dish.begin();x!=dish.end();x++)
//             cost+=x->second;
//         return cost;      
//     }   
//     map<long long int, char, greater<long long int>> scen;
//     scen.clear(); 
//     auto cl = clans.begin();
//     auto di = dish.begin();
//     while(cl->first > di->first)
//         cl++;   
//     while(cl != clans.end() && di!= dish.end())
//     {
//         // cout<<"in";
//         if(cl->first > di->first)
//         {
//             scen[cl->first]='c';
//             cl++;
//         }
//         else
//         {
//             scen[di->first]='d';
//             di++;
//         }        
//     }
//     if(cl==clans.end())
//         while(di!=dish.end())
//         {
//             scen[di->first]='d';
//             di++;
//         }
//     else
//         while(cl!=clans.end())
//         {
//             scen[cl->first]='c';
//             cl++;
//         }
//     auto p = scen.begin();
//     // while(p!=scen.end())
//     // {    cout<<p->first<<" - "<<p->second;p++;}
//     // cout<<endl;    
//     while(p!=scen.end())
//     {
//         if(p->second=='d')
//         {
//             auto x = dish.find(p->first);
//             cost+=x->second;
//         }
//         else
//         {
//             auto x = clans.find(p->first);
//             // if(Q[j]+R[j]>=mn) mn=Q[j];
//             if(cost - (x->second).second >=(x->second).first)
//                 cost-= (x->second).second;
//             else
//                 cost=(x->second).first;
//         }
//         p++;
//     }

//     return cost;
// }

// int main()
// {
//     long long int x,dist,dd,cll,dd1,dd2,cll1,cll2,cll3;
//     cin>>x;
//     map<long long int,long long int,greater<long long int>> d;
//     pair<long long int,long long int> p;
//     map<long long int,pair<long long int,long long int>,greater<long long int>> c;
//     while(x--)
//     {
//         d.clear();
//         c.clear();
//         cin>>dist;
//         cin>>dd;
//         while(dd--)
//         {
//             cin>>dd1>>dd2;
//             d[dd1]=dd2;
//         }
//         cin>>cll;
//         while(cll--)
//         {
//             cin>>cll1>>cll2>>cll3;
//             p.first = cll2;
//             p.second = cll3;
//             c[cll1] = p;
//         }
//         cout<<find_min(dist,d,c)<<endl;
//     }    
//     return 0;
// }


#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long ll;

int main(){
	fastIO;
	int T;cin>>T;
	while(T--){
		int X;cin>>X;
		int B;cin>>B;
		ll D[B],Y[B];
		for(int i=0;i<B;i++){
			cin>>D[i]>>Y[i];
		}
		int C;cin>>C;
		ll P[C],Q[C],R[C];
		for(int i=0;i<C;i++) cin>>P[i]>>Q[i]>>R[i];
		
		int i=B-1,j=C-1;
		ll mn=1;
		while(D[i]<P[j]) j--;
		while(i>=0){
			mn+=Y[i];
			i--;
			while(j>=0&&D[i]<P[j]){
				if(Q[j]<mn){
					if(Q[j]+R[j]>=mn) mn=Q[j];
					else mn-=R[j];
				}
				j--;
			}
		}
		while(j>=0){
			if(Q[j]<mn){
				if(Q[j]+R[j]>=mn) mn=Q[j];
				else mn-=R[j];
			}
			j--;
		}
		cout<<mn<<"\n";
	}
	return 0;
}