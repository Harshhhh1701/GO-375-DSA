//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& a, vector<int>& b)
    {
        // Your code goes here
        int n = a.size();
        int m = b.size();

        if(n>m)
            return MedianOfArrays(b, a);

        int total = (m+n+1)/2;
        int start = 0;
        int end = n;

        while(start <= end) {
            int mid = (end+start)/2;

            int partA = mid;
            int partB = total - partA;

            int leftA = (partA > 0) ? a[partA-1] : INT_MIN;
            int leftB = (partB > 0) ? b[partB-1] : INT_MIN;

            int rightA = (partA < n) ? a[partA] : INT_MAX;
            int rightB = (partB < m) ? b[partB] : INT_MAX;

            if(leftA <= rightB && leftB <= rightA) {
                if((m+n) % 2 == 0) {
                    return (max(leftA, leftB) + min(rightA, rightB))/2.0;
                } else
                    return (max(leftA, leftB));
            }

            if(leftA > rightB)
                end = mid-1;
            else
                start = mid+1;
        }

        return 0.0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends