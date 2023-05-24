//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        long long product=1, zero=0, j;
        
        for(int i=0; i<n; ++i) {
            if(nums[i]!=0) {
                product*=nums[i];
            }
            else {zero++, j=i;}
        }
        vector<long long> ans(n,0);
        if(zero>1) {
            return ans;
        }
        if(zero==1) {
            ans[j]=product;
            return ans;
        }
        for(int i=0; i<n; ++i) {
            ans[i]=product/nums[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends




// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         int fromBegin=1;
//         int fromLast=1;
//         vector<int> res(n,1);
        
//         for(int i=0;i<n;i++){
//             res[i]*=fromBegin;
//             fromBegin*=nums[i];
//             res[n-1-i]*=fromLast;
//             fromLast*=nums[n-1-i];
//         }
//         return res;
//     }
// };