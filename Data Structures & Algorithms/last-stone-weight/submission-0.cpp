class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;

        for(auto x : stones) heap.push(x);

        while(heap.size() > 1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();

            if(x == y) continue;
            
            heap.push(x-y);
        }

        if(heap.size() > 0) return heap.top();
        return 0;
    }
};
