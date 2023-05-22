//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    unordered_map<int, int> mpp;
    int count=0;
    for (int i = 0; i < size; i++) {
        mpp[arr[i]]++;
 
        // Check if any element whose frequency
        // is greater than 1 exist or not for n == 0
        if (n == 0 && mpp[arr[i]] > 1)
            return true;
    }
 
    // Check if difference is zero and
    // we are unable to find any duplicate or
    // element whose frequency is greater than 1
    // then no such pair found.
    if (n == 0)
        return false;
 
    for (int i = 0; i < size; i++) {
        if (mpp.find(n + arr[i]) != mpp.end()) {
            count++;
        }
    }

    return count;
    
}