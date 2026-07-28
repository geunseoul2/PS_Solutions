class KthLargest {
public:
    priority_queue<int,vector<int>,std::greater<int>> minheap;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x : nums) {
            minheap.push(x);
            if(minheap.size() > k) minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > k) minheap.pop();

        return minheap.top();
    }
};
