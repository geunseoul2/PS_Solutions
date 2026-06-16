class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hmap;

        for(auto i : nums) {
            hmap[i]++;
        }

        vector<int> ans;

        for(int i=0;i<k;i++) {
            int max = 0;
            int max_idx = 0;
            for(auto pair: hmap) {
                if(pair.second > max) {
                    max = pair.second;
                    max_idx = pair.first;
                }
            }

            ans.push_back(max_idx);
            hmap.erase(max_idx);
        }

        return ans;
    }
};
