//string palindrome
class Solution {
public:
    bool alpha(char c){
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    bool alphanumeric(char c){
        return (alpha(c) || (c >= '0' && c <= '9'));
    }
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        int i = 0, j = s.length() - 1;
        while(i < j){
            while(i < j && !alphanumeric(s[i]))
                i ++;
            while(j > i && !alphanumeric(s[j]))
                j --;
            if(s[i] == s[j] || (alpha(s[i]) && alpha(s[j]) && abs(s[i] - s[j]) == 32)){
                i ++;
                j --;
            }
            else
                return false;
        }
        return true;
    }
};