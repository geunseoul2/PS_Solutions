class TrieNode {
public:
    unordered_map<char,TrieNode*> child;
    bool eof = false;
};


class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto c : word) {
            if(curr->child.find(c) == curr->child.end()) curr->child[c] = new TrieNode();
            curr = curr->child[c];
        }

        curr->eof = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c : word) {
            if(curr->child.find(c) == curr->child.end()) return false;
            curr = curr->child[c];
        }
        return curr->eof;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c : prefix) {
            if(curr->child.find(c) == curr->child.end()) return false;
            curr = curr->child[c];
        }
        return true;
    }
};
