class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1_map;
        int l = 0;
        int check=0;

        for(auto c : s1) s1_map[c]++;

        for(int i=0;i<s2.length();i++) {
            if(s1.length() < i-l+1) {
                if(s1_map.find(s2[l]) != s1_map.end()) { //Window를 줄여야 할때
                    s1_map[s2[l]]++;
                    if(s1_map[s2[l]] > 0) check--; //지우려는게 유효한것인지 확인하고 맞으면 줄인다.
                }
                l++;
            }

            if(s1_map.find(s2[i]) != s1_map.end()) { //만약 i번쨰 숫자가 유효한 글자라면
                s1_map[s2[i]]--;
                if(s1_map[s2[i]] >= 0) check++; //유효한 것인지 확실히 확인하려면 -1보다 큰지 확인해야 함. 아니면 잉여 글자.
            }
            if(check == s1.length()) return true;

            
        }

        return false;
    }
};
