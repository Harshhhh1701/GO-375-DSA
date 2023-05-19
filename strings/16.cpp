//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string.
//  Determine if the two strings match. 
// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(string  &str,string &pattern,int i,int j)
    {
        //base cases
        if(i<0 && j<0)
        {
            //both wild and patern reached end so valid
            return true;
        }
        
        //then some part of pattern is still remaning
        if(i<0 && j>=0)
        {
            //check if that part is only * if anything other than * comes then its invalid
            for(int k=0;k<=j;k++)
            {
                if(pattern[k]!='*')
                {
                    return false;
                }
            }
            
            return true;
        }
        
        //if string is remaning but pattern exhausted
        if(j<0 && i>=0)
        {
            return false;
        }
        
        
        
        //match
        if(str[i]==pattern[j] ||pattern[j]=='?' )
        {
            return solve(str,pattern,i-1,j-1);
        }
        
        else if(pattern[j]=='*')
        {
            return (solve(str,pattern,i-1,j) || solve(str,pattern,i,j-1));
        }
        //no match
        else
        {
            return false;
        }
    }
    bool match(string wild, string pattern)
    {
        // code here
        int wild_size=wild.size();
        int patt_size=pattern.size();
        return solve(pattern,wild,patt_size-1,wild_size-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends