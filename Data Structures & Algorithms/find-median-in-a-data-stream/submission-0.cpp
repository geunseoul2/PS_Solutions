class MedianFinder {
public:
    int total_num;
    priority_queue<int,vector<int>,std::greater<int>> minheap; //minimum of the right half
    priority_queue<int> maxheap; //maximum of the left half

    MedianFinder() {
        total_num = 0;
        maxheap.push(-100000);
        minheap.push(100000);
    }
    
    void addNum(int num) {
        total_num++;

        if(num > maxheap.top()) minheap.push(num);
        else maxheap.push(num);

        if(minheap.size() > total_num/2 + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        } else if(maxheap.size() > total_num/2 + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(total_num % 2 == 1) { //if odd
            return maxheap.size() > minheap.size() ? maxheap.top() : minheap.top();
        } else {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
    }
};
