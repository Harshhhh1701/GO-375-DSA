//5. Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), i;
        if(n<2)
            return s;
            
        int leftMost=0, rightMost=0;
        i = 0;
        int start, end;
        while(i<n)
        {
            start = i;
            end = i;
            i++;
            while(i<n && s[i]==s[start])
            {
                i++;
            }
            end = i-1;
            
            while(start-1>=0 && end+1<n && s[start-1]==s[end+1])
            {
                start--;
                end++;
            }
            
            if(rightMost-leftMost <= end-start)
            {
                leftMost = start;
                rightMost = end;
            }
        }
        
        return s.substr(leftMost, rightMost-leftMost+1);
    }
};