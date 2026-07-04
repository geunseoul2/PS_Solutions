class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hmap;

        for(auto x: nums) {
            if(hmap[x] == 1) return x;

            hmap[x]++;
        }

        return 0;
    }
};
