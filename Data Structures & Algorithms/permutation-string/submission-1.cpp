class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1_map;
        int l = 0;
        int check=0;

        for(auto c : s1) s1_map[c]++;

        for(int i=0;i<s2.length();i++) {
            if(s1.length() < i-l+1) {
                if(s1_map.find(s2[l]) != s1_map.end()) {
                    cout << s2[l] << endl;
                    s1_map[s2[l]]++;
                    if(s1_map[s2[l]] > 0) check--;
                }
                l++;
            }

            if(s1_map.find(s2[i]) != s1_map.end()) {
                s1_map[s2[i]]--;
                if(s1_map[s2[i]] >= 0) check++;
                cout << check << endl;
            }
            if(check == s1.length()) return true;

            
        }

        return false;
    }
};
