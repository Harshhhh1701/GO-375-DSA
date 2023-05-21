//Given two arrays of equal size N and an integer K. The task is to check if after permuting both arrays, we get sum of their corresponding
// element greater than or equal to k i.e Ai + Bi >= K for all i (from 0 to N-1). Return true if possible, else false.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort( a, a + n );
        sort( b, b + n, greater<>() );
        while ( n-- ){
            if ( a[ n ] + b[ n ] < k ){
               return false; 
            } 
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        Solution ob;
        cout << ob.isPossible(a, b, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends