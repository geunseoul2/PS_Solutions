class Task {
public:
    char name;
    int num; //number of this task
    int cool;

    Task(char na, int n, int c) : name(na),num(n), cool(c) {}

    bool operator<(const Task t) const {
        return num < t.num;
    }
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(auto c : tasks) m[c]++;

        priority_queue<Task> heap;
        for(auto pair : m) heap.push(Task(pair.first,pair.second,n));
        
        queue<pair<Task,int>> waitq; //for storing the waiting Tasks

        int cycle = 0;
        while(!heap.empty() || !waitq.empty()) {
            cycle++;

            //resotre the tasks that finished cooling down
            while(!waitq.empty() && waitq.front().second == cycle) {
                heap.push(waitq.front().first);
                waitq.pop();
            }



            if(!heap.empty()) {
                Task curr = heap.top();
                heap.pop();

                curr.num--;
                if(curr.num > 0) { //if the task still exists
                    waitq.push({curr,n + cycle + 1});
                }   
            }

        }


        return cycle;
    }
};
