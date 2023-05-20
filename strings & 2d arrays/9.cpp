//424. Longest Repeating Character Replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int maxsize = 0, winsize, left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            hash[s[right]]++;


            while (right - left  + 1 
            - max_element(hash.begin(), hash.end(), [](const auto& a, const auto& b){
                return a.second < b.second;
            })->second > k
            ){
                hash[s[left]]--;
                left++;
            }

            maxsize = max(maxsize, right - left  + 1);
        }

        return maxsize;
    }
};