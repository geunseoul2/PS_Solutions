class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;

        for(auto& s : strs) {
            string sorted  = s;
            sort(sorted.begin(),sorted.end());
            hashmap[sorted].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& pair: hashmap) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
