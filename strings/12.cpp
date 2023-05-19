class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
    int n = s.size();

    // Create a 2D boolean array to store palindrome information
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
        count++;
    }

    // Check for palindromic substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true;
            count++;
        }
    }

    // Check for palindromic substrings of length > 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true;
                count++;
            }
        }
    }

    return count;
    }
};