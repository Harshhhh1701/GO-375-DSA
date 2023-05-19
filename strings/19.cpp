//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Given two strings A and B. Find the minimum number of steps required to transform string A into string B.
//  The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A
// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if (A.length() != B.length()) {
            return -1;
        }
     
        // create a map to store the frequency of characters in string A
        unordered_map<char, int> m;
        int n = A.length();
        for (int i = 0; i < n; i++) {
            if (m.count(A[i])) // if the character already exists in the map
                m[A[i]]++;     // increment its frequency
            else
                m[A[i]] = 1;    // add the character to the map with a frequency of 1
        }
     
        // subtract the frequency of characters in string B from the map
        for (int i = 0; i < n; i++) {
            if (m.count(B[i]))
                m[B[i]]--;
        }
     
        // check if all the frequencies in the map are 0, indicating equal frequency of characters in both strings
        for (auto it : m) {
            if (it.second != 0) // if frequency is not zero
                return -1;      // strings cannot be transformed into each other, return -1
        }
     
        // calculate the minimum number of operations required to transform string A into string B
        int i = n - 1, j = n - 1;
        int res = 0;
        while (i >= 0 && j >= 0) {
            while (i >= 0 && A[i] != B[j]) {
                res++;   // increment the number of operations required
                i--;     // move the pointer i to the left
            }
            i--;
            j--;
        }
       return res; // returning result
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends