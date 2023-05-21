//{ Driver Code Starts
//common elements from 3 arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            vector<int>v;
            int i=0,j=0,k=0;
            while(i!=n1 && j!=n2 && k!=n3)
            {
                if(a[i]==b[j] && a[i]==c[k])
                {
                    
                    if(v.size()==0 || v[v.size()-1]!=a[i])v.push_back(a[i]);
                    i++;
                    j++;
                    k++;
                }
                int mn=max(a[i],b[j]);
                mn=max(mn,c[k]);
                while(i!=n1 && mn>a[i])
                    i++;
                
                while(j!=n2 && mn>b[j])
                    j++;
                
                while(k!=n3 && mn>c[k])
                    k++;
                    
            }
            return v;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends