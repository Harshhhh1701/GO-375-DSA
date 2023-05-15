//Longest common prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n=arr.size();
        if (n == 0) 
        return ""; 
        
        // if only one string is present in the array
        // it itself is the prefix
        if (n == 1) 
            return arr[0]; 
  
        // Sort the array of strings 
        sort(arr.begin(),arr.end()); 
    
        // first string of the array has minimum length
        int min = arr[0].length();
    
        // common prefix of the whole array
        // is common prefix of first and last strings
        string first = arr[0], last = arr[n - 1]; 
    
        // recur until strings have common characters
        int i = 0; 
        while (i < min && first[i] == last[i]) 
            i++; 
  
        string prefix = first.substr(0, i); 
        return prefix;
    }
};