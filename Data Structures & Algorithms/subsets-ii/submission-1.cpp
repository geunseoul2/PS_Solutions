class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;

        sort(nums.begin(),nums.end());
        ans.push_back({});
        int size = nums.size();
        int ans_size = 0;
        int start = 0;

        for(int i=0; i<size; i++) {
            start = (i>0 && nums[i] == nums[i-1]) ? ans_size : 0;
            ans_size = ans.size();
            for(int j=start; j<ans_size; j++) {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
