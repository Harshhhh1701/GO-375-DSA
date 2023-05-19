//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
//prefer 2 nd solution

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int N = str.length();
 
    // create a 2D array to store the count of palindromic
    // subsequence
    long cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));
 
    // palindromic subsequence of length 1
    for (int i = 0; i < N; i++)
        cps[i][i] = 1;
 
    // check subsequence of length L is palindrome or not
    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N-L; i++) {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k]
                    = cps[i][k - 1] + cps[i + 1][k] + 1;
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
                            - cps[i + 1][k - 1];
        }
    }
 
    // return total palindromic subsequence
    return cps[0][N - 1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends












//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
   #define MOD 1000000007

   long long int dp[1005][1005];
   string S;
   long long int countPS(string str)
   {
      const int n = str.length();
      
      memset(dp, -1, sizeof(dp));
      
      S = str;
      
      long long int ans = solve(0, n-1);
      return ans<0?ans+MOD:ans;
   }
   
   private:
   long long int solve(int i, int j){
       if(i > j) return 0;
       
       if(dp[i][j] != -1) return dp[i][j]%MOD;
       
       if(i == j) return dp[i][j] = 1;
       
       if(S[i] == S[j]){
           return dp[i][j] = (solve(i+1, j)%MOD + solve(i, j-1)%MOD + 1)%MOD;
       }
       else{
           return dp[i][j] = (solve(i+1, j)%MOD + solve(i, j-1)%MOD - solve(i+1, j-1)%MOD)%MOD;
       }
   }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends