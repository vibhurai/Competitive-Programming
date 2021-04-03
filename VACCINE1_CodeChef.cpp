#include <bits/stdc++.h>
using namespace std;

static int partition_for_median(int arr[], int low, int high) 
{ 
        // pivot is choosen randomly 
      long long random = low + rand( )%(high-low +1 ) ;
        int pivot = arr[high]; 
     
 
        int i = (low-1); // index of smaller element 
        for (int j = low; j < high; j++) 
        { 
            // If current element is smaller than or 
            // equal to pivot 
            if (arr[j] < pivot) 
            { 
                i++; 
 
                // swap arr[i] and arr[j] 
                int temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp; 
            } 
        } 
 
        // swap arr[i+1] and arr[high] (or pivot) 
        int temp = arr[i+1]; 
        arr[i+1] = arr[high]; 
        arr[high] = temp; 
 
        return i+1; 
}


void sort(int arr[], int low, int high, int pivot_choice) 
    { 
 
        if (low < high) 
        { 
        	int pi = 0;
            if(pivot_choice==3) {
            	pi = partition_for_median(arr, low, high); 
                
                int n = (high-low+1);
                while(!(pi-low >= n/4 && high-pi >= n/4))
                	pi = partition_for_median(arr, low, high);
                	
                sort(arr, low, pi-low-1, pivot_choice); 
                sort(arr, pi+1, high, pivot_choice); 
            }
        } 
    }
    

int main()
{
    int d1,v1,d2,v2,p,final=0,produced=0,small,big,small_v,big_v;
    cin>>d1>>v1>>d2>>v2>>p;
    
    //adding non-production days
    if(d1<d2)
    {
        final+=d1-1;
        small=d1;
        small_v=v1;
        big= d2;
        big_v=v2;
    }    
    else    
    {    
        final+=d2-1;
        small=d2;
        small_v=v2;
        big= d1;
        big_v=v1;
    }
   

    if(small_v*(big-small) >=p)
    {
        if(small_v*(big-small) ==p)
            final=big-1;
        else
            final+=p/small_v;
    }
    
    else
    {
        int left = p-small_v*(big-small); //calculating left over medicines to be produced
        final=(big-1)+left/(v1+v2);
        if(left%(v1+v2)!=0)
            final++;
    }      

    cout<<final<<endl;
    
    return 0;
}