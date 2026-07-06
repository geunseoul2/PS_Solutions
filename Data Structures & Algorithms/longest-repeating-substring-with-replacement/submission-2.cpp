class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hmap;
        pair<char,int> max(0,0);
        int l=0,res=0;

        for(int i=0;i<s.length();i++) {
            hmap[s[i]]++;
            if(hmap[s[i]] > max.second) {
                max.first = s[i];
                max.second = hmap[s[i]];
            }
            int others = i - l + 1 - max.second;
            if(k < others) {
                cout << others << endl;
                hmap[s[l]]--;
                if(max.first == s[l]) max.second--;
                l++;
            } else res = std::max(res,i-l+1);
        }

        return res;
    }
};
