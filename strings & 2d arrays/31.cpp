//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int maxHist(vector<int>&arr){
        stack<int>s;
        int maxA =0;
        int n = arr.size();
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || arr[s.top()]>= arr[i])){
                int height = arr[s.top()];
                s.pop();
                int width;
                if(s.empty()) width =i;
                else width = i- s.top() -1;
                maxA = max(maxA, width*height);
            }
            s.push(i);
        }
        return maxA;
    }
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Your code here
         int maxArea = 0;
                vector<int> height(m, 0);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (mat[i][j] == 1) height[j]++;
                        else height[j] = 0;
                    }
                    int area = maxHist(height);
                    maxArea = max(maxArea, area);
                }
                return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends