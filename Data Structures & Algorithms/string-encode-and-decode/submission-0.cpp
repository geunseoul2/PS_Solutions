class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";

        for(auto s : strs) {
            string size;
            if(s.size() < 10) encode.append("00" + to_string(s.size()));
            else if(s.size() < 100) encode.append("0" + to_string(s.size()));
            else encode.append(to_string(s.size()));
            encode.append(s);
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decode;
        int idx = 0;
        while(idx < s.size()) {
            cout << s.substr(idx+3,idx+stoi(s.substr(idx,idx+3))) << endl;
            decode.push_back(s.substr(idx+3,idx+stoi(s.substr(idx,idx+3))));
            idx += stoi(s.substr(idx,idx+3)) + 3;
        }

        return decode;
    }
};
