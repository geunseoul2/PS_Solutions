class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> hmap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hmap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        vector<int> ts;
        if(hmap.find(key) == hmap.end()) return ""; //if key not exist return nothing
        cout << key << timestamp << endl;
        for(auto& pair : hmap[key]) ts.push_back(pair.first);

        sort(ts.begin(),ts.end());
        if(ts.size() == 0) return "";

        if(ts.size() == 1) {
            if(ts[0] <= timestamp) return hmap[key][ts[0]];
            else return "";
        }

        for(int i=0;i<ts.size()-1;i++) {
            if(ts[i] <= timestamp && ts[i+1] > timestamp) return hmap[key][ts[i]];
        }

        if(ts[ts.size()-1] <= timestamp) return hmap[key][ts[ts.size()-1]];
        else return "";
    }
};
