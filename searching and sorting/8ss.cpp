//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//Count triplets with sum smaller than X
// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
        long long count=0;
        for(int i=0; i<n-2; ++i) {
            int rem=sum-arr[i],l=i+1,h=n-1;
            
            while(l<h) {
                if(arr[l]+arr[h]<rem) {
                    count+=h-l;
                    l++;
                }
               else {
                   h--;
               }
            }
        }
        return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends