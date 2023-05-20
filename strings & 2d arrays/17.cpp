//{ Driver Code Starts
//Initial template for C++ 
//  Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector<int>ans(s.length(),0);
        int j=0,i=1;
        while(i<s.length()) {
            if(s[i]==s[j]) {
                ans[i] = j+1;
                j++;
                i++;
            }
            else {
                if(j==0) {
                    
                    i++;
                }
                else {
                    j = ans[j-1];
                }
            }
        }
        return ans[s.length()-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends