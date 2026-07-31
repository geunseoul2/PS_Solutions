class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int size = nums.size();

        for(int i=0;i<size;i++) {
            int curr_size = ans.size();
            for(int j=0;j<curr_size;j++) {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
