//49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            h[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto m: h) ans.push_back(m.second);
        return ans;
    }
};