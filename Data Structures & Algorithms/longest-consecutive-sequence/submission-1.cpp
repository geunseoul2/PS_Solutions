class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //remove duplicate and sort
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());

        int ans = 1, curr = 1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == nums[i-1] + 1) curr++;
            else {
                ans = max(ans,curr);
                curr = 1;
            }
        }

        return max(curr,ans);
    }
};
