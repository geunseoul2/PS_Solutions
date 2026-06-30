class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0;
        unordered_map<char,int> hmap;

        for(int i=0;i<s.size();i++) {
            if(hmap.find(s[i]) != hmap.end()) { //Has Duplicate
                left = max(hmap[s[i]] + 1,left); //The Duplicate character can come before the left pointer, so use max.
            }
            hmap[s[i]] = i;
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
