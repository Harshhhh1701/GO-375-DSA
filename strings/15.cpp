//{ Driver Code Starts
//Function to find the smallest window in the string s consisting
//of all the characters of string p.
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

    bool docheck(vector<int> &ms,vector<int> &mp){
        for(int i = 0;i<26;i++){
            if(mp[i] > ms[i]) return false;
        }
        return true;
    }
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> mp(26);
        for(int i = 0;i<p.size();i++) mp[p[i]-'a']++;
        vector<int> ss(26);
        for(int i = 0;i<s.size();i++) ss[s[i]-'a']++;
        if(!docheck(ss,mp)) return "-1";
        vector<int> ms(26);
        int l = 0;
        int ans = INT_MAX;
        int ind;
        for(int i = 0;i<s.size();i++){
            if(mp[s[i]-'a'] != 0) ms[s[i]-'a']++;
            while(docheck(ms,mp)){
                if(i-l < ans){
                    ind = l;
                    ans = i-l;
                }
                if(mp[s[l]-'a'] != 0){
                    ms[s[l]-'a']--;
                }
                l++;
            }
        }
        string fans = "";
        for(int i = ind;i <= ind+ans;i++){
            fans += s[i];
        }
        return fans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends