//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int r,int c,vector<vector<char>>&v,vector<vector<int>>&vis){
         int n=v.size();
         int m=v[0].size();
         if(r<0 or c<0) return;
         if(r>=n or c>=m) return ;
         if(vis[r][c] or v[r][c]=='0') return;
         vis[r][c]=1;
         
        for(int i=-1;i<2;++i){
            for(int j=-1;j<2;++j)
             dfs(r+i,c+j,v,vis);
        }
       
    }
    int numIslands(vector<vector<char>>& v) {
        // Code here
        int n=v.size();
         int m=v[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         int cnt=0;
         
         for(int i=0;i<n;++i){
             for(int j=0;j<m;++j){
                 if(v[i][j]=='1' and !vis[i][j]){
                     cnt++;
                     dfs(i,j,v,vis);
                 }
             }
         }
         return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends