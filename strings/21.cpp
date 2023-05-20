//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int solve(int i,vector<int>&nums,int rs,int &k,vector<vector<int>>&dp)
    {
        if(i==nums.size())
        return 0;
        if(dp[i][rs]!=-1)
        return dp[i][rs];
        int ans;

        if(nums[i]>rs)
        {
            return dp[i][rs]=(rs+1)*(rs+1)+solve(i+1,nums,k-nums[i]-1,k,dp);
        }

        else{

            

            int a;

            if(nums[i]==rs)

            {

                a=solve(i+1,nums,k,k,dp);

            }

            else{

                a=solve(i+1,nums,rs-nums[i]-1,k,dp);

            }

            int b=(rs+1)*(rs+1)+solve(i+1,nums,k-nums[i]-1,k,dp);

            dp[i][rs]=min(a,b);

        }

        

    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n=nums.size()+1;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(0,nums,k,k,dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends