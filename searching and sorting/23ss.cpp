//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossibleSolution(int a[],int n,int m,int sol){
        int pageSum=0;
        int count=1;
        for(int i=0;i<n;i++){
            if(a[i]>sol){
                return false;
            }
            if(pageSum+a[i]>sol){
                count++;
                pageSum=a[i];
                if(count>m){
                return false;
                }
            }
            else{
                pageSum=pageSum+a[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N){
            return -1;
        }
        int start=0;
        int end=accumulate(A,A+N,0);
        int ans=-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(isPossibleSolution(A,N,M,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
