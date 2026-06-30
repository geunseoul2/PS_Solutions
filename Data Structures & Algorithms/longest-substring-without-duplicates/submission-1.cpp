class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sublen = 0;
        int ans = 0;
        unordered_map<char,int> hmap;

        for(int i=0;i<s.size();i++) {
            if(hmap.find(s[i]) != hmap.end()) { //Has Duplicate
                cout << s[i] << endl;
                ans = max(ans,sublen);
                sublen = sublen - hmap[s[i]];
            } else {
                hmap[s[i]] = i;
                sublen++;
            }
        }

        return max(ans,sublen);
    }
};
