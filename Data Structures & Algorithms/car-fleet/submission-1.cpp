class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pos_srt;
        vector<int> time;
        stack<int> nge;

        for(int i=0;i<position.size();i++) pos_srt.push_back({position[i],speed[i]});
        sort(pos_srt.begin(),pos_srt.end());
        //for(int i=0;i<position.size();i++) cout << pos_srt[i].first << " " << pos_srt[i].second << endl;

        //calculate the time to reach the target
        for(auto p : pos_srt) {
            time.push_back(ceil((target-p.first)/(double)p.second));
            cout << (target-p.first)/p.second << " ";
        }

        for(int i=time.size()-1;i>=0;i--) {
            while(!nge.empty() && time[nge.top()] < time[i]) nge.pop(); //find the next greater or same element?
            if(!nge.empty()) time.erase(time.begin() + i); //if found, erase the current index?
            nge.push(i);
        }

        return time.size();
    }
};
