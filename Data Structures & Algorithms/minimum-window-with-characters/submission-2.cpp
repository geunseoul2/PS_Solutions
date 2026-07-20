class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, check = t.length();
        pair ans = {0,s.length()};
        unordered_map<char,int> hmap;

        for(auto c:t) hmap[c]++;

        while(r < s.length()) {
            if(hmap.find(s[r]) == hmap.end()) r++;
            else {
                if(hmap[s[r]] > 0) check--;
                hmap[s[r]]--;
                while(check==0) {
                    if(hmap.find(s[l]) != hmap.end()) {
                        hmap[s[l]]++;
                        if(hmap[s[l]] > 0) check++;
                    }
                    if(r-l+1 < ans.second-ans.first+1) ans = {l,r};
                    l++;
                }
                r++;
            }
        }
        if(ans.second-ans.first+1 > s.length()) return "";
        return s.substr(ans.first,ans.second-ans.first+1);
    }
};