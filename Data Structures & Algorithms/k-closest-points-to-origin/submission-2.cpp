class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> heap;

        for(auto x : points) {
            int distance = x[0] * x[0] + x[1] * x[1];
            
            heap.push({distance,{x[0],x[1]}});
            if(heap.size() > k) heap.pop();
        }

        vector<vector<int>> ans;
        while(!heap.empty()) {
            ans.push_back({heap.top().second.first,heap.top().second.second});
            heap.pop();
        }

        return ans;
    }
};
