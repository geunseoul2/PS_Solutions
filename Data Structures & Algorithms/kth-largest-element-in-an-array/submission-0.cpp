class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,std::greater<int>> minheap;

        for(auto x : nums) {
            minheap.push(x);

            if(minheap.size() > k) minheap.pop();
        }

        return minheap.top();
    }
};
