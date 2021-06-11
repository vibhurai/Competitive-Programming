#include <bits/stdc++.h>
using namespace std;

void findnos(set<int>s, int n)
{
    auto x= --s.end();
    map<int,int> val;
    val.clear();
    double range = *(--s.end())+(*(--x));
    range = sqrt(range);
    range = int(range);
    int count=0,sq,cb;

    //iterating the range from the smallest natural number
    for(int i=1;i<=range;i++)
    {
        sq = i*i;
        cb= i*i*i;

        //finding the pair if it exists for either a perfect square or a perfect cube
        for(auto j=s.begin(); j!=s.end(); j++)
        {
            
            //as a set is in  ascending order, all numbers after this point would not be useful thus the iterations simply waste time
            if(sq-(*j)>0)
            {
                
                //if the number is present and not equal to itself (for a perect square)
                if(s.find(sq-(*j)) != s.end() && s.find(sq-(*j)) !=j )
                {
                    
                    // if a (value, key) mapping exists
                    if(val.find(sq-(*j)) != val.end()) 
                    {   
                        if(val[sq-(*j)]!=(*j))
                        {                          
                            val[*j]=sq-(*j);
                            count++;
                        }
                    }  

                    // creating an entry in the map
                    else 
                    {
                        val[*j]=sq-(*j);
                        count++; 
                    }    
                } 

                //if the number is present and not equal to itself (for a perect cube) and the following conditions are same as explained for squared numbers
                if(s.find(cb-(*j)) != s.end() && s.find(sq-(*j)) !=j)
                {
                    // cout<<"incube";
                    if(val.find(cb-(*j)) != val.end())
                    {
                        if(val[cb-(*j)]!=(*j))
                        {                          
                            val[*j]=cb-(*j);
                            count++;
                        }
                    }    
                    else
                    {
                        val[*j]=cb-(*j);
                        count++; 
                    }       
                }
            }      
            else 
                break;
        }        
    }  
    
    // cout<<endl;  
    cout<<count<<endl;
}

int main()
{
    int x,N,fl;
    set<int> S;
    cin>>x;
    while(x--)
    {
       cin>>N;
       S.clear();
       while(N--)
       {
            cin>>fl;
            S.insert(fl);
       }
        findnos(S,N);
    }
    return 0;
}
